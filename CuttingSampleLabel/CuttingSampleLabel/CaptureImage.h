#ifndef CAPTURE_IMAGE_H
#define CAPTURE_IMAGE_H

#include <opencv2\objdetect\objdetect.hpp>
#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\opencv.hpp>
#include <opencv2\imgproc\imgproc.hpp>

#include "LabelType.h"

class CaptureImage
{
public:

	cv::Mat _rawData;
	cv::Mat _destData;
	cv::Mat _captureResultData;

	int _startX, _startY;
	int _moveX, _moveY;
	int _endX, _endY;
	int _destX, _destY;
	int _fileNumber = 0;

	std::vector<std::vector<LabelType>> _result;
	std::vector<std::string> _fileName;

	void DrawResult();
	void DrawCapture();

	CaptureImage();
	~CaptureImage();

protected:



private:
	
};


#endif