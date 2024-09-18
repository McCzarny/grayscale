#pragma once
#include <filesystem>

#ifdef _WIN32
  #define GRAYSCALE_EXPORT __declspec(dllexport)
#else
  #define GRAYSCALE_EXPORT
#endif

namespace grayscale
{
bool GRAYSCALE_EXPORT convert_to_grayscale(
  const std::filesystem::path& input_file,
  const std::filesystem::path& output_filename);
} // namespace grayscale