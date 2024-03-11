cmake_minimum_required(VERSION 3.22)

project(WebarkitLib_desktop_example)

if(POLICY CMP0135)
  cmake_policy(SET CMP0026 NEW)
endif()

set(CMAKE_CXX_STANDARD 14)

include(FetchContent)

FetchContent_Declare(
  build_opencv
 URL https://github.com/webarkit/opencv-em/releases/download/0.1.5/opencv-4.7.0.zip
)

FetchContent_MakeAvailable(build_opencv)

add_subdirectory(./src/WebARKitLib/WebARKit ./src/WebARKitLib/WebARKit/build)

add_executable(webarkit_example main.cpp)

get_filename_component(PARENT_DIR ./src/WebARKitLib ABSOLUTE)

target_include_directories(webarkit_example PRIVATE "${PARENT_DIR}/WebARKit/include")
target_include_directories(webarkit_example PRIVATE "${PARENT_DIR}/WebARKit/WebARKitTrackers/WebARKitOpticalTracking/include")

target_include_directories(webarkit_example PRIVATE
        "${build_opencv_SOURCE_DIR}"
        "${build_opencv_SOURCE_DIR}/3rdparty/include/libjpeg"
        "${build_opencv_SOURCE_DIR}/libs/opencv/include"
        "${build_opencv_SOURCE_DIR}/libs/opencv/modules/calib3d/include"
        "${build_opencv_SOURCE_DIR}/libs/opencv/modules/core/include"
        "${build_opencv_SOURCE_DIR}/libs/opencv/modules/features2d/include"
        "${build_opencv_SOURCE_DIR}/libs/opencv/modules/flann/include"
        "${build_opencv_SOURCE_DIR}/libs/opencv/modules/imgcodecs/include"
        "${build_opencv_SOURCE_DIR}/libs/opencv/modules/imgproc/include"
        "${build_opencv_SOURCE_DIR}/libs/opencv/modules/video/include"
        "${build_opencv_SOURCE_DIR}/libs/opencv/modules/videoio/include"
        "${build_opencv_SOURCE_DIR}/libs/opencv_contrib/modules/xfeatures2d/include"
        )

set(webarkit_example 
${PARENT_DIR}/WebARKit/WebARKitManager.cpp
)

target_link_libraries(
  webarkit_example
  WebARKitLib
  "${build_opencv_SOURCE_DIR}/lib/libopencv_calib3d.a"
  "${build_opencv_SOURCE_DIR}/lib/libopencv_features2d.a"
  "${build_opencv_SOURCE_DIR}/lib/libopencv_flann.a"
  "${build_opencv_SOURCE_DIR}/lib/libopencv_imgcodecs.a"
  "${build_opencv_SOURCE_DIR}/lib/libopencv_video.a"
  "${build_opencv_SOURCE_DIR}/lib/libopencv_videoio.a"
  "${build_opencv_SOURCE_DIR}/lib/libopencv_xfeatures2d.a"
  "${build_opencv_SOURCE_DIR}/lib/libopencv_imgproc.a"
  "${build_opencv_SOURCE_DIR}/lib/libopencv_core.a"
  "${build_opencv_SOURCE_DIR}/3rdparty/lib/liblibopenjp2.a"
  "${build_opencv_SOURCE_DIR}/3rdparty/lib/libzlib.a"
)