#include "MyGraphicView.h"

MyGraphicView::MyGraphicView(QWidget *parent)
	: QGraphicsView(parent)
{

}

MyGraphicView::~MyGraphicView()
{

}

void MyGraphicView::mousePressEvent(QMouseEvent *event)
{
	if (this->_mouseStatus)
	{
		QPointF mousePoint = this->mapToScene(event->pos());

		this->_startX = mousePoint.x();
		this->_startY = mousePoint.y();
		emit MousePress();
	}

}

void MyGraphicView::mouseMoveEvent(QMouseEvent *event)
{
	if (this->_mouseStatus)
	{
		QPointF mousePoint = this->mapToScene(event->pos());

		this->_moveX = mousePoint.x();
		this->_moveY = mousePoint.y();
		emit MouseMove();
	}
}

void MyGraphicView::mouseReleaseEvent(QMouseEvent *event)
{
	if (this->_mouseStatus)
	{
		QPointF mousePoint = this->mapToScene(event->pos());

		this->_endX = mousePoint.x();
		this->_endY = mousePoint.y();
		emit MouseRelease();
	}
}