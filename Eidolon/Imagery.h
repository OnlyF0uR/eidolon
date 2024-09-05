#pragma once

#include <opencv2/opencv.hpp>
#include <iostream>

class Imagery
{
public:
	Imagery(const cv::Mat&, std::string);
	~Imagery();
	void blur() const;
	Imagery derivePreview();
	void save() const;
	void save(int) const;

private:
	cv::Mat image;
	std::string outputName;
};

