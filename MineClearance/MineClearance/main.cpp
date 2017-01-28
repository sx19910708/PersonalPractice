#include "MineClearance.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MineClearance w;
	w.show();
	return a.exec();
}
