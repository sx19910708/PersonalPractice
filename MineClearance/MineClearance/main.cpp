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

	// 为控制器设置模型
	conntroler.SetMineModel(&mineModel);

	// 为界面设置模型
	w.SetMineModel(&mineModel);

	// 为界面设置控制
	w.SetMineConntroler(&conntroler);

	conntroler.InitMineLayout(9, 9, 10);

	w.show();

	return a.exec();
}
