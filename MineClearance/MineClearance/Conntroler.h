#ifndef CONNTROLER_H
#define CONNTROLER_H

#include <QMap>
#include <QVector>
#include <QPoint>
#include <QItemDelegate>
#include <QStandardItemModel>

/*Conntroler -- 运算与随机生成类*/
class Conntroler : public QItemDelegate
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

	/*
	*Summary: 重新布雷
	*Parameters:x 轴方格数量 y 轴方格数量 mineNum 雷数量
	*Return : void
	*/
	void InitMineLayout(int x, int y, int mineNum);

	// virtual by QItemDelegate
	void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;

	// virtual by QItemDelegate
	bool editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index);

private:

	/*
	*Summary: 获取随机数
	*Parameters:
	*Return : 随机整数
	*/
	int GetRandomNum();

	/*
	*Summary: 随机雷位置
	*Parameters:x 轴位置上限 y 轴位置上限
	*Return : 雷的坐标
	*/
	QPoint GetRandomMinePoint(int maxX, int maxY);

	/*
	*Summary: 检测指定索引是否为雷
	*Parameters:index 检测的索引
	*Return : 是否为雷
	*/
	bool OpenMine(const QModelIndex &index);

private:

	// 布雷数据模型
	QStandardItemModel *mineModel_;

	// 每局雷的位置分布
	QVector<QPoint> setMineLayout;

	// 按键显示样式
	QMap<QModelIndex, QStyleOptionButton*> m_btns;

	// 最大宽度高度
	int maxX_, maxY_;
};

#endif // CONNTROLER_H
