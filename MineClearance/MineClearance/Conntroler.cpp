#include "Conntroler.h"

Conntroler::Conntroler()
{
	this->mineModel_ = NULL;
}

Conntroler::~Conntroler()
{

}

/*
*Summary: 设置布雷模型
*Parameters:
*     mineModel:布雷模型指针 
*Return : void.
*/
void Conntroler::SetMineModel(QAbstractItemModel * mineModel)
{
	this->mineModel_ = qobject_cast<QStandardItemModel *>(mineModel);
}
