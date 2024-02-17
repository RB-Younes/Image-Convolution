
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
    Compute the sum of absolute partial derivative according to Sobel's method
*/
cv::Mat edgeSobel(cv::Mat image)
{
    Mat res = image.clone();
    /********************************************
                YOUR CODE HERE
    *********************************************/
    
    /********************************************
                END OF YOUR CODE
    *********************************************/
    return res;
}

/**
    Value of a centered gaussian of variance (scale) sigma at point x.
*/
float gaussian(float x, float sigma2)
{
    /*1.0 / (2 * M_PI * sigma2) * exp(-x * x / (2 * sigma2))*/
    return 1.0 / (2  * sigma2) * exp(-x * x / (2 * sigma2));
}

/**
    Performs a bilateral filter with the given spatial smoothing kernel 
    and a intensity smoothing of scale sigma_r.

*/
cv::Mat bilateralFilter(cv::Mat image, cv::Mat kernel, float sigma_r)
{
    Mat res = image.clone();
    /********************************************
                YOUR CODE HERE
    *********************************************/
   
    /********************************************
                END OF YOUR CODE
    *********************************************/
    return res;
}
