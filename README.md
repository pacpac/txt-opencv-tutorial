# Build

```bash
mkdir build
cd build
cmake -DCMAKE_TOOLCHAIN_FILE=../txt_toolchain.cmake ..
cmake --build .
```

# Manual build
```bash
g++ -I/usr/include/opencv -lopencv_core -lm -o opencv-ver opencv-ver.cpp
```
