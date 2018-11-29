#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Scalar randomColor(RNG& rng){
  unsigned int icolor = (unsigned) rng;
  return Scalar(icolor&0xFF, (icolor>>8)&0xFF, (icolor>>16)&0xFF);
}

void DrawingRandomLines(
    Mat image, 
    const char *window_name,
    int lineNumber,
    RNG rng)
{
    int lineType = 8;
    Point pt1, pt2;
    
    int x_1 =  0;
    int x_2 = image.cols;
    int y_1 = 0;
    int y_2 = image.rows;

    for(int i=0; i<lineNumber; ++i){
        pt1.x = rng.uniform(x_1, x_2);
        pt1.y = rng.uniform(y_1, y_2);
        pt2.x = rng.uniform(x_1, x_2);
        pt2.y = rng.uniform(y_1, y_2);

        line(image,              // image 
             pt1,                // first point
             pt2,                // second point
             randomColor(rng),   // line color
             rng.uniform(1, 10), // thickness
             LINE_AA             // line type
            );
    }
    imshow(window_name, image);
}

void DrawingRandomCircles(
    Mat image, 
    const char *window_name,
    int circleNumber,
    RNG rng)
{
    int lineType = 8;
    Point pt1, pt2;
    
    int x_1 =  0;
    int x_2 = image.cols;
    int y_1 = 0;
    int y_2 = image.rows;

    for(int i=0; i<circleNumber; ++i){
        Point org;
        org.x = rng.uniform(x_1, x_2);
        org.y = rng.uniform(y_1, y_2);
        
        circle(image,                // image 
               org,                  // center
               rng.uniform(1, 100),  // radius
               randomColor(rng),     // line color
               rng.uniform(-3, 10),  // thickness
               LINE_AA               // line type
            );
    }
    imshow(window_name, image);
}

int DisplayingRandomText(
    Mat image, 
    const char *window_name,
    int textNumber, 
    RNG rng)
{
    int x_1 =  0;
    int x_2 = image.cols;
    int y_1 = 0;
    int y_2 = image.rows;
    
    for (int i = 1; i < textNumber; i++){
        Point org;
        org.x = rng.uniform(x_1, x_2);
        org.y = rng.uniform(y_1, y_2);
        putText(image,                        // image
                "Testing text rendering",     // text
                org,                          // bottom-left corner of the text string
                rng.uniform(0, 8),            // font type
                rng.uniform(0, 100)*0.05+0.1, // font scale
                randomColor(rng),             // color
                rng.uniform(1, 10),           // thickness
                LINE_AA                       // line type
            );
    }
    imshow(window_name, image);
}

int main(int argc, char **argv){
    const unsigned int H = 450;
    const unsigned int W = 800;
    
    Mat image = Mat::zeros(H, W, CV_8UC3);
    
    // choose the random seed
    // RNG rng(0xFFFFFFFF);
    // RNG rng(0x12345678);
    // RNG rng(0xA0A0A0A0);
    RNG rng(0x0A0A0A0A);

    // overlay the texture on the same image
    DrawingRandomLines(image, "Random Lines", 20, rng);
    DrawingRandomCircles(image, "Random Circles", 10, rng);
    DisplayingRandomText(image, "Random Text", 10, rng);
    
    waitKey(0);
    destroyAllWindows();
    return 0;
}