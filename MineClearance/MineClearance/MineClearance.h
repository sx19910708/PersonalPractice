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

	/*
	*Summary: 设置布雷模型
	*Parameters:
	*     mineModel:布雷模型指针 
	*Return : void.
	*/
	void SetMineModel(QAbstractItemModel *mineModel);

	/*
	*Summary: 设置布雷控制
	*Parameters:
	*     mineConntroler:布雷模型控制
	*Return : void.
	*/
	void SetMineConntroler(QAbstractItemDelegate *mineConntroler);

private:
	Ui::MineClearanceClass ui;
};

#endif // MINECLEARANCE_H
