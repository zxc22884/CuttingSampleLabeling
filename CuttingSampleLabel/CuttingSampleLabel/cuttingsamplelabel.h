#ifndef CUTTINGSAMPLELABEL_H
#define CUTTINGSAMPLELABEL_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsSceneDragDropEvent>
#include <QMouseEvent>
#include <QPoint>
#include <QtWidgets/QMainWindow>

#include "ui_cuttingsamplelabel.h"
#include "LabelType.h"
#include "CaptureImage.h"

class CuttingSampleLabel : public QMainWindow
{
	Q_OBJECT

public:

	CaptureImage _captureImage;

	CuttingSampleLabel(QWidget *parent = 0);
	~CuttingSampleLabel();


private:

	Ui::CuttingSampleLabelClass ui;

	QString _folderPath;
	QStringList _filePath;
	QImage _qImage;
	LabelType _labelType;

	bool _saveFlag = false;

	void AddActionToToolBar(); //把Action加到ToolBar
	void CreateActions(); //連結工作slot
	void OpenRawData(); //開啟圖片 
	void ConvertMatToQImage(); //Mat轉QImage
	void ShowQImage(); //在GraphicsView 顯示
	void InitialCaptureResult(); //初始化Result次數
	int  RadioTextToID(QString &str); 

private slots:

	void Exit(); //點擊觸發離開
	void OpenFile(); //點擊觸發開啟檔案
	void SaveResult(); //點擊觸發存檔
	void OpenFolder(); //開啟資料夾
	void NextImage();
	void PreviousImage();
	void MousePressed();
	void MouseMoved();
	void MouseReleased();	
	void OnRadioButtonClick();

};

#endif // CUTTINGSAMPLELABEL_H
