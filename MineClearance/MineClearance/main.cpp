#include "MineClearance.h"
#include <QtWidgets/QApplication>
#include <QStandardItemModel>
#include "Conntroler.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	// 界面对象
	MineClearance w;

	// 控制对象
	Conntroler conntroler;

	// 模型对象
	QStandardItemModel mineModel;

	conntroler.SetMineModel(&mineModel);

	w.show();
	return a.exec();
}
