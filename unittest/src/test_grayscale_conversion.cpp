#include "grayscale.hpp"

#include <gtest/gtest.h>
#include <opencv2/opencv.hpp>

#include <filesystem>

TEST(GrayscaleTest, GrayscaleConversionTest) {
    const std::filesystem::path input_path = "input.png";
    const std::filesystem::path output_path = "output.png";
    const std::filesystem::path expected_path = "expected.png";
    ASSERT_TRUE(grayscale::convert_to_grayscale(input_path, output_path));
    ASSERT_TRUE(std::filesystem::exists(output_path));

    cv::Mat output_image = cv::imread(output_path.string(), cv::IMREAD_COLOR);
    cv::Mat expected_image = cv::imread(expected_path.string(), cv::IMREAD_COLOR);

    // Compare general properties of the output and expected images
    ASSERT_EQ(output_image.rows, expected_image.rows);
    ASSERT_EQ(output_image.cols, expected_image.cols);
    ASSERT_EQ(output_image.channels(), expected_image.channels());

    // Compare the pixel values of the output and expected images
    for (int i = 0; i < output_image.rows; ++i) {
        for (int j = 0; j < output_image.cols; ++j) {
            for (int c = 0; c < output_image.channels(); ++c) {
                EXPECT_EQ(output_image.at<cv::Vec3b>(i, j)[c], expected_image.at<cv::Vec3b>(i, j)[c]);
            }
        }
    }
}