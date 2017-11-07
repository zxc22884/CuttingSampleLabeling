#include "cuttingsamplelabel.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>
#include <direct.h>

#include "MyGraphicView.h"


CuttingSampleLabel::CuttingSampleLabel(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	QString s = QStringLiteral("國立台北科技大學 資訊工程系 1323實驗室 陳彥霖教授團隊 開發者:呂孟穎");
	ui.statusBar->showMessage(s);
	ui._lineEdit->setVisible(false);
	ui._radioAddLabel->setVisible(false);
	ui._okPushButton->setVisible(false);

	CreateActions();
	AddActionToToolBar();
	setAcceptDrops(true);
	setMouseTracking(true);
	InitialLabelRadioButton();
	InitialColorButton();

}

CuttingSampleLabel::~CuttingSampleLabel()
{

}

void CuttingSampleLabel::InitialCaptureResult()
{
	_captureImage._result.clear();
	_captureImage._state.clear();
	ui._actionPreviousState->setEnabled(false);

	std::vector<LabelType> temp;
	for (int i = 0; i < _labelRadioButton.size(); i++)
	{
		_captureImage._result.push_back(temp);
		qDebug() << "CAP" << _captureImage._result.size();
	}
	qDebug() << "bt"<<_labelRadioButton.size();
	qDebug() << "CAP" << _captureImage._result.size();
}

void CuttingSampleLabel::CreateActions()
{
	connect(ui._actionExit, SIGNAL(triggered()), this, SLOT(Exit())); //離開
	connect(ui._actionOpenFile, SIGNAL(triggered()), this, SLOT(OpenFile())); //開檔案
	connect(ui._actionOpenFolder, SIGNAL(triggered()), this, SLOT(OpenFolder()));//開資料夾
	connect(ui._actionSave, SIGNAL(triggered()), this, SLOT(SaveResult())); //儲存
	connect(ui._actionNextImage, SIGNAL(triggered()), this, SLOT(NextImage())); //下一張
	connect(ui._actionPreviousImage, SIGNAL(triggered()), this, SLOT(PreviousImage())); //上一張
	connect(ui._actionLabel, SIGNAL(triggered()), this, SLOT(ShowAddLabelRadioButton())); //新增種類
	connect(ui._actionPreviousState, SIGNAL(triggered()), this, SLOT(PreviousButtonClick())); //上一步

	connect(ui.graphicsView, SIGNAL(MousePress()), this, SLOT(MousePressed()));
	connect(ui.graphicsView, SIGNAL(MouseMove()), this, SLOT(MouseMoved()));
	connect(ui.graphicsView, SIGNAL(MouseRelease()), this, SLOT(MouseReleased()));


	connect(ui._okPushButton, SIGNAL(clicked()), this, SLOT(AddLabelRadioButton()));
	connect(ui._redButton, SIGNAL(clicked()), this, SLOT(OnColorButtonClick())); //框的顏色
	connect(ui._greenButton, SIGNAL(clicked()), this, SLOT(OnColorButtonClick())); //框的顏色
	connect(ui._blueButton, SIGNAL(clicked()), this, SLOT(OnColorButtonClick())); //框的顏色
	connect(ui._yellowButton, SIGNAL(clicked()), this, SLOT(OnColorButtonClick())); //框的顏色
	connect(ui._blackButton, SIGNAL(clicked()), this, SLOT(OnColorButtonClick())); //框的顏色
	connect(ui._whiteButton, SIGNAL(clicked()), this, SLOT(OnColorButtonClick())); //框的顏色
	
	//ui._redButton->setEnabled(false);
}

void CuttingSampleLabel::AddActionToToolBar()
{
	ui.mainToolBar->addAction(ui._actionOpenFolder);
	ui.mainToolBar->addAction(ui._actionOpenFile);
	ui.mainToolBar->addSeparator();
	ui.mainToolBar->addSeparator();
	ui.mainToolBar->addAction(ui._actionSave);
	ui.mainToolBar->addSeparator();
	//ui.mainToolBar->addSeparator();
	ui.mainToolBar->addAction(ui._actionLabel);
	//ui.mainToolBar->addAction(ui._actionDraw);
	ui.mainToolBar->addSeparator();
	ui.mainToolBar->addAction(ui._actionPreviousImage);
	ui.mainToolBar->addAction(ui._actionNextImage);
	ui.mainToolBar->addSeparator();
	ui.mainToolBar->addAction(ui._actionPreviousState);

	ui._actionNextImage->setEnabled(false);
	ui._actionPreviousImage->setEnabled(false);
	ui._actionPreviousState->setEnabled(false);
	_labelType.typeId = 0;
}

