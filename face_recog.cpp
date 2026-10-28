import cv2
import matplotlib.pyplot as plt

imagePath = r"
cascadePath = r"C:\Users\HP\OneDrive\Desktop\Rohit's python\face_detection\haarcascade_frontalface_default.xml"

# Create the Haar Cascade
face_cascade = cv2.CascadeClassifier(cascadePath)

# Read the image
image = cv2.imread(imagePath)

# Check files
if face_cascade.empty():
    print("ERROR: Haar Cascade file could not be loaded.")
    exit()

if image is None:
    print("ERROR: Image could not be loaded.")
    exit()

# Convert image to grayscale
gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

# Detect faces
faces = face_cascade.detectMultiScale(
    gray,
    scaleFactor=1.1,
    minNeighbors=10,
    minSize=(40, 40)
)

print("Found {0} faces!".format(len(faces)))

# Draw rectangles
for (x, y, w, h) in faces:
    cv2.rectangle(
        image,
        (x, y),
        (x + w, y + h),
        (0, 255, 0),
        2
    )

# Convert BGR to RGB
RGB_img = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)

plt.imshow(RGB_img)
plt.axis("off")
plt.show()

