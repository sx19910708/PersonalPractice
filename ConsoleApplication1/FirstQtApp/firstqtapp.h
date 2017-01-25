#ifndef FIRSTQTAPP_H
#define FIRSTQTAPP_H

#include <QtWidgets/QMainWindow>
#include "ui_firstqtapp.h"

class FirstQtApp : public QMainWindow
{
	Q_OBJECT

public:
	FirstQtApp(QWidget *parent = 0);
	~FirstQtApp();

private:
	Ui::FirstQtAppClass ui;
};

#endif // FIRSTQTAPP_H
