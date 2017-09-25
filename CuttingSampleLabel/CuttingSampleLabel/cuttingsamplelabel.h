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

	QStringList _filePath;
	QImage _qImage;
	LabelType _labelType;

	int _openType = 0; //0為file 1為folder

	void AddActionToToolBar(); //把Action加到ToolBar
	void CreateActions(); //連結工作slot
	void OpenRawData(); //開啟圖片 
	void ConvertMatToQImage(); //Mat轉QImage
	void ShowQImage(); //在GraphicsView 顯示
	void InitialCaptureResult();
	int  RadioTextToID(QString &str);

private slots:

	void Exit(); //離開
	void OpenFile(); //開啟檔案
	void SaveResult();
	//void OpenDocument(); //開啟資料夾
	void MousePressed();
	void MouseMoved();
	void MouseReleased();	
	void OnRadioButtonClick();

};

#endif // CUTTINGSAMPLELABEL_H
