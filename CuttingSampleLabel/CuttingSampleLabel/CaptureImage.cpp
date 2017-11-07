#include "CaptureImage.h"
#include <QDir>
#include <QDebug>
#include <QXmlStreamWriter>

CaptureImage::CaptureImage()
{

}

CaptureImage::~CaptureImage()
{

}

void CaptureImage::DrawCapture()
{
	_rawData  = _captureResultData.clone();
	for (int i = 0; i < _result.size(); i++)
	{
		for (int j = 0; j < _result[i].size(); j++)
		{
			//cv::cvtColor(_rawData, _rawData, CV_BGR2RGB);
			cv::rectangle(_rawData, cv::Point(_result[i][j]._result.x, _result[i][j]._result.y - 15), cv::Point(_result[i][j]._result.x + _result[i][j]._result.width, _result[i][j]._result.y), _result[i][j]._rectangleColor, -1);
			cv::putText(_rawData, _result[i][j].name, cv::Point(_result[i][j]._result.x, _result[i][j]._result.y - 5), 5, 0.55, _result[i][j]._textColor, 1);
			cv::rectangle(_rawData, cv::Point(_result[i][j]._result.x, _result[i][j]._result.y), cv::Point(_result[i][j]._result.x + _result[i][j]._result.width, _result[i][j]._result.y + _result[i][j]._result.height), _result[i][j]._rectangleColor, 1, 0);
			_destData = _rawData.clone();
		}
	}
}

void CaptureImage::DrawResult()
{
	std::string filePath;
	std::string savePath;
	std::string rowPath;
	std::string xmlRowPath;

	rowPath = "Result//Result//";
	QDir myDir1(QString::fromStdString(rowPath));
	int myCount = myDir1.count() - 2;

	xmlRowPath = "Result//XML//";


	std::string myPath = xmlRowPath + std::to_string(myCount) + ".xml";
	QFile file(QString::fromStdString(myPath));
	if (!file.open(QFile::WriteOnly | QFile::Text)) {
		qDebug() << "Error: Cannot write file: "
			<< qPrintable(file.errorString());
	}
	QXmlStreamWriter xmlWriter(&file);
	xmlWriter.setAutoFormatting(true);
	xmlWriter.writeStartDocument();
	xmlWriter.writeStartElement("r" + QString::fromStdString(std::to_string(myCount)));

	for (int i = 0; i < _result.size(); i++)
	{

		for (int j = 0; j < _result[i].size(); j++)
		{	
			if (j == 0)
			{
				xmlWriter.writeStartElement("entry");
				xmlWriter.writeAttribute("term", QString::fromStdString(_result[i][0].name));
			}
			QString position = "(" + QString::number(_result[i][j]._result.x) + "," + QString::number(_result[i][j]._result.y) + "," + QString::number(_result[i][j]._result.width) + "," + QString::number(_result[i][j]._result.height) + ")";
			xmlWriter.writeTextElement("position", position);

			filePath = "Result//" + _result[i][j].name;
			QDir myDir(QString::fromStdString(filePath));
			int myCount1 = myDir.count() - 2;
			savePath = "Result//" + _result[i][j].name + "//" + _result[i][j].name + "(" + std::to_string(myCount1) + ").jpg";
			//qDebug() << myDir.count();2
			cv::Mat roiImg(_captureResultData, _result[i][j]._result);
			cv::imwrite(savePath, roiImg);

			if (j == _result[i].size() - 1)
			{
				xmlWriter.writeEndElement();
			}

		}
	}
	xmlWriter.writeEndDocument();
	file.close();


	cv::cvtColor(_rawData, _rawData, CV_BGR2RGB);
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