#include "MineClearance.h"
#include <QtWidgets/QApplication>
#include <QStandardItemModel>
#include "Conntroler.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	// �������
	MineClearance w;

	// ���ƶ���
	Conntroler conntroler;

	// ģ�Ͷ���
	QStandardItemModel mineModel;

	conntroler.SetMineModel(&mineModel);

	w.show();
	return a.exec();
}
