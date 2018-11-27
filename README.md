# OpenCV-Examples

Some OpenCV examples.

## Environment

OS: Ubuntu 16.04

OpenCV version: 3.4.1

## Examples

### 01-Hello world

Reading an image and keeping the data with **cv::Mat** object.

<img src="data/image/lena.jpg" width="25%">

### 02-Image operation

Accessing a point in the matrix using **cv::Mat::at**.
Computing the value of the gradient with **sobel operator** along different axes.

<img src="result/sobelx.png" width="25%">

### 03-Mask

Calculating the convolutional result of each pixels value in an image according to a mask matrix.

<img src="result/sharpen.png" width="25%">

### 04-Blending

Calculating the weighted sum of two images.

<p align="center">
    <img src="data/image/lena.jpg">
    <img src="data/image/baboon.jpg">
    <img src="result/blend.png">
</p>

### 05-Contrast

Changing the contrast and brightness of an image.

<p align="center">
    <img src="data/image/lena.jpg">
    <img src="result/overexposure.png">
    <img src="result/gamma_correlation.png">
</p>
