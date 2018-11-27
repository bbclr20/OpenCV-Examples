#include<opencv2/opencv.hpp>
#include<iostream>
// #include<string>

using namespace cv;
using namespace std;

static void help(char* progName) {
    cout <<  endl << "This program shows how to filter images with mask" << endl
         <<  "Usage:" << endl << "    "
         << progName << " [image_path -- default ../../data/lena.jpg] [G -- grayscale] " << endl << endl;
}

void Sharpen(const Mat& myImage, Mat& Result){
    CV_Assert(myImage.depth() == CV_8U);

    const int nChannels = myImage.channels();
    Result.create(myImage.size(), myImage.type());
    for(int j=1; j<myImage.rows-1;++j){
        const uchar* previous = myImage.ptr<uchar>(j-1);
        const uchar* current = myImage.ptr<uchar>(j);
        const uchar* next = myImage.ptr<uchar>(j+1);

        uchar *output = Result.ptr<uchar>(j);
        for (int i=nChannels; i<nChannels*(myImage.cols-1);++i){
            *output++ = saturate_cast<uchar>(5*current[i]
                            -current[i-nChannels] - current[i+nChannels] - previous[i] - next[i]);
        }
    }
    Result.row(0).setTo(Scalar(0));
    Result.row(Result.rows-1).setTo(Scalar(0));
    Result.col(0).setTo(Scalar(0));
    Result.col(Result.cols-1).setTo(Scalar(0));
}

int main(int argc, char **argv){
    help(argv[0]);
    
    const String filename = argc >=2 ? argv[1] : "../../data/image/lena.jpg";
    Mat src;
    if (argc >= 3 && !strcmp("G", argv[2])){
        src = imread( filename, IMREAD_GRAYSCALE);
    }else{
        src = imread( filename, IMREAD_COLOR);
    }
    
    if (src.empty()){
        cerr << "Can't open image ["  << filename << "]" << endl;
        return -1;
    }
    imshow("Input", src);
    
    // hand written function
    Mat dst0;
    double t = (double)getTickCount();
    Sharpen(src, dst0);
    t = ((double)getTickCount() - t)/getTickFrequency();
    cout << "Hand written function takes: " << t << " s" << endl;
    imshow("Hand written", dst0);
    
    // use OpenCV built-in function
    Mat kernel = (Mat_<char>(3,3) <<  0, -1,  0,
                                     -1,  5, -1,
                                      0, -1,  0);
    Mat dst1;
    t = (double)getTickCount();
    filter2D(src, dst1, src.depth(), kernel);
    t = ((double)getTickCount() - t)/getTickFrequency();
    cout << "Built-in filter2D takes: " << t << " s" << endl;
    imshow( "Built-in", dst1 );
    
    waitKey(0);
    destroyAllWindows();
    return 0;
}