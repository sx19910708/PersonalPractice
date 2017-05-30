#include "MineClearance.h"

MineClearance::MineClearance(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

MineClearance::~MineClearance()
{

}

/*
*Summary: 设置布雷模型
*Parameters:
*     mineModel:布雷模型指针 
*Return : void.
*/
void MineClearance::SetMineModel(QAbstractItemModel * mineModel)
{
	ui.tableView->setModel(mineModel);
}

/*
*Summary: 设置布雷控制
*Parameters:
*     mineConntroler:布雷模型控制
*Return : void.
*/
void MineClearance::SetMineConntroler(QAbstractItemDelegate * mineConntroler)
{
	ui.tableView->setItemDelegate(mineConntroler);
}
