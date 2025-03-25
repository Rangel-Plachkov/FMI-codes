import cv2
import numpy as np

# Initialize variables
drawing = False  # Flag to track mouse press
ix, iy = -1, -1  # Initial coordinates

# Create a black image
img = np.zeros((512, 512, 3), np.uint8)

def draw_text(guess =""):
    img[0:30, :] = 0
    cv2.putText(img, f"Prediction: {guess}",
                (10, 20), cv2.FONT_HERSHEY_SIMPLEX, 0.6, (255, 255, 255), 1)

draw_text()

def interactive_drawing(event, x, y, flags, param):
    global ix, iy, drawing

    if event == cv2.EVENT_LBUTTONDOWN:  # Mouse button pressed
        drawing = True
        ix, iy = x, y
    elif event == cv2.EVENT_MOUSEMOVE and drawing:  # Draw while moving
        cv2.line(img, (ix, iy), (x, y), (255, 255, 255), 3)
        ix, iy = x, y
    elif event == cv2.EVENT_LBUTTONUP:  # Mouse button released
        drawing = False


cv2.namedWindow('Window')
cv2.setMouseCallback('Window', interactive_drawing)

while True:
    cv2.imshow('Window', img)
    key = cv2.waitKey(1) & 0xFF

    if key == 27:  # 'Esc' key to exit
        break
    elif key == ord('c'):
        img[:] = 0
        draw_text()
        
cv2.destroyAllWindows()
