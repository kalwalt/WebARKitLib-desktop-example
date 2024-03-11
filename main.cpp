#include <WebARKitManager.h>
#include <WebARKitLog.h>
#include <WebARKitTrackers/WebARKitOpticalTracking/WebARKitEnums.h>
#include <WebARKitCamera.h>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/videoio.hpp>

void processVideo(webarkit::WebARKitManager& manager, cv::VideoCapture& capture);

int main() {
    WEBARKIT_LOGi("Init WebARKit example...\n");
    webarkit::WebARKitManager manager;
    // Init the manager with the Teblid tracker
    manager.initialiseBase(webarkit::TRACKER_TYPE::TEBLID_TRACKER, 640, 480);
     // Load the test image
    cv::Mat image = cv::imread("../pinball.jpg", cv::IMREAD_GRAYSCALE);

    if(image.data == NULL) {
      std::cout << "Something wrong while reading the image!" << std::endl;
    }
  
    if(image.empty()) {
      image = cv::Mat::zeros(2048, 1637,  CV_8UC4);
    }

    int width = image.cols;
    int height = image.rows;
    unsigned char* data = image.data;

    manager.initTracker(data, width, height, webarkit::ColorSpace::GRAY);

    cv::VideoCapture cap;
    processVideo(manager, cap);

    return 0;
}

void processVideo(webarkit::WebARKitManager& manager, cv::VideoCapture& capture)
{
    // Grab first frame to get the frame dimensions
    cv::Mat currentFrame; 

    capture.open(0); // Open the default camera

    // Check the capture succeeded:
    if (!capture.isOpened()){ // This section prompt an error message if no video stream is found//
      std::cout << "No video stream detected" << std::endl;
      system("pause");
      return;
    }

    bool shouldQuit = false;
    do
    {
        capture >> currentFrame;

        cv::Size frameSize(currentFrame.cols, currentFrame.rows);

        if (currentFrame.empty())
        {
            shouldQuit = true;
            continue;
        }

        manager.processFrameData(currentFrame.data, currentFrame.cols, currentFrame.rows, webarkit::ColorSpace::RGBA);
        shouldQuit = getKeyEsc();
    } while (!shouldQuit);
}