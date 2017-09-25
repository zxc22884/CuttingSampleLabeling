#ifndef LABEL_TYPE_H
#define LABEL_TYPE_H

#include <string>
#include <opencv2\objdetect\objdetect.hpp>
#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\opencv.hpp>
#include <opencv2\imgproc\imgproc.hpp>

class LabelType
{
public:
	
	std::string name;
	int typeId;

	cv::Rect _result;

	LabelType();
	~LabelType();

protected:

private:

};


#endif