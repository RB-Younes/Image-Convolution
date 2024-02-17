
#pragma once

#include <opencv2/opencv.hpp>

cv::Mat meanFilter(cv::Mat image, int size);

cv::Mat convolution(cv::Mat image, cv::Mat kernel);

cv::Mat median(cv::Mat image, int size);