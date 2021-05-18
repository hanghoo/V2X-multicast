import cv2
img = cv2.imread("/home/hang/Downloads/CV2X multicast/lena.png")
cv2.imshow("Origin",img)
imgGray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
cv2.imshow("Gray",imgGray)

cv2.waitKey()
cv2.destroyAllWindows()