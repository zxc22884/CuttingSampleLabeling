#ifndef CUTTINGSAMPLELABEL_H
#define CUTTINGSAMPLELABEL_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsSceneDragDropEvent>
#include <QMouseEvent>
#include <QPoint>
#include <QtWidgets/QMainWindow>
#include <QHBoxLayout>
#include <QRadioButton>

#include "ui_cuttingsamplelabel.h"
#include "LabelType.h"
#include "CaptureImage.h"

class CuttingSampleLabel : public QMainWindow
{
	Q_OBJECT

public:

	CaptureImage _captureImage;
	QVBoxLayout *_vbox = new QVBoxLayout;
	
	CuttingSampleLabel(QWidget *parent = 0);
	~CuttingSampleLabel();


private:

	Ui::CuttingSampleLabelClass ui;

	QString _folderPath;
	QStringList _filePath;
	QImage _qImage;
	LabelType _labelType;
	std::vector<std::string> _labelRadioButton; //Label的Radio
	std::vector<std::string> _colorRadioButton; //Color的Radio
	

	bool _saveFlag = false;

	void AddActionToToolBar(); //把Action加到ToolBar
	void CreateActions(); //連結工作slot
	void OpenRawData(); //開啟圖片 
	void ConvertMatToQImage(); //Mat轉QImage
	void ShowQImage(); //在GraphicsView 顯示
	void InitialCaptureResult(); //初始化Result次數
	void CheckImageNumbers(); //看還有幾張
	void InitialLabelRadioButton();
 	int  RadioTextToID(QString &str); 
	bool CheckText();//確認是否符合規則
	bool CheckRadioButton();

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
	void AddLabelRadioButton();//增加Button 確定
	void ShowAddLabelRadioButton(); //顯示

};

#endif // CUTTINGSAMPLELABEL_H
