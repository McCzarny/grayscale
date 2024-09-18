#include <iostream>
#include <filesystem>

#include "grayscale.hpp"

int main(const int argc, const char *argv[]) {
    if (argc != 3) {
        std::cout << "Usage: " << argv[0] << " <input_filename> <output_filename>" << std::endl;
        return 1;
    }

    const std::filesystem::path input_filename = argv[1];
    const std::filesystem::path output_filename = argv[2];
    grayscale::convert_to_grayscale(input_filename, output_filename);
}
