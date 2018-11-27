#include<iostream>
#include<opencv2/opencv.hpp>
#include<string>

using namespace std;
using namespace cv;

int main(int argc, char **argv){
    const String filename = "../../data/image/lena.jpg";
    
    Mat coloredImg = imread(filename, IMREAD_COLOR);
    if(coloredImg.empty()){
        cerr << "Can't open image " << filename << endl;
        return -1;
    }
    
    Mat grayImg = imread(filename, IMREAD_GRAYSCALE);
    if(grayImg.empty()){
        cerr << "Can't open image " << filename << endl;
        return -1;
    }
    
    imshow("Colored image", coloredImg);
    imshow("Grayscale image", grayImg);
    
    // get the intensity of grayscale image 
    unsigned int y, x;
    y = 10;
    x = 100;
    Scalar intensity = grayImg.at<uchar>(y, x);
    printf("Grayscale intensity at (%u, %u)= %u\n", x, y, (unsigned int)intensity.val[0]);

    // get the intensity of colored image
    Vec3b rgbIntensity = coloredImg.at<Vec3b>(y, x);
    uchar blue = rgbIntensity.val[0];
    uchar green = rgbIntensity.val[1];
    uchar red = rgbIntensity.val[2];
    printf("BGR at (%u, %u)= (%u %u %u)\n", 
        x, y, (unsigned int)blue, (unsigned int)green, (unsigned int)red);

    //
    // copy the data with cv::Mat::copyTo or cv::Mat::clone (not necessary) and
    // compute the gradient along different axes
    //
    // Mat img1 = grayImg.clone();
    Mat img1 = coloredImg.clone();
    Mat sobelx;
    
    Sobel(img1,    // src 
          sobelx,  // dst
          CV_32F,  // ddepth: output depth
          1,       // dx
          0        // dy
          );
    
    Mat sobely;
    Sobel(img1,    // src 
          sobely,  // dst
          CV_32F,  // ddepth: output depth
          0,       // dx
          1        // dy
          );
    
    // rescale the gradient to 0~255 and draw the result
    double minVal, maxVal;
    minMaxLoc(sobelx, &minVal, &maxVal);
    Mat drawSobelx;
    sobelx.convertTo(drawSobelx, 
                     CV_8U, 
                     255.0/(maxVal - minVal),            // alpha: scale
                     -minVal * 255.0/(maxVal - minVal)); // beta: offset
    
    minMaxLoc(sobely, &minVal, &maxVal);
    Mat drawSobely;
    sobely.convertTo(drawSobely, 
                     CV_8U, 
                     255.0/(maxVal - minVal),            // alpha: scale
                     -minVal * 255.0/(maxVal - minVal)); // beta: offset

    imshow("Sobel x", drawSobelx);
    imshow("Sobel y", drawSobely);

    waitKey(0);
    destroyAllWindows();    
    return 0;
}