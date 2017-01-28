#ifndef CONNTROLER_H
#define CONNTROLER_H

#include <QObject>
#include <QStandardItemModel>

/*Conntroler -- 运算与随机生成类*/
class Conntroler : public QObject
{
	Q_OBJECT

public:
	Conntroler();
	~Conntroler();

	/*
	*Summary: 设置布雷模型
	*Parameters:
	*     mineModel:布雷模型指针 
	*Return : void.
	*/
	void SetMineModel(QAbstractItemModel *mineModel);

private:

	// 布雷数据模型
	QStandardItemModel *mineModel_;
};

#endif // CONNTROLER_H
