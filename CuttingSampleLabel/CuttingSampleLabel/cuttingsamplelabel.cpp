#include "cuttingsamplelabel.h"
#include <QFileDialog>
#include <QDebug>
#include<QMessageBox>

#include "MyGraphicView.h"


CuttingSampleLabel::CuttingSampleLabel(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	QString s = QStringLiteral("國立台北科技大學 資訊工程系 1323實驗室 陳彥霖教授團隊 開發者:呂孟穎");
	ui.statusBar->showMessage(s);
	CreateActions();
	AddActionToToolBar();
	setAcceptDrops(true);
	setMouseTracking(true);
}

CuttingSampleLabel::~CuttingSampleLabel()
{

}

void CuttingSampleLabel::MousePressed()
{
	if (ui.graphicsView->_startX >= 0 && ui.graphicsView->_startY >= 0 && ui.graphicsView->_startX < _captureImage._rawData.cols && ui.graphicsView->_startY < _captureImage._rawData.rows)
	{
		_captureImage._startX = ui.graphicsView->_startX;
		_captureImage._startY = ui.graphicsView->_startY;
		//qDebug() << "StartX" << ui.graphicsView->_startX;
		//qDebug() << "StartY" << ui.graphicsView->_startY;
	}

}

void CuttingSampleLabel::MouseMoved()
{
	if (ui.graphicsView->_moveX >= _captureImage._startX && ui.graphicsView->_moveY >= _captureImage._startY && ui.graphicsView->_moveX < _captureImage._rawData.cols && ui.graphicsView->_moveY < _captureImage._rawData.rows)
	{
		_captureImage._moveX = ui.graphicsView->_moveX;
		_captureImage._moveY = ui.graphicsView->_moveY;
		//qDebug() << "MoveX" << ui.graphicsView->_moveX;
		//qDebug() << "MoveY" << ui.graphicsView->_moveY;
		_captureImage._rawData = _captureImage._destData.clone();
		cv::rectangle(_captureImage._rawData, cv::Point(_captureImage._startX, _captureImage._startY), cv::Point(_captureImage._moveX, _captureImage._moveY), cv::Scalar(0, 255, 0), 1, 0);
		ConvertMatToQImage();
		ShowQImage();
	}
}

void CuttingSampleLabel::MouseReleased()
{
	if (ui.graphicsView->_endX >= _captureImage._startX && ui.graphicsView->_endY >= _captureImage._startY && ui.graphicsView->_endX < _captureImage._rawData.cols && ui.graphicsView->_endY < _captureImage._rawData.rows)
	{
		_captureImage._endX = ui.graphicsView->_endX;
		_captureImage._endY = ui.graphicsView->_endY;
		//qDebug() << "EndX" << ui.graphicsView->_endX;
		//qDebug() << "EndY" << ui.graphicsView->_endY;
		
		cv::cvtColor(_captureImage._rawData, _captureImage._rawData, CV_BGR2RGB);

		cv::rectangle(_captureImage._rawData, cv::Point(_captureImage._startX, _captureImage._startY - 15), cv::Point(_captureImage._endX, _captureImage._startY), cv::Scalar(0, 0, 255), -1);
		cv::putText(_captureImage._rawData, _labelType.name, cv::Point(_captureImage._startX, _captureImage._startY - 5), 5, 0.55, cv::Scalar(0, 255, 255), 1);
		cv::rectangle(_captureImage._rawData, cv::Point(_captureImage._startX, _captureImage._startY), cv::Point(_captureImage._endX, _captureImage._endY), cv::Scalar(0, 0, 255), 1, 0);
		_captureImage._destData = _captureImage._rawData.clone();


		_labelType._result = cv::Rect(_captureImage._startX, _captureImage._startY, _captureImage._endX - _captureImage._startX, _captureImage._endY - _captureImage._startY);

		_captureImage._result[_labelType.typeId].push_back(_labelType);
		qDebug() << _captureImage._result[_labelType.typeId].size();
	
		ConvertMatToQImage();
		ShowQImage();
	}
	else
	{
		cv::cvtColor(_captureImage._rawData, _captureImage._rawData, CV_BGR2RGB);
		ConvertMatToQImage();
		ShowQImage();
	}
}

void CuttingSampleLabel::CreateActions()
{
	connect(ui._actionExit, SIGNAL(triggered()), this, SLOT(Exit()));
	connect(ui._actionOpenFile, SIGNAL(triggered()), this, SLOT(OpenFile()));
	connect(ui._actionSave, SIGNAL(triggered()), this, SLOT(SaveResult()));
	connect(ui.graphicsView, SIGNAL(MousePress()), this, SLOT(MousePressed()));
	connect(ui.graphicsView, SIGNAL(MouseMove()), this, SLOT(MouseMoved()));
	connect(ui.graphicsView, SIGNAL(MouseRelease()), this, SLOT(MouseReleased()));
	connect(ui.radioSpotLabelBt, SIGNAL(pressed()), this, SLOT(OnRadioButtonClick()));
	connect(ui.radioMetalLabelBt, SIGNAL(pressed()), this, SLOT(OnRadioButtonClick()));
	connect(ui.radioOilLabelBt, SIGNAL(pressed()), this, SLOT(OnRadioButtonClick()));
	connect(ui.radioOthersLabelBt, SIGNAL(pressed()), this, SLOT(OnRadioButtonClick()));
}

