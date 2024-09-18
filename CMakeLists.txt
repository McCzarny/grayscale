cmake_minimum_required(VERSION 3.15)
project(GrayscaleLib CXX)

set (CMAKE_CXX_STANDARD 17)

find_package(OpenCV REQUIRED)
INCLUDE_DIRECTORIES( ${OpenCV_INCLUDE_DIRS} )

add_library(grayscale src/grayscale.cpp)
target_include_directories(grayscale PUBLIC include)
target_link_libraries(grayscale PUBLIC opencv::opencv)

set_target_properties(grayscale PROPERTIES PUBLIC_HEADER "include/grayscale.h")
install(TARGETS grayscale)

add_subdirectory(test_package)

# Enable testing
enable_testing()

# Add unittest directory
add_subdirectory(unittest)
