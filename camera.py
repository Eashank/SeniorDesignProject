import cv2
import numpy as np

# Initialize camera capture
cap = cv2.VideoCapture(4)
cap.set(3, 1920)
cap.set(4, 1080)

# Define parameters for circle detection
params = cv2.SimpleBlobDetector_Params()
params.filterByCircularity = True
params.minCircularity = 0.6
params.filterByArea = True
params.minArea = 1000
params.maxArea = 10000
detector = cv2.SimpleBlobDetector_create(params)

# Define fonts and colors for displaying text
font = cv2.FONT_HERSHEY_SIMPLEX
font_scale = 1
color = (0, 0, 255)
thickness = 2

while True:
    # Capture frame-by-frame
    ret, frame = cap.read()

    # Convert to grayscale
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
#    cv2.imshow("test", gray)
    # Detect circles using blob detection
    keypoints = detector.detect(frame)

    # Draw circles and display text on the frame
    for i, keypoint in enumerate(keypoints):
        # Determine the text to display based on the size of the circle
        if keypoint.size < 50:
            text = f"Object {i+1}: Filler Tube"
        elif keypoint.size < 100:
            text = f"Object {i+1}: Cathode"
        else:
            text = f"Object {i+1}: Cathode"

        # Draw a rectangle and display text below the circle
        x, y = int(keypoint.pt[0]), int(keypoint.pt[1])
        size = int(keypoint.size / 2)
        cv2.rectangle(frame, (x-size, y-size), (x+size, y+size), color, thickness)
        cv2.putText(frame, text, (x-size, y+size+30), font, font_scale, color, thickness)

    # Display the resulting frame
#    left = frame[:,:int(frame.shape[1]/2)]
    #cv2.imshow('Circle Detection', frame)
    cv2.imshow('Circle Detection', frame)
#    cv2.imshow('grau', gray)

    # Wait for 'q' key to be pressed to exit
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

# Release the camera and close all windows
cap.release()
cv2.destroyAllWindows()

