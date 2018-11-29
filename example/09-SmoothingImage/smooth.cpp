#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

const int MAX_KERNEL_LENGTH = 31;

int main(int argc, char **argv){
    CommandLineParser parser(argc, argv,
                             "{image | ../../data/image/baboon.jpg | input image}");

    String filename = parser.get<String>("image");
    Mat src = imread(filename, IMREAD_COLOR);
    
    //
    // blur: each output pixel is the mean 
    // of its kernel neighbors
    //
    Mat blur_image;
    for(int i=1; i<MAX_KERNEL_LENGTH; i+=2) {
        blur(src,         // src
             blur_image,  // dst
             Size(i, i),  // kernel size
             Point(-1,-1) // kernel center
            );
    }
    imshow("Blur image", blur_image);

    //
    // Gaussian blur: convolving each point in 
    // the input array with a Gaussian kernel 
    //
    Mat gaussian_blur_image;
    for ( int i=1; i<MAX_KERNEL_LENGTH; i+=2){
        GaussianBlur(src,                 // src
                     gaussian_blur_image, // dst
                     Size(i, i),          // kernel size
                     0,                   // sigma X
                     0,                   // sigma Y
                     BORDER_WRAP          // border condition
                    );
    }
    imshow("Gaussian blur", gaussian_blur_image);

    //
    // median blur: replace each pixel with the
    // median of its neighboring pixels 
    //
    Mat median_blur_image;
    for (int i=1; i<MAX_KERNEL_LENGTH; i+=2){
        medianBlur(src,               // src
                   median_blur_image, // dst
                   i                  // kernel size
                   );
    }
    imshow("Mediam blur", median_blur_image);

    //
    // cv::bilateralFilter can reduce unwanted noise very well 
    // while keeping edges fairly sharp
    //
    Mat bilateral_image;
    for (int i=1; i<MAX_KERNEL_LENGTH; i+=2){
        bilateralFilter(src,             // src
                        bilateral_image, // dst
                        i,               // diameter
                        i*2,             // sigma color
                        i/2              // sigma space
                    );
    }
    imshow("Bilateral filter", bilateral_image);

    waitKey(0);
    destroyAllWindows();
    return 0;
}