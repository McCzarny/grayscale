cmake_minimum_required(VERSION 3.15)
project(GrayscaleApp CXX)
INCLUDE_DIRECTORIES( ${OpenCV_INCLUDE_DIRS} )


add_executable(app src/app.cpp)
target_link_libraries(app grayscale)
