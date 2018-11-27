#include<opencv2/opencv.hpp>
#include<iostream>
#include<string>

using namespace cv;
using namespace std;

int main(int argc, char **argv){
    const String file_lena = "../../data/image/lena.jpg";
    const String file_baboon = "../../data/image/baboon.jpg";
    
    Mat lena = imread(file_lena, IMREAD_COLOR);
    if(lena.empty()) { 
        cerr << "Error loading lena" << endl; return -1; 
    }

    Mat baboon = imread(file_baboon, IMREAD_COLOR);
    if(baboon.empty()) { 
        cerr << "Error loading baboon" << endl; 
        return -1; 
    }

    imshow("lena", lena);
    imshow("baboon", baboon);

    //
    // blend the images with the equation as follows
    // dst = src1*alpha + src2*beta + gamma;
    //
    const double ALPHA = 0.5; 
    const double BETA = 1-ALPHA; 

    Mat blendResult;
    addWeighted(lena,        // src1
                ALPHA,       // alpha
                baboon,      // src2
                BETA,        // beta
                0.0,         // gamma
                blendResult  // dst
                );

    imshow("Linear Blend", blendResult);

    waitKey(0);
    destroyAllWindows();
    return 0;
}