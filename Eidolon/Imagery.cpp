#include "Imagery.h"

Imagery::Imagery(const cv::Mat& image, std::string outputName)
{
	Imagery::image = image;
	Imagery::outputName = outputName;
}

Imagery::~Imagery()
{
}

void Imagery::blur() const {
	cv::GaussianBlur(Imagery::image, Imagery::image, cv::Size(85, 85), 55, 55);
}

void Imagery::save() const {
	std::string filePath = Imagery::outputName + ".webp";
	if (!cv::imwrite(filePath, Imagery::image)) {
		std::cerr << "Error: Could not write the image to " << filePath << std::endl;
	}
	else {
		std::cout << "Image saved to " << filePath << std::endl;
	}
}

void Imagery::save(int qualityPushback) const {
	std::string filePath = Imagery::outputName + ".webp";

	std::vector<int> compression_params;

	compression_params.push_back(cv::IMWRITE_WEBP_QUALITY);
	compression_params.push_back(qualityPushback);

	if (!cv::imwrite(filePath, Imagery::image, compression_params)) {
		std::cerr << "Error: Could not write the image to " << filePath << std::endl;
	}
	else {
		std::cout << "Image saved to " << filePath << std::endl;
	}
}

Imagery Imagery::derivePreview() {
	cv::Mat blurredImage;
	Imagery::image.copyTo(blurredImage);

	Imagery imagery(blurredImage, Imagery::outputName + "-preview");
	imagery.blur();

	return imagery;
}
