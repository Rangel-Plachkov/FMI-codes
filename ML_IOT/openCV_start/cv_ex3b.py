import cv2

if __name__ == "__main__":
    cap = cv2.VideoCapture(0)
    if cap.isOpened():
        print("Webcam opened")
        while cv2.waitKey(20) != ord('q'):
            return_value, frame = cap.read()
            if return_value == False:
                print("Video closed / error")
                break
            cv2.imshow('Test.MP4', frame)
    cap.release()
    cv2.destroyAllWindows()

