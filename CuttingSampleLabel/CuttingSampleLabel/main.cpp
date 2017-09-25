#include "cuttingsamplelabel.h"
#include <QtWidgets/QApplication>
#include <opencv2\opencv.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\core\core.hpp>
#include <opencv2\imgproc\imgproc.hpp>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	CuttingSampleLabel w;
	w.show();
	return a.exec();
}
