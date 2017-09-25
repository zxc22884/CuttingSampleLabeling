#ifndef MYGRAPHICVIEW_H
#define MYGRAPHICVIEW_H

#include <QGraphicsView>
#include <QMouseEvent>

class MyGraphicView : public QGraphicsView
{
	Q_OBJECT

public:

	explicit MyGraphicView(QWidget *parent = 0);
	~MyGraphicView();

	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);

	int _startX;
	int _startY;
	int _moveX;
	int _moveY;
	int _endX;
	int _endY;

	bool _mouseStatus = false;

	 
private:

signals :

	void MousePress();
	void MouseMove();
	void MouseRelease();
};

#endif // MYGRAPHICVIEW_H
