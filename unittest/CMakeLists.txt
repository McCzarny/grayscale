cmake_minimum_required(VERSION 3.15)
project(UnitTests CXX)

include(CTest)

find_package(gtest REQUIRED)

INCLUDE_DIRECTORIES( ${OpenCV_INCLUDE_DIRS} )

add_executable(unit_tests src/test_grayscale_conversion.cpp)
target_link_libraries(unit_tests grayscale GTest::gtest GTest::gtest_main)


# Create a temporary directory for test images
set(TEST_TEMP_DIR ${CMAKE_BINARY_DIR}/$ENV{TMP})
file(MAKE_DIRECTORY ${TEST_TEMP_DIR})

# Copy images from resources directory to temp directory
file(COPY ${CMAKE_SOURCE_DIR}/unittest/resources DESTINATION ${TEST_TEMP_DIR})

add_test(NAME test_grayscale_conversion COMMAND  $<TARGET_FILE:unit_tests> WORKING_DIRECTORY  ${TEST_TEMP_DIR})
