#include "CaptureImage.h"
#include <QDir>
#include <QDebug>

CaptureImage::CaptureImage()
{

}

CaptureImage::~CaptureImage()
{

}

void CaptureImage::DrawCapture()
{


}

void CaptureImage::DrawResult()
{
	std::string filePath;
	std::string savePath;
	std::string rowPath;

	for (int i = 0; i < _result.size(); i++)
	{
		for (int j = 0; j < _result[i].size(); j++)
		{	
			filePath = "Result//" + _result[i][j].name;
			QDir myDir(QString::fromStdString(filePath));
			int myCount1 = myDir.count() - 2;
			savePath = "Result//" + _result[i][j].name + "//" + _result[i][j].name + "(" + std::to_string(myCount1) + ").jpg";
			//qDebug() << myDir.count();2
			cv::Mat roiImg(_captureResultData, _result[i][j]._result);
			cv::imwrite(savePath, roiImg);

		}
	}

	rowPath = "Result//Result//";
	QDir myDir1(QString::fromStdString(rowPath));
	cv::cvtColor(_rawData, _rawData, CV_BGR2RGB);
	int myCount = myDir1.count() - 2;
	cv::imwrite(rowPath + std::to_string(myCount) + ".jpg", _rawData);

}

void CaptureImage::SetUpImageQueue(QStringList qFileName)
{
	_fileName.clear();
	for (int i = 0; i < qFileName.count(); i++)
	{
		_fileName.push_back(qFileName[i].toStdString());
	}
}
;