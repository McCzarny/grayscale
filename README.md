
# Grayscale Image Converter

[![CI Status](https://github.com/McCzarny/grayscale/workflows/CI/badge.svg)](https://github.com/McCzarny/grayscale/actions)
[![Page](https://img.shields.io/badge/pages-conversion%20example-blue)](https://McCzarny.github.io/grayscale/)

This project provides a simple tool to convert color images to grayscale using OpenCV.

## Prerequisites

- Conan2
- OpenCV

## Building the Project

```
conan install . --build=missing
conan build .
```

## CMake Targets

The project includes the following CMake targets:

1. `grayscale`: The main library for grayscale image conversion.
1. `app`: A test package containing a command-line application.
3. `unit_tests`: Unit tests for the project (requires Google Test).


## Usage

To convert a single image:

```
./grayscale_converter input_image.png output_image.png
```

## OpenCV Usage

This project utilizes OpenCV for image processing. Key OpenCV functions used include:

- `cv::imread()`: For reading input images
- `cv::cvtColor()`: For converting color images to grayscale
- `cv::imwrite()`: For saving the processed images

## Continuous Integration

This project uses GitHub Actions for continuous integration. The CI pipeline builds the project, runs tests, and generates a GitHub Pages website.

## GitHub Pages

CI generates a github page based on the built targets to present an example of input and output images. [GitHub Pages](https://yourusername.github.io/grayscale/). 

## License

None
