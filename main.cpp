#include <WebARKitManager.h>
#include <WebARKitLog.h>
#include <WebARKitTrackers/WebARKitOpticalTracking/WebARKitEnums.h>
#include <WebARKitCamera.h>
#include <opencv2/imgcodecs.hpp>

int main() {
    WEBARKIT_LOGi("Init WebARKit example...\n");
    webarkit::WebARKitManager manager;
    // Init the manager with the Akaze tracker
    manager.initialiseBase(webarkit::TRACKER_TYPE::AKAZE_TRACKER, 640, 480);
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

    return 0;
}