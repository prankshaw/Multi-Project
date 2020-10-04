import cv2
import numpy as np

cap = cv2.VideoCapture(0)
four_cc=cv2.VideoWriter_fourcc(*"XVID")
out=cv2.VideoWriter("Output.avi",four_cc,30,(640,480))
# We first capture a initial frame that will be used later to overlap the mentioned color
for i in range(60):  # We are taking few captures since, there may be chances of capturing a dull image as the first capture.
    _, img = cap.read()
    img=cv2.flip(img,1)

while cap.isOpened():

    status,frame=cap.read()
    frame=cv2.flip(frame,1)
    # Now we convert the frame to hsv in order to detect colors
    hsv=cv2.cvtColor(frame,cv2.COLOR_BGR2HSV)
    # Now we set the color of the cloak we are going to use
    lower_red1 = np.array([0, 120, 50],np.uint8)
    upper_red1 = np.array([5, 255, 255],np.uint8)
    lower_red2 = np.array([175, 120, 50],np.uint8)
    upper_red2 = np.array([180, 255, 255],np.uint8)
    # Now we create the mask which will have the color of the cloak
    mask1=cv2.inRange(hsv,lower_red1,upper_red1)
    mask2=cv2.inRange(hsv,lower_red2,upper_red2)
    mask1=cv2.morphologyEx(mask1,cv2.MORPH_OPEN,kernel=np.ones((3,3),np.uint8),iterations=1)
    mask1 = cv2.dilate(mask1, np.ones((3, 3), np.uint8), iterations=1)
    mask2 = cv2.morphologyEx(mask2, cv2.MORPH_OPEN, kernel=np.ones((3, 3), np.uint8), iterations=1)
    mask2 = cv2.dilate(mask2, np.ones((3, 3), np.uint8), iterations=1)
    # Now we combine both the masks to get the red color
    mask=mask1+mask2
    mask = cv2.dilate(mask, np.ones((3, 3), np.uint8), iterations=1)
    # Using the mask our frame will become white (1) to red color and black (0) to other colors.
    # We want everything except red color from the present frame and everything in place of the red frame from the first image
    # We want to remove red from the present frame, so we invert the mask such that it detects everything except red.
    mask_present=cv2.bitwise_not(mask)
    frame2=cv2.bitwise_and(img,img,mask=mask)
    frame1=cv2.bitwise_and(frame,frame,mask=mask_present)
    final_frame=cv2.addWeighted(frame1,1,frame2,1,gamma=0)
    out.write(final_frame)
    cv2.imshow("Video",final_frame)
    if cv2.waitKey(1) & 0xFF == 27:
        break
cv2.destroyAllWindows()
