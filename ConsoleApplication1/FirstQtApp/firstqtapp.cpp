#include "firstqtapp.h"
#include <qwidget.h>

FirstQtApp::FirstQtApp(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	QWidget *q = new QWidget;
	q->show();
}

FirstQtApp::~FirstQtApp()
{

}
