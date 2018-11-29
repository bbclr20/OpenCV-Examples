#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int erosion_elem = 0;
int erosion_size = 0;
int dilation_elem = 0;
int dilation_size = 0;
const int max_elem = 2;
const int max_kernel_size = 21;

Mat src, erosion_dst, dilation_dst;

void Erosion(int, void*){
    int erosion_type = 0;
    
    if(erosion_elem == 0){ 
        erosion_type = MORPH_RECT;
    }else if(erosion_elem == 1 ){ 
        erosion_type = MORPH_CROSS; 
    }else if(erosion_elem == 2){ 
        erosion_type = MORPH_ELLIPSE;
    }
    
    Mat element;
    element = getStructuringElement(
                erosion_type,
                Size(2*erosion_size + 1, 2*erosion_size+1),
                Point(erosion_size, erosion_size)
            );

    erode(src, erosion_dst, element);
    imshow("Erosion Demo", erosion_dst);
}

void Dilation(int, void*){
    int dilation_type = 0;

    if(dilation_elem == 0){ 
        dilation_type = MORPH_RECT; 
    }else if(dilation_elem == 1){ 
        dilation_type = MORPH_CROSS; 
    }else if(dilation_elem == 2) { 
        dilation_type = MORPH_ELLIPSE; 
    }

    Mat element;
    element = getStructuringElement( 
        dilation_type,
        Size(2*dilation_size+1, 2*dilation_size+1),
        Point(dilation_size, dilation_size)
        );

    dilate(src, dilation_dst, element);
    imshow("Dilation Demo", dilation_dst);
}

int main(int argc, char **argv){
    CommandLineParser parser(argc, argv,
                             "{image | ../../data/image/morphology_j.png | input image}");

    String filename = parser.get<String>("image");
    src = imread(filename, IMREAD_COLOR);
    
    if(src.empty()){
        cerr << "Error loading image " << filename << endl;
        return -1;
    }
    imshow("Input image", src);

    //
    // Erosion
    //
    namedWindow("Erosion Demo", WINDOW_AUTOSIZE);
    createTrackbar(
        "Element:\n 0: Rect \n 1: Cross \n 2: Ellipse", 
        "Erosion Demo",
        &erosion_elem, max_elem,
        Erosion
        );

    createTrackbar(
        "Kernel size:\n 2n +1", 
        "Erosion Demo",
        &erosion_size, max_kernel_size,
        Erosion
        );
    Erosion(0, 0);
    
    //
    // Dilation
    //
    namedWindow("Dilation Demo", WINDOW_AUTOSIZE);
    moveWindow("Dilation Demo", src.cols, 0);
   
    createTrackbar( 
        "Element:\n 0: Rect \n 1: Cross \n 2: Ellipse", 
        "Dilation Demo",
        &dilation_elem, max_elem,
        Dilation
        );
    
    createTrackbar(
        "Kernel size:\n 2n +1", 
        "Dilation Demo",
        &dilation_size, max_kernel_size,
        Dilation
        );
    Dilation(0, 0);

    waitKey(0);
    destroyAllWindows();
    return 0;
}