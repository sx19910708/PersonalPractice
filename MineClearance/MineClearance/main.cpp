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

	// Ϊ����������ģ��
	conntroler.SetMineModel(&mineModel);

	// Ϊ��������ģ��
	w.SetMineModel(&mineModel);

	// Ϊ�������ÿ���
	w.SetMineConntroler(&conntroler);

	conntroler.InitMineLayout(9, 9, 10);

	w.show();

	return a.exec();
}
