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

	int _openType = 0; //0��file 1��folder

	void AddActionToToolBar(); //��Action�[��ToolBar
	void CreateActions(); //�s���u�@slot
	void OpenRawData(); //�}�ҹϤ� 
	void ConvertMatToQImage(); //Mat��QImage
	void ShowQImage(); //�bGraphicsView ���
	void InitialCaptureResult();
	int  RadioTextToID(QString &str);

private slots:

	void Exit(); //���}
	void OpenFile(); //�}���ɮ�
	void SaveResult();
	//void OpenDocument(); //�}�Ҹ�Ƨ�
	void MousePressed();
	void MouseMoved();
	void MouseReleased();	
	void OnRadioButtonClick();

};

#endif // CUTTINGSAMPLELABEL_H
