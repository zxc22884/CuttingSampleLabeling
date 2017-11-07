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
	std::vector<std::string> _labelRadioButton; //Label��Radio
	std::vector<std::string> _colorRadioButton; //Color��Radio
	

	bool _saveFlag = false;

	void AddActionToToolBar(); //��Action�[��ToolBar
	void CreateActions(); //�s���u�@slot
	void OpenRawData(); //�}�ҹϤ� 
	void ConvertMatToQImage(); //Mat��QImage
	void ShowQImage(); //�bGraphicsView ���
	void InitialCaptureResult(); //��l��Result����
	void CheckImageNumbers(); //���٦��X�i
	void InitialLabelRadioButton();
	void InitialColorButton();
 	int  RadioTextToID(QString &str); 
	bool CheckText();//�T�{�O�_�ŦX�W�h
	bool CheckRadioButton();

private slots:

	void Exit(); //�I��Ĳ�o���}
	void OpenFile(); //�I��Ĳ�o�}���ɮ�
	void SaveResult(); //�I��Ĳ�o�s��
	void OpenFolder(); //�}�Ҹ�Ƨ�
	void NextImage();
	void PreviousImage();
	void MousePressed();
	void MouseMoved();
	void MouseReleased();	
	void OnRadioButtonClick();
	void AddLabelRadioButton();//�W�[Button �T�w
	void ShowAddLabelRadioButton(); //���
	void OnColorButtonClick();
	void PreviousButtonClick();

};

#endif // CUTTINGSAMPLELABEL_H
