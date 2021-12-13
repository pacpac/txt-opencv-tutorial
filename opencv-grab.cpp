#include <opencv2/opencv.hpp>
#include <iostream>
#include <stdio.h>

using namespace cv;
using namespace std;

int main(int, char**)
{
    Mat frame;

    VideoCapture cap;

    cap.open(0, cv::CAP_V4L2);

    if (!cap.isOpened()) {
        cerr << "ERROR! Unable to open camera\n";
        return -1;
    }

    cout << "Set PROP_FOURCC" << endl; 
    bool r = cap.set(cv::CAP_PROP_FOURCC, cv::VideoWriter::fourcc('Y','U','Y','V'));
    if (!r) {
        std::cout << "error cap.set()" << std::endl;
    	return -1;
    }
 
    cap.set(CAP_PROP_FRAME_WIDTH,320);
    cap.set(CAP_PROP_FRAME_HEIGHT,240);
    
    cout << "Camera frame W " << dec << cap.get(CAP_PROP_FRAME_WIDTH);
    cout << "; Camera frame H " << dec << cap.get(CAP_PROP_FRAME_HEIGHT);
    cout << "; Format " << dec << cap.get(CAP_PROP_FORMAT) << endl;

    cout << "Start grabbing" << endl;
    cap.read(frame);
    if (frame.empty()) {
        cerr << "ERROR! blank frame grabbed" << endl;
        return -1;
    } else {
        cout << "I Have a frame!\n";
    }

    cout << "Frame size: W " << frame.cols << ", H " << frame.rows << endl;     
    cout << "Frame channels:" << frame.channels() << endl; 

    if (imwrite("frame.jpg", frame)) {
        cout << "Frame written to file" << endl;
    } else {
        cerr << "ERROR! write to file failed" << endl;
    }

    return 0;
}
