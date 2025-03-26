import cv2
import numpy as np
#import tensorflow as tf

drawing = False
ix, iy = -1, -1

img = np.zeros((512, 512, 3), np.uint8)


#model = tf.keras.models.load_model("handwritten_letter_recognition.h5")  # Added model loading

def draw_text(guess=""):
    img[0:30, :] = 0
    cv2.putText(img, f"Prediction: {guess}",
                (10, 20), cv2.FONT_HERSHEY_SIMPLEX, 0.6, (255, 255, 255), 1)

draw_text()

def interactive_drawing(event, x, y, _, __):
    global ix, iy, drawing

    if event == cv2.EVENT_LBUTTONDOWN:
        drawing = True
        ix, iy = x, y
    elif event == cv2.EVENT_MOUSEMOVE and drawing:
        cv2.line(img, (ix, iy), (x, y), (255, 255, 255), 10)
        ix, iy = x, y
    elif event == cv2.EVENT_LBUTTONUP:
        drawing = False

def process_image():
    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    roi = gray[30:, :]
    resized = cv2.resize(roi, (28, 28), interpolation=cv2.INTER_AREA)
    return resized


def process_image_model():
    resized = process_image()
    normalized = resized / 255.0
    return normalized.reshape(1, 28, 28, 1)


# def predict_letter():
#     processed_img = process_image()  # Process image before prediction
#     predictions = model.predict(processed_img)
#     predicted_label = np.argmax(predictions, axis=1)[0]
#     letter = chr(predicted_label + ord('A'))  # Convert to corresponding letter
#     return letter

cv2.namedWindow('Window')
cv2.setMouseCallback('Window', interactive_drawing)

while True:
    cv2.imshow('Window', img)
    key = cv2.waitKey(1) & 0xFF

    if key == 27:
        break
    elif key == ord('c'):
        img[:] = 0
        draw_text()
    elif key == ord('s'):
        processed_img = process_image()
        cv2.imwrite("image.png", processed_img)
        print("Saved image.png")
    elif key == ord('p'):
        pass
        #predicted_letter = predict_letter()
        #print(f"Predicted Letter: {predicted_letter}")
        #draw_text(predicted_letter)

cv2.destroyAllWindows()
