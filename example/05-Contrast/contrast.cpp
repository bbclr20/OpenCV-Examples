#include<opencv2/opencv.hpp>
#include<iostream>

using namespace cv;
using namespace std;

int main(int argc, char **argv){
    CommandLineParser parser(argc, argv, 
                             "{image | ../../data/image/lena.jpg | input image}");
    
    String filename = parser.get<String>("image");
    
    Mat image = imread(filename, IMREAD_COLOR);
    if(image.empty()) { 
        cerr << "Error loading image" << endl; return -1; 
    }

    imshow("Input", image);
    
    //
    // modify the contrast of the image using the following equation:
    // output = alpha * input + beta
    //
    Mat new_image = Mat::zeros(image.size(), image.type());
    double alpha = 2.2;
    int beta = 50;
    
    // cout << " Basic Linear Transforms " << endl;
    // cout << "-------------------------" << endl;
    // cout << "* Enter the alpha value [1.0-3.0]: "; 
    // cin >> alpha;
    // cout << "* Enter the beta value [0-100]: ";    
    // cin >> beta;
    
    // for( int y = 0; y < image.rows; y++ ) {
    //     for( int x = 0; x < image.cols; x++ ) {
    //         for( int c = 0; c < image.channels(); c++ ) {
    //             new_image.at<Vec3b>(y,x)[c] =
    //               saturate_cast<uchar>( alpha*image.at<Vec3b>(y,x)[c] + beta );
    //         }
    //     }
    // }
    
    //
    //  converts an array to another data type with optional scaling 
    //  if rtype is negative, the output matrix will have the same type as the input. 
    //
    image.convertTo(new_image, // output 
                    -1,        // rtype
                    alpha,     // alpha
                    beta       // beta
                    );
    imshow("New Image", new_image);


    //
    // perform the Gamma transform with a look-up table
    // Gamma correlation: output = (input/255)^gamma * 255
    //
    Mat lookUpTable(1, 256, CV_8U);
    uchar* p = lookUpTable.ptr();
    double gamma = 0.4;
    for(int i = 0; i < 256; ++i) {
        p[i] = saturate_cast<uchar>(pow(i/255.0, gamma) * 255.0);
    }
    Mat res = image.clone();
    LUT(image, lookUpTable, res);
    imshow("Gamma correlation", res);

    waitKey(0);
    destroyAllWindows();
    return 0;
}