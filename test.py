import cv2
import numpy as np

# Initialize camera capture
cap = cv2.VideoCapture(0)
#cap.set(3, 1920)
#cap.set(4, 1080)

while True:
    frame = cap.read()
    cv2.imshow('test', frame)
    if cv2.waitKey(1) & 0xFF == ord('q'):
       break

# Release the camera and close all windows
cap.release()
cv2.destroyAllWindows()