void CuttingSampleLabel::OnRadioButtonClick()
{
	QObject* obj = sender();
	QRadioButton *rdb = qobject_cast<QRadioButton*>(obj);
	//qDebug() << rdb->text();

	_labelType.name = rdb->text().toStdString();
	_labelType.typeId = RadioTextToID(rdb->text());


	qDebug() << "Type"<<rdb->text();
	qDebug() << "ID"<<RadioTextToID(rdb->text());
	
}

int CuttingSampleLabel::RadioTextToID(QString &str) //得到 radioButton的 ID
{
	
	for (int i = 0; i < _labelRadioButton.size(); i++)
	{
		if (QString::fromStdString(_labelRadioButton[i]) == str)
		{
			return i;
		}

	}
	return -1;
}

void CuttingSampleLabel::InitialLabelRadioButton() //初始化
{
	_labelRadioButton.clear();

	QFont font;
	font.setFamily(QStringLiteral("Arial"));
	font.setPointSize(12);
	font.setBold(false);
	font.setWeight(50);

	QRadioButton *spotButton;
	spotButton = new QRadioButton(ui.groupLabelType);
	spotButton->setObjectName("Spotbt");
	spotButton->setFont(font);
	spotButton->setText("Spot");
	_vbox->addWidget(spotButton);
	spotButton->setChecked(true);
	_labelType.name = spotButton->text().toStdString();
	connect(spotButton, SIGNAL(pressed()), this, SLOT(OnRadioButtonClick())); //點到Radio Button
	_labelRadioButton.push_back("Spot");

	QRadioButton *metalButton;
	metalButton = new QRadioButton(ui.groupLabelType);
	metalButton->setObjectName("Metalbt");
	metalButton->setFont(font);
	metalButton->setText("Metal");
	_vbox->addWidget(metalButton);
	connect(metalButton, SIGNAL(pressed()), this, SLOT(OnRadioButtonClick())); //點到Radio Button
	_labelRadioButton.push_back("Metal");

	QRadioButton *oilButton;
	oilButton = new QRadioButton(ui.groupLabelType);
	oilButton->setObjectName("Oilbt");
	oilButton->setFont(font);
	oilButton->setText("Oil");
	_vbox->addWidget(oilButton);
	connect(oilButton, SIGNAL(pressed()), this, SLOT(OnRadioButtonClick())); //點到Radio Button
	_labelRadioButton.push_back("Oil");

	ui.groupLabelType->setLayout(_vbox);

}

void CuttingSampleLabel::AddLabelRadioButton() //新增
{ 
	if (!CheckRadioButton())
	{
		QMessageBox::information(this, tr("Warring"), tr("Label Type Exist"));
	}

	else if (ui._lineEdit->text() != "" && CheckText())
	{
		QFont font;
		font.setFamily(QStringLiteral("Arial"));
		font.setPointSize(12);
		font.setBold(false);
		font.setWeight(50);

		QRadioButton *tempButton;
		tempButton = new QRadioButton(ui.groupLabelType);
		tempButton->setObjectName(ui._lineEdit->text() + "bt");
		tempButton->setFont(font);
		tempButton->setText(ui._lineEdit->text());
		_vbox->addWidget(tempButton);
		connect(tempButton, SIGNAL(pressed()), this, SLOT(OnRadioButtonClick())); //點到Radio Button
		_labelRadioButton.push_back(ui._lineEdit->text().toStdString());

		std::string path = "Result//" + ui._lineEdit->text().toStdString();
		_mkdir(path.c_str());
		std::vector<LabelType> temp;
		_captureImage._result.push_back(temp);
		//qDebug() << "CAP" << _captureImage._result.size();

		ui._radioAddLabel->setVisible(false);
		ui._lineEdit->setVisible(false);
		ui._okPushButton->setVisible(false);
	}
	else
	{
		QMessageBox::information(this, tr("Warring"), tr("Please Key in label type with a~z A~Z 0~9 !!"));
	}

}

bool CuttingSampleLabel::CheckText() //檢查是否符合
{
	for (int i = 0; i < ui._lineEdit->text().size(); i++)
	{
		if ((ui._lineEdit->text()[i] >= 'a' && ui._lineEdit->text()[i] <= 'z' || ui._lineEdit->text()[i] >= 'A' || ui._lineEdit->text()[i] <= 'Z' || ui._lineEdit->text()[i] >= '0'&&ui._lineEdit->text()[i] <= '9') && ui._lineEdit->text()[i] != ' '&& ui._lineEdit->text()[i] != '/'&& ui._lineEdit->text()[i] != '?' && ui._lineEdit->text()[i] != '>' && ui._lineEdit->text()[i] != '<'&& ui._lineEdit->text()[i] != '"'&& ui._lineEdit->text()[i] != '*'&& ui._lineEdit->text()[i] != '|'&& ui._lineEdit->text()[i] != '\\')
		{
		}
		else
		{
			ui._lineEdit->clear();
			return false;
		}
	}
	return true;
}