void CuttingSampleLabel::AddActionToToolBar()
{
	ui.mainToolBar->addSeparator();
	ui.mainToolBar->addAction(ui._actionOpenFile);
	ui.mainToolBar->addAction(ui._actionSave);
	ui.mainToolBar->addSeparator();
	ui.mainToolBar->addSeparator();
	ui.mainToolBar->addAction(ui._actionLabel);
	ui.mainToolBar->addAction(ui._actionDraw);
	ui.mainToolBar->addSeparator();
	ui.radioSpotLabelBt->setChecked(true);
	_labelType.name = ui.radioSpotLabelBt->text().toStdString();
	_labelType.typeId = 0;
}
void CuttingSampleLabel::OnRadioButtonClick()
{
	QObject* obj = sender();
	QRadioButton *rdb = qobject_cast<QRadioButton*>(obj);
	//qDebug() << rdb->text();

	_labelType.name = rdb->text().toStdString();
	_labelType.typeId = RadioTextToID(rdb->text());
	qDebug() << rdb->text();
	qDebug() << RadioTextToID(rdb->text());
}


void CuttingSampleLabel::OpenFile()
{
	_filePath.clear();
	qDebug() << "123" << _filePath.count();
	_filePath = QFileDialog::getOpenFileNames(this, tr("OpenFile"), "RawData", tr("Images *.png *.jpg *.bmp"));
	_openType = 0;
	qDebug() << "123" << _filePath.count();

	if (_filePath.count() != 0)
	{
		_captureImage._fileNumber = 0; //初始化 從0開始

		InitialCaptureResult();
		OpenRawData();
		ui.graphicsView->_mouseStatus = true;
		qDebug() << "openSuccess";
	}
		
}

void CuttingSampleLabel::OpenRawData()
{
	std::string str = _filePath[0].toStdString(); //stdString轉乘QString
	_captureImage._rawData.release();
	_captureImage._rawData = cv::imread(str);
	_captureImage._destData = _captureImage._rawData.clone();
	_captureImage._captureResultData = _captureImage._rawData.clone();

	ConvertMatToQImage();
	ShowQImage();
}

void CuttingSampleLabel::ConvertMatToQImage()
{
	if (_captureImage._rawData.channels() == 3) //三通道
	{
		cv::cvtColor(_captureImage._rawData, _captureImage._rawData, CV_BGR2RGB);
		_qImage = QImage((const unsigned char*)(_captureImage._rawData.data), _captureImage._rawData.cols, _captureImage._rawData.rows, _captureImage._rawData.cols * _captureImage._rawData.channels(), QImage::Format_RGB888);
	}
	else
	{
		_qImage = QImage((const unsigned char*)(_captureImage._rawData.data), _captureImage._rawData.cols, _captureImage._rawData.rows, _captureImage._rawData.cols * _captureImage._rawData.channels(), QImage::Format_RGB888);
	}

}

void CuttingSampleLabel::ShowQImage()
{
	QGraphicsScene *scene = new QGraphicsScene;
	scene->addPixmap(QPixmap::fromImage(_qImage));
	ui.graphicsView->setScene(scene);

	//ui.graphicsView->show();
}

int  CuttingSampleLabel::RadioTextToID(QString &str)
{
	QString ids[] = { "Spot", "Metal", "Oil", "Others" };
	int len = sizeof(ids) / sizeof(*ids);

	for (int i = 0; i < len; i++)
	{
		if (ids[i] == str)
		{
			return i;
		}
	
	}
	return -1;
}

void CuttingSampleLabel::InitialCaptureResult()
{
	_captureImage._result.clear();

	std::vector<LabelType> temp;
	temp.clear();
	_captureImage._result.push_back(temp);
	_captureImage._result.push_back(temp);
	_captureImage._result.push_back(temp);
	_captureImage._result.push_back(temp);
}

void CuttingSampleLabel::SaveResult()
{
	_captureImage.DrawResult();
	QMessageBox::information(this, tr("Save"), tr("Success"));
	QGraphicsScene *scene = new QGraphicsScene;
	scene->clear();
	ui.graphicsView->setScene(scene);
	ui.graphicsView->_mouseStatus = false;

	_captureImage._fileNumber++;

}

void CuttingSampleLabel::Exit()
{
	QApplication::quit();
}