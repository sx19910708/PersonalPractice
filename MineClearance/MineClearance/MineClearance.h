#ifndef MINECLEARANCE_H
#define MINECLEARANCE_H

#include <QtWidgets/QMainWindow>
#include "ui_MineClearance.h"

class MineClearance : public QMainWindow
{
	Q_OBJECT

public:
	MineClearance(QWidget *parent = 0);
	~MineClearance();

private:
	Ui::MineClearanceClass ui;
};

#endif // MINECLEARANCE_H
