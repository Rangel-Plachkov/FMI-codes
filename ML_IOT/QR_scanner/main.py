import cv2
from pyzbar import pyzbar
cap = cv2.VideoCapture(0)

while True:
    ret, frame = cap.read()

    if not ret:
        print("Failed to read frame")
        break

    data, bbox, _ = cv2.QRCodeDetector().detectAndDecode(frame)

    if bbox is not None:
        for point in bbox:
            cv2.polylines(frame, [point.astype(int)], True, (0, 255, 0), 2)
    if data:
        print(f"QR Code detected: {data}")

    cv2.imshow("QR Scanner", frame)

    if cv2.waitKey(1) & 0xFF == 27:
        break

cap.release()
cv2.destroyAllWindows()
