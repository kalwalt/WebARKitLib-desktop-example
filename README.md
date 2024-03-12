# WebARKitLib desktop example

A simple repository to show how to use WebARKitLib in a desktop environment. This example uses the [WebARKitLib](https://github.com/webarkit/WebARKitLib) library to create a simple desktop application that uses the camera to detect and track an image. Note that we are testing a specific branch of the WebARKitLib library, so it may not work with the latest version of the library, It's recommended to use the same version of the library that is used in this example. (See the commit hash in the repository for the version used in this example.)
It use the [IGL](https://github.com/facebook/igl) library for the rendering stuff. Tested under Linux (Ubuntu 22.04).

## How to build


### Prerequisites
 You need git and cmake to build the project. You can install them with the following commands: `sudo apt-get install git cmake`.
 Then you can clone this repository and update the submodules with the following commands: `git submodule update --init`.

### Build

To build the project, you can use the following commands:
```bash
# Create a build directory
mkdir build
# run the build script
./build.sh
# go to the build directory and run the webarkit_example
cd build && ./webarkit_example

```