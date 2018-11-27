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
    
    imshow("Colored image", coloredImg);
    
    waitKey(0);
    destroyAllWindows();    
    return 0;
}