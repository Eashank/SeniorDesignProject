import cv2
import numpy as np

# Reading the image
img = cv2.imread('test.jpg')

cv2.namedWindow('image', cv2.WINDOW_NORMAL)
cv2.resizeWindow('image', 1920,1080)

# Showing the output




hsv = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)



# lower bound and upper bound for Green color
lower_bound = np.array([50, 20, 20])	 
upper_bound = np.array([100, 255, 255])

# find the colors within the boundaries
mask = cv2.inRange(hsv, lower_bound, upper_bound)

cv2.imshow("image", mask)



cv2.waitKey(0)
cv2.destroyAllWindows()

