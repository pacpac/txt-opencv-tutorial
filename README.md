# Build
mkdir build
cd build
cmake ..
cmake --build .

# Manual build
g++ -I/usr/include/opencv -lopencv_core -lm -o opencv-ver opencv-ver.cpp
