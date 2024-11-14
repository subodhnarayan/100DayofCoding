import matplotlib.pyplot as plt
from skimage import io, color
from skimage.segmentation import slic
from skimage.segmentation import mark_boundaries
from skimage.util import img_as_float

# Load the image
image = img_as_float(io.imread('https://homepages.cae.wisc.edu/~ece533/images/airplane.png'))  # Example image URL

# Perform SLIC segmentation
segments = slic(image, n_segments=250, compactness=10, sigma=1)

# Display the results
fig, ax = plt.subplots(1, 2, figsize=(12, 6), sharex=True, sharey=True)
ax[0].imshow(image)
ax[0].set_title('Original Image')
ax[1].imshow(mark_boundaries(image, segments))
ax[1].set_title('SLIC Segmentation')
for a in ax:
    a.axis('off')
plt.tight_layout()
plt.show()
