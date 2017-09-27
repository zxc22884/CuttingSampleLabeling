#ifndef CAPTURE_IMAGE_H
#define CAPTURE_IMAGE_H

#include <opencv2\objdetect\objdetect.hpp>
#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\opencv.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <QString>

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

	std::vector<std::vector<LabelType>> _result; //放結果
	std::vector<std::string> _fileName; //檔名

	void SetUpImageQueue(QStringList qFileName); //把檔名存入
	void DrawResult(); //畫結果
	void DrawCapture(); //畫暫時的結果

	CaptureImage();
	~CaptureImage();

protected:



private:
	
};


#endif