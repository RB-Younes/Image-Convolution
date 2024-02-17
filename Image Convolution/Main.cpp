#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include "tpConvolution.h"

using namespace cv;

int main()
{

    cv::Mat Kernel = (cv::Mat_<float>(3, 3) <<
        0.0f, -1.0f, 0.0f,
        -1.0f, -5.0f, -1.0f,
        0.0f, -1.0f, 0.0f);

    std::string image_path = samples::findFile("img1.png");
    Mat img = imread(image_path, IMREAD_GRAYSCALE);
    if (img.empty())
    {
        std::cout << "Could not read the image: " << image_path << std::endl;
        return 1;
    }
    Mat res = convolution(img, Kernel);

    imshow("Display window1", img);
    
    imshow("Display window2", res);



    int k = waitKey(0); // Wait for a keystroke in the window
    int k1 = waitKey(0); // Wait for a keystroke in the window



}