cmake_minimum_required(VERSION 3.1)

project( txt-opencv-tutorial CXX )

set( OpenCV_DIR ../txt-opencv-build/install/opencv/share/OpenCV )

find_package( OpenCV REQUIRED core videoio imgproc imgcodecs )
include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable( opencv-ver opencv-ver.cpp )
add_executable( opencv-grab opencv-grab.cpp )
target_link_libraries( opencv-ver ${OpenCV_LIBS} )
target_link_libraries( opencv-grab ${OpenCV_LIBS} )
