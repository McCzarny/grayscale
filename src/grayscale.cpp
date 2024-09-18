#include "grayscale.hpp"

#include <opencv2/opencv.hpp>

#include <iostream>

namespace grayscale
{
bool convert_to_grayscale(
    const std::filesystem::path& input_file,
    const std::filesystem::path& output_filename)
{
        // Load image
        std::cout << "Converting " << input_file << " to " << output_filename << std::endl;
        auto img = cv::imread(input_file, cv::IMREAD_COLOR);
        if (img.empty()) {
            std::cerr << "Could not read the image: " << input_file << std::endl;
            return false;
        }

        // Convert to grayscale
        cvtColor(img, img, cv::COLOR_BGR2GRAY);

        // Write to disk
        if (!cv::imwrite(output_filename, img))
        {
            std::cerr << "Could not write image: " << output_filename << std::endl;
            return false;
        }
        std::cout << "Done!" << std::endl;
        return true;
}
} // namespace grayscale