bool CuttingSampleLabel::CheckRadioButton()
{
	for (int i = 0; i < _labelRadioButton.size(); i++)
	{
		if (ui._lineEdit->text().toStdString() == _labelRadioButton[i])
		{
			return false;
		}
	}
	return true;
}

void CuttingSampleLabel::InitialColorButton()
{
	ui._redButton->setStyleSheet("background-color: rgb(255,0,0);");
	ui._blueButton->setStyleSheet("background-color: rgb(0,0,255);");
	ui._greenButton->setStyleSheet("background-color: rgb(0,255,0);");
	ui._yellowButton->setStyleSheet("background-color: rgb(255,255,0);");
	ui._blackButton->setStyleSheet("background-color: rgb(0,0,0);");
	ui._whiteButton->setStyleSheet("background-color: rgb(255,255,255);");

}

void CuttingSampleLabel::OnColorButtonClick() //選顏色
{
	QObject* obj = sender();
	QPushButton *rdb = qobject_cast<QPushButton*>(obj);
	
	if (rdb->text() == "Red")
	{
		_labelType._rectangleColor = cv::Scalar(0, 0, 255);
		_labelType._textColor = cv::Scalar(0, 255, 255);
	}

	if (rdb->text() == "Green")
	{
		_labelType._rectangleColor = cv::Scalar(0, 255, 0);
		_labelType._textColor = cv::Scalar(255, 0, 0);
	}

	if (rdb->text() == "Blue")
	{
		_labelType._rectangleColor = cv::Scalar(255, 0, 0);
		_labelType._textColor = cv::Scalar(0, 255, 0);
	}

	if (rdb->text() == "Yellow")
	{
		_labelType._rectangleColor = cv::Scalar(0, 255, 255);
		_labelType._textColor = cv::Scalar(0, 0, 255);
	}

	if (rdb->text() == "Black")
	{
		_labelType._rectangleColor = cv::Scalar(0, 0, 0);
		_labelType._textColor = cv::Scalar(255, 255, 255);
	}

	if (rdb->text() == "White")
	{
		_labelType._rectangleColor = cv::Scalar(255, 255, 255);
		_labelType ._textColor = cv::Scalar(0, 0, 0);
	}
}

void CuttingSampleLabel::ShowAddLabelRadioButton() //顯示新增的
{
	ui._radioAddLabel->setVisible(true);
	ui._lineEdit->setVisible(true);
	ui._lineEdit->setText("");
	ui._okPushButton->setVisible(true);
}

void CuttingSampleLabel::OpenFolder()
{
	_filePath.clear();
	_folderPath.clear();
	_folderPath = QFileDialog::getExistingDirectory(this, tr("Image folder"));

	if (!_folderPath.isEmpty())
	{
		QDir dir(_folderPath);
		QStringList filter;
		filter << QLatin1String("*.png");
		filter << QLatin1String("*.bmp");
		filter << QLatin1String("*.jpg");
		dir.setNameFilters(filter);

		foreach(QFileInfo fileinfo, dir.entryInfoList())
		{
			
			_saveFlag = true;
			_filePath.push_back(fileinfo.absoluteFilePath());
		}
		if (_filePath.count() != 0)
		{
			_captureImage._fileNumber = 0; //初始化 從0開始
			_captureImage.SetUpImageQueue(_filePath);
			InitialCaptureResult();
			OpenRawData();
			ui.graphicsView->_mouseStatus = true;
		}
		else
		{
			QMessageBox::information(this, tr("Warring OpenFolder"), tr("No image in this folder!!"));
		}
	}
	CheckImageNumbers();

}

void CuttingSampleLabel::OpenFile()
{
	_filePath.clear();
	_folderPath.clear();
	_filePath = QFileDialog::getOpenFileNames(this, tr("OpenFile"), "RawData", tr("Images *.png *.jpg *.bmp"));


	if (_filePath.count() != 0)
	{
		_saveFlag = true;
		_captureImage._fileNumber = 0; //初始化 從0開始
		_captureImage.SetUpImageQueue(_filePath);
		InitialCaptureResult();
		OpenRawData();
		ui.graphicsView->_mouseStatus = true;
		//qDebug() << "openSuccess";
	}
	CheckImageNumbers();

}

void CuttingSampleLabel::OpenRawData() //開原始檔案
{
	_captureImage._rawData.release();
	_captureImage._rawData = cv::imread(_captureImage._fileName[_captureImage._fileNumber]);
	qDebug() << QString::fromStdString(_captureImage._fileName[_captureImage._fileNumber]);
	_captureImage._destData = _captureImage._rawData.clone();
	_captureImage._captureResultData = _captureImage._rawData.clone();

	ConvertMatToQImage();
	ShowQImage();
}

