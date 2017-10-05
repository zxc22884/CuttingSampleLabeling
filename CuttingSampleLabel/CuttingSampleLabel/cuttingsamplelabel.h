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
	std::vector<QRadioButton> _labelRadioButton;
	std::vector<QRadioButton> _colorRadioButton;

	bool _saveFlag = false;

	void AddActionToToolBar(); //��Action�[��ToolBar
	void CreateActions(); //�s���u�@slot
	void OpenRawData(); //�}�ҹϤ� 
	void ConvertMatToQImage(); //Mat��QImage
	void ShowQImage(); //�bGraphicsView ���
	void InitialCaptureResult(); //��l��Result����
	void CheckImageNumbers(); //���٦��X�i
 	int  RadioTextToID(QString &str); 

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

};

#endif // CUTTINGSAMPLELABEL_H
