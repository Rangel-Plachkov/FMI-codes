import cv2
import numpy as np
import torch
import torch.nn as nn

DRAW_MODE_WHITE = False

drawing = False
ix, iy = -1, -1

canvas_color = 0 if DRAW_MODE_WHITE else 255
img = np.full((512, 512, 3), canvas_color, dtype=np.uint8)

model = nn.Sequential(
    nn.Conv2d(1, 32, kernel_size=3, padding=1),
    nn.ReLU(),
    nn.MaxPool2d(2),

    nn.Conv2d(32, 64, kernel_size=3, padding=1),
    nn.ReLU(),
    nn.MaxPool2d(2),

    nn.Conv2d(64, 128, kernel_size=3, padding=1),
    nn.ReLU(),
    nn.MaxPool2d(2),

    nn.Dropout(0.25),
    nn.Flatten(),

    nn.Linear(128 * 3 * 3, 128),
    nn.ReLU(),
    nn.Linear(128, 26)
)

model.load_state_dict(torch.load('model.pth'))
model.eval()


def draw_text(guess=""):
    text_bg = 0 if DRAW_MODE_WHITE else 255
    text_color = (255, 255, 255) if DRAW_MODE_WHITE else (0, 0, 0)
    img[0:30, :] = text_bg
    cv2.putText(img, f"Prediction: {guess}",
                (10, 20), cv2.FONT_HERSHEY_SIMPLEX, 0.6, text_color, 1)


draw_text()


def interactive_drawing(event, x, y, _, __):
    global ix, iy, drawing

    draw_color = (255, 255, 255) if DRAW_MODE_WHITE else (0, 0, 0)

    if event == cv2.EVENT_LBUTTONDOWN:
        drawing = True
        ix, iy = x, y
    elif event == cv2.EVENT_MOUSEMOVE and drawing:
        cv2.line(img, (ix, iy), (x, y), draw_color, 50)
        ix, iy = x, y
    elif event == cv2.EVENT_LBUTTONUP:
        drawing = False


def process_image():
    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    roi = gray[30:, :]

    if not DRAW_MODE_WHITE:
        roi = cv2.bitwise_not(roi)

    resized = cv2.resize(roi, (28, 28), interpolation=cv2.INTER_AREA)
    return resized


def process_image_model():
    resized = process_image()
    tensor_img = torch.tensor(resized, dtype=torch.float32).unsqueeze(0).unsqueeze(0)
    tensor_img = tensor_img / 255.0
    tensor_img = (tensor_img - 0.5) / 0.5
    return tensor_img


def predict_letter():
    if drawing:
        return ""
    input_tensor = process_image_model()
    with torch.no_grad():
        predictions = model(input_tensor)
        probs = torch.softmax(predictions, dim=1)
        confidence, predicted_label = torch.max(probs, dim=1)
        letter = chr(predicted_label.item() + ord('A'))
        return f"{letter} ({round(confidence.item()*100,1)}%)"


cv2.namedWindow('Window')
cv2.setMouseCallback('Window', interactive_drawing)

while True:
    cv2.imshow('Window', img)
    key = cv2.waitKey(1) & 0xFF

    if key == 27:
        break
    elif key == ord('c'):
        img[:] = canvas_color
        draw_text()
    elif key == ord('s'):
        processed_img = process_image()
        cv2.imwrite("image.png", processed_img)
        print("Saved image.png")

    letter = predict_letter()
    draw_text(letter)

cv2.destroyAllWindows()
