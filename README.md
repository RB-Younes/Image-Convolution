# TP 03 Convolution

This TP 03 Convolution includes several functions implemented for image processing, including convolution filters such as the mean filter and the median filter.

## Mean Filter (`meanFilter`)

The `meanFilter` function calculates a mean filter of a size specified by the user. This filter is used to reduce noise in an image by replacing each pixel with the weighted average of its neighbors.

## Convolution (`convolution`)

The `convolution` function performs convolution of a float image by a given convolution kernel. Convolution is a fundamental operation in image processing, often used to apply different types of filters to an image, such as blur or edge detection.

## Median Filter (`median`)

The `median` function calculates a median filter of a float image. This filter is effective for removing impulse noise while preserving the edges of the image.


**Note**: Pixel values outside the image domain are assumed to have a zero value for convolution and mean filter functions. For the median filter, values outside the image domain are ignored.

---

This TP 03 Convolution provides basic functionalities for image processing, providing tools for filtering, smoothing, and enhancing images using convolution techniques.
