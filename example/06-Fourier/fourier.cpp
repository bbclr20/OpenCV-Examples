#include<opencv2/opencv.hpp>
#include<iostream>

using namespace cv;
using namespace std;

int main(int argc, char **argv){
    CommandLineParser parser(argc, argv, 
                             "{image | ../../data/image/hexagonal.jpg | input image}");
    
    String filename = parser.get<String>("image");
    
    Mat image = imread(filename, IMREAD_GRAYSCALE);
    if(image.empty()) { 
        cerr << "Error loading image" << endl; return -1; 
    }
    imshow("Input", image);
    
    // apply low pass filter to the image
    Mat blur;
    GaussianBlur(image, blur, Size(5, 5), 3, 3);
    imshow("Blur", blur);
    
    Mat padded;
    int m = getOptimalDFTSize(blur.rows);
    int n = getOptimalDFTSize(blur.cols);

    // the function copies the source image into the middle of the destination image
    copyMakeBorder(blur,            // src
                   padded,          // dst
                   0,               // top
                   m - blur.rows,   // bottom
                   0,               // left
                   n - blur.cols,   // right
                   BORDER_CONSTANT, // borderType
                   Scalar::all(0)   // value
                   );
    
    Mat planes[] = {
        Mat_<float>(padded),              // real part 
        Mat::zeros(padded.size(), CV_32F) // imaginary part
        };
    Mat complexI;

    // creates one multi-channel array out of several single-channel ones
    merge(planes,   // src 
          2,        // count
          complexI  // dst
          );
    cout << "complexI.channels(): " << complexI.channels() << endl;

    //
    // Perform a forward or inverse Discrete Fourier transform of 
    // a 1D or 2D floating-point array. 
    //
    dft(complexI, // src 
        complexI  // dst
        );
    
    //
    // divide a multi-channel array into several single-channel arrays 
    // planes[0] = Re(DFT(I), planes[1] = Im(DFT(I))
    //
    split(complexI, // src 
          planes    // mvbegin
          );

    // calculate the euclidean length of 2D vectors
    magnitude(planes[0], // inputx
              planes[1], // inputy
              planes[0]  // magnitude
              );
    Mat magI = planes[0];

    //
    // compute the magnitude and switch to logarithmic scale
    // => log(1 + sqrt(Re(DFT(I))^2 + Im(DFT(I))^2))
    //
    magI += Scalar::all(1);
    log(magI, magI);

    //
    // rearrange the quadrants of Fourier image  
    // so that the origin is at the image center
    //
    magI = magI(Rect(0, 0, magI.cols & -2, magI.rows & -2));
    
    int cx = magI.cols/2;
    int cy = magI.rows/2;
    Mat q0(magI, Rect(0, 0, cx, cy));   // Top-Left - Create a ROI per quadrant
    Mat q1(magI, Rect(cx, 0, cx, cy));  // Top-Right
    Mat q2(magI, Rect(0, cy, cx, cy));  // Bottom-Left
    Mat q3(magI, Rect(cx, cy, cx, cy)); // Bottom-Right
    
    // swap q0 with q3
    Mat tmp;
    q0.copyTo(tmp);
    q3.copyTo(q0);
    tmp.copyTo(q3);

    // swap q1 with q2
    q1.copyTo(tmp);
    q2.copyTo(q1);
    tmp.copyTo(q2);
    
    // normalize the result
    normalize(magI, magI, 0, 1, NORM_MINMAX);
    imshow("spectrum magnitude", magI);

    waitKey(0);
    destroyAllWindows();
    return 0;
}