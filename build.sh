#! /bin/bash
cd build
cmake -DEMSCRIPTEN_COMP=0 -DIGL_WITH_VULKAN=OFF -DIGL_WITH_SAMPLES=OFF ..
cmake --build .