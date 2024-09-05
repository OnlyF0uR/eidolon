// CSImageOptimizer.cpp : Defines the entry point for the application.
// 

#include "Eidolon.h"
#include "Imagery.h"

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <input_image>" << std::endl;
        return -1;
    }

    std::string inputFilePath = argv[1];

	std::string filename = inputFilePath.substr(0, inputFilePath.find_last_of("."));
	std::string extention = inputFilePath.substr(inputFilePath.find_last_of(".") + 1);

    // If the extention is an image file
	if (extention == "jpg" || extention == "jpeg" || extention == "png" || extention == "bmp" || extention == "webp") {
        // Load the image from the file
        cv::Mat image = cv::imread(inputFilePath, cv::IMREAD_COLOR);

        // Check if the image was loaded successfully
        if (image.empty()) {
            std::cerr << "Error: Could not open or find the image " << inputFilePath << std::endl;
            return -1;
        }

        std::string outputFileName = filename + "-out";

		Imagery imagery(image, outputFileName);
        imagery.save(90);

		Imagery preview = imagery.derivePreview();
        preview.save(80);
    }
    else if (extention == "mov" || extention == "mp4" || extention == "flv") {
        std::cout << "Soon!" << std::endl;
    }
    else {
		std::cerr << "Error: Unsupported file format " << extention << std::endl;
		return -1;
    }

    return 0;
}