void CuttingSampleLabel::ConvertMatToQImage() //轉影像為QImage
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

void CuttingSampleLabel::ShowQImage() //顯示Image
{
	QGraphicsScene *scene = new QGraphicsScene;
	scene->addPixmap(QPixmap::fromImage(_qImage));
	ui.graphicsView->setScene(scene);

}

void CuttingSampleLabel::SaveResult() //儲存
{
	ui.graphicsView->_mouseStatus = false;
	
	_captureImage._fileNumber++;
	//qDebug() << _captureImage._fileName.size();
	if (_saveFlag)
	{
		_captureImage.DrawResult();
		_captureImage._state.clear();
		ui._actionPreviousState->setEnabled(false);
		QMessageBox::information(this, tr("Save"), tr("Success"));

		if (_captureImage._fileNumber < _captureImage._fileName.size())
		{
			ui.graphicsView->_mouseStatus = true;
			InitialCaptureResult();
			OpenRawData();

		}
		else
		{
			QGraphicsScene *scene = new QGraphicsScene;
			scene->clear();
			ui.graphicsView->setScene(scene);
			_saveFlag = false;
		}
	}
	else
	{
		QMessageBox::information(this, tr("Warring"), tr("No Image !!"));
	}
	CheckImageNumbers();

}

void CuttingSampleLabel::NextImage() //下一張圖
{
	_captureImage._fileNumber++;
	ui.graphicsView->_mouseStatus = true;
	InitialCaptureResult();
	OpenRawData();

	CheckImageNumbers();
}

void CuttingSampleLabel::PreviousImage()//上一張圖
{
	_captureImage._fileNumber--;
	ui.graphicsView->_mouseStatus = true;
	InitialCaptureResult();
	OpenRawData();
	CheckImageNumbers();
}

void CuttingSampleLabel::CheckImageNumbers() //檢查有幾張圖
{

	if (_captureImage._fileNumber > 0 && _captureImage._fileNumber + 1 < _captureImage._fileName.size())
	{
		ui._actionNextImage->setEnabled(true);
		ui._actionPreviousImage->setEnabled(true);
	}

	else if (_captureImage._fileNumber == 0 && _captureImage._fileNumber + 1 < _captureImage._fileName.size())
	{
		ui._actionNextImage->setEnabled(true);
		ui._actionPreviousImage->setEnabled(false);
	}

	else if (_captureImage._fileNumber + 1 == _captureImage._fileName.size() && _captureImage._fileNumber != 0)
	{
		ui._actionNextImage->setEnabled(false);
		ui._actionPreviousImage->setEnabled(true);
	}
	else
	{
		ui._actionNextImage->setEnabled(false);
		ui._actionPreviousImage->setEnabled(false);
	}
}

void CuttingSampleLabel::PreviousButtonClick() //前一步
{
	int number = 0;

	number = _captureImage._state[_captureImage._state.size() - 1];
	_captureImage._state.pop_back();
	_captureImage._result[number].pop_back();

	if (_captureImage._state.size() == 0)
	{
		ui._actionPreviousState->setEnabled(false);
	}
	_captureImage.DrawCapture();
	ConvertMatToQImage();
	ShowQImage();

}

void CuttingSampleLabel::Exit()
{
	QApplication::quit();
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

		//cv::cvtColor(_captureImage._rawData, _captureImage._rawData, CV_BGR2RGB);
		//cv::rectangle(_captureImage._rawData, cv::Point(_captureImage._startX, _captureImage._startY - 15), cv::Point(_captureImage._endX, _captureImage._startY), _captureImage._rectangleColor, -1);
		//cv::putText(_captureImage._rawData, _labelType.name, cv::Point(_captureImage._startX, _captureImage._startY - 5), 5, 0.55, _captureImage._textColor, 1);
		//cv::rectangle(_captureImage._rawData, cv::Point(_captureImage._startX, _captureImage._startY), cv::Point(_captureImage._endX, _captureImage._endY), _captureImage._rectangleColor, 1, 0);
		//_captureImage._destData = _captureImage._rawData.clone();

		_labelType._result = cv::Rect(_captureImage._startX, _captureImage._startY, _captureImage._endX - _captureImage._startX, _captureImage._endY - _captureImage._startY);
		_captureImage._result[_labelType.typeId].push_back(_labelType);
		
		_captureImage._state.push_back(_labelType.typeId);
		ui._actionPreviousState->setEnabled(true);
		qDebug() << _captureImage._result[_labelType.typeId].size();
		
		_captureImage.DrawCapture();
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