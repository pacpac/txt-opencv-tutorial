#include "opencv2/opencv.hpp"
#include "opencv2/videoio/videoio.hpp"
#include "iostream"

#define DEBUG 1

using namespace cv;
using namespace std;

int main(int argc, char** argv) {
    // open the first webcam plugged in the computer
    VideoCapture camera(0);
    if (!camera.isOpened()) {
        cerr << "ERROR: Could not open camera" << endl;
        return 1;
    }

    // this will contain the image from the webcam
    Mat frame;
        
    // capture the next frame from the webcam
    camera >> frame;
    
    return 0;
}
