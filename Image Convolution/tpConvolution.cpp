
#include "tpConvolution.h"
#include <cmath>
#include <algorithm>
#include <tuple>
using namespace cv;
using namespace std;
/**
    Compute a mean filter of size 2k+1.

    Pixel values outside of the image domain are supposed to have a zero value.
*/
cv::Mat meanFilter(cv::Mat image, int k){
    Mat res = image.clone();

    /********************************************
                YOUR CODE HERE
    *********************************************/
    int dim = 2 * k + 1;
    int kernelSize = dim * dim;

    for (int i = 0; i < res.rows; i++)
    {
        for (int j = 0; j < res.cols; j++)
        {
            int sum = 0;
            for (int x = i - k; x <= i+k; x++)
            {
                for (int y = j - k; y <= j+k; y++)
                {
                    if (x >= 0 && x < res.rows && y >= 0 && y < res.cols) {

                        sum += static_cast<int>(res.at<uchar>(x, y));
                    }
                }
            }

            int avg = sum / kernelSize;
            res.at<uchar>(i, j) = static_cast<uchar>(avg);
        }
    }

    /********************************************
                END OF YOUR CODE
    *********************************************/

    return res;

}

/**
    Compute the convolution of a float image by kernel.
    Result has the same size as image.
    
    Pixel values outside of the image domain are supposed to have a zero value.
*/
Mat convolution(Mat image, cv::Mat kernel)
{
    Mat res = image.clone();
    /********************************************
                YOUR CODE HERE
    *********************************************/

    image.convertTo(image, CV_32F);
    for (int i = 0; i < res.rows; i++)
    {
        for (int j = 0; j < res.cols; j++)
        {
            float val = 0;
            int xk = 0;
            int yk = 0;
            for (int x = i - kernel.rows/2 ; x <= i + kernel.rows / 2; x++)
            {
                for (int y = j - kernel.rows / 2 ; y <= j + kernel.rows / 2 ; y++)
                {
                    if (x >= 0 && x < res.rows && y >= 0 && y < res.cols) 
                    {

                        val += image.at<float>(x, y) * kernel.at<float>(xk,yk);
                    }
                    yk += 1;
                }
                xk += 1;
                yk = 0;
            }

            res.at<uchar>(i, j) = static_cast<uchar>(val);
        }
    }
    /********************************************
                END OF YOUR CODE
    *********************************************/

    return res;
}


/**
    Compute a median filter of the input float image.
    The filter window is a square of (2*size+1)*(2*size+1) pixels.

    Values outside image domain are ignored.

    The median of a list l of n>2 elements is defined as:
     - l[n/2] if n is odd
     - (l[n/2-1]+l[n/2])/2 is n is even
*/

Mat median(Mat image, int size)
{
    Mat res = image.clone();
    assert(size > 0);
    /********************************************
                YOUR CODE HERE
    *********************************************/

    int rows = image.rows;
    int cols = image.cols;


    // Pad the image
    int borderSize = size;
    cv::Mat paddedImage(rows + 2 * borderSize, cols + 2 * borderSize, CV_8U);
    cv::copyMakeBorder(image, paddedImage, borderSize, borderSize, borderSize, borderSize, cv::BORDER_REFLECT);

    // Iterate over the image pixels
    for (int i = borderSize; i < rows + borderSize; ++i) {
        for (int j = borderSize; j < cols + borderSize; ++j) {
            // Extract pixel values in the window
            std::vector<uchar> windowValues;
            for (int m = i-size; m <= i+size; m++) {
                for (int n = j-size; n <= j+size; n++) {
                    windowValues.push_back(paddedImage.at<uchar>(m,n));
                }
            }

            // Sort the window values
            std::sort(windowValues.begin(), windowValues.end());

            // Calculate the median
            int n = windowValues.size();
            float medianValue;
            if (n % 2 == 0) {
                medianValue = (windowValues[n / 2 - 1] + windowValues[n / 2]) / 2.0f;
            }
            else {
                medianValue = windowValues[n / 2];
            }

            // Assign the median to the resulting image
            res.at<uchar>(i - borderSize, j - borderSize) = medianValue;
        }
    }

    /********************************************
                END OF YOUR CODE
    *********************************************/
    return res;
}