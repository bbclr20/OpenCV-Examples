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
    <img src="data/image/lena.jpg" width="25%">
    <img src="data/image/baboon.jpg" width="25%">
    <img src="result/blend.png" width="25%">
</p>

### 05-Contrast

Changing the contrast and brightness of an image.

<p align="center">
    <img src="data/image/lena.jpg" width="25%">
    <img src="result/overexposure.png" width="25%">
    <img src="result/gamma_correlation.png" width="25%">
</p>

### 06-Fourier transform

Applying the **low pass filter** to the image and observe the result.

<p align="center">
    <img src="result/blur_hex.png" width="35%">
    <img src="result/fourier_spectrum.png" width="35%">
</p>

### 07-File IO

Using cv::FileStorage, cv::FileNode and cv::FileNodeIterator to write/read the text entries to a file. The output file may be either **XML (xml) , YAML (yml/yaml) or xml.gz** which is depend on the file extension.

### 08-RNG

Using the **Random Number generator** class (cv::RNG) to create random textures and overlay the textures on the canvas.

<p align="center">
    <img src="result/random_circles.png" width="35%">
    <img src="result/random_text.png" width="35%">
</p>

### 09-Smmothing image

Applying diverse **linear filters** to the image using OpenCV functions (blur, GaussianBlur, medianBlur and bilateralFilter).

<p align="center">
    <img src="result/blur_baboon.png" width="25%">
    <img src="result/gaussian_baboon.png" width="25%">
</p>
<p align="center">
    <img src="result/median_baboon.png" width="25%">
    <img src="result/bilateral_baboon.png" width="25%">
</p>

## Reference

1. <https://docs.opencv.org/3.4/d9/df8/tutorial_root.html>