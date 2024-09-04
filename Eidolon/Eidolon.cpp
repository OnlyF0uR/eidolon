// CSImageOptimizer.cpp : Defines the entry point for the application.
// 

#include "Eidolon.h"

static void compress(const cv::Mat& input, const std::string& outputFilePath) {
    std::vector<int> compression_params;

    compression_params.push_back(cv::IMWRITE_WEBP_QUALITY);
    compression_params.push_back(80);

    if (!cv::imwrite(outputFilePath, input, compression_params)) {
        std::cerr << "Error: Could not write the image to " << outputFilePath << std::endl;
    }
    else {
        std::cout << "Image successfully converted to " << outputFilePath << std::endl;
    }
}

int main() {
    std::string inputFilePath = "image.png";
    std::string outputFilePath = "image.webp";

    // Load the image from the file
    cv::Mat image = cv::imread(inputFilePath, cv::IMREAD_COLOR);

    // Check if the image was loaded successfully
    if (image.empty()) {
        std::cerr << "Error: Could not open or find the image " << inputFilePath << std::endl;
        return -1;
    }

    // Compress and save the image
    compress(image, outputFilePath);

    return 0;
}