#include "Conntroler.h"
#include <QTime>
#include <QStandardItem>
#include <QStyleOptionButton>
#include <QApplication>
#include <QMessageBox>
#include <QBrush>
#include <QColor>

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

/*
*Summary: 获取随机数
*Parameters:
*Return : 随机整数
*/
int Conntroler::GetRandomNum()
{
	QTime t = QTime::currentTime();
	qsrand(t.msec() + t.second() * 1000);
	return qrand();
}
/*
*Summary: 重新布雷
*Parameters:x 轴方格数量 y 轴方格数量 mineNum 雷数量
*Return : void
*/
void Conntroler::InitMineLayout(int x, int y, int mineNum)
{
	this->maxX_ = x;

	this->maxY_ = y;

	// 初始化棋盘
	for (int col = 0; col < x; col++)
	{
		for (int row = 0; row < y; row++)
		{
			QStandardItem *modelItem = new QStandardItem(row, col);
			modelItem->setData(0, Qt::UserRole + 1);

			this->mineModel_->setItem(row, col, modelItem);
		}
	}

	// 随机创建mineNum个对象
	for (int i = 0; i < mineNum; i++)
	{
		QPoint minePoint = this->GetRandomMinePoint(x ,y);

		this->setMineLayout.push_back(minePoint);

		// 设置进模型中
		this->mineModel_->item(minePoint.y(), minePoint.x())->setData(1, Qt::UserRole);
		//this->mineModel_->item(minePoint.y(), minePoint.x())->setData("*", Qt::DisplayRole);
	}
}

// Inherits by QItemDelegate
void Conntroler::paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index) const
{
	//QStyleOptionButton* button = m_btns.value(index);

	//if (!button) 
	//{
	//	button = new QStyleOptionButton();
	//	button->rect = option.rect.adjusted(4, 4, -4, -4);
	//	button->text = "X";
	//	button->state |= QStyle::State_Enabled;

	//	(const_cast<Conntroler *>(this))->m_btns.insert(index, button);
	//}

	//QApplication::style()->drawControl(QStyle::CE_PushButton, button, painter);

	QItemDelegate::paint(painter, option, index);
}

// virtual by QItemDelegate
bool Conntroler::editorEvent(QEvent * event, QAbstractItemModel * model, const QStyleOptionViewItem & option, const QModelIndex & index)
{
	if (event->type() == QEvent::MouseButtonRelease)
	{
		this->OpenMine(index);
	}

	return false;
}

/*
*Summary: 随机雷位置
*Parameters:x 轴位置上限 y 轴位置上限
*Return : 雷的坐标
*/
QPoint Conntroler::GetRandomMinePoint(int maxX, int maxY)
{
	// 获取xy轴坐标
	int x = this->GetRandomNum() % maxX;
	int y = this->GetRandomNum() % maxY;

	QPoint p(x, y);

	// 检查改坐标是否存在
	if (this->setMineLayout.contains(p))
	{
		p = this->GetRandomMinePoint(maxX, maxY);
	}

	return p;
}

/*
*Summary: 检测指定索引是否为雷
*Parameters:index 检测的索引
*Return : 是否为雷
*/
bool Conntroler::OpenMine(const QModelIndex & index)
{
	bool rec = false;

	int x = index.column();

	int y = index.row();

	int openFlg = this->mineModel_->data(index, Qt::UserRole + 1).toInt();

	if (x >= 0 && x < this->maxX_ &&
		y >= 0 && y < this->maxY_ && !openFlg)
	{
		// 设置已经翻开标志
		this->mineModel_->setData(index, 1, Qt::UserRole + 1);

		int aroundNum = 0;

		// 检测该位置是否为雷
		if (this->setMineLayout.contains(QPoint(x, y)))
		{
			QMessageBox::warning(0, "炸了", "点到雷了");
		}
		// 检测周围一圈的状况
		else
		{
			rec = true;

			if (this->setMineLayout.contains(QPoint(x - 1, y - 1))) aroundNum++;
			if (this->setMineLayout.contains(QPoint(x, y - 1))) aroundNum++;
			if (this->setMineLayout.contains(QPoint(x + 1, y - 1))) aroundNum++;
			if (this->setMineLayout.contains(QPoint(x - 1, y))) aroundNum++;
			if (this->setMineLayout.contains(QPoint(x + 1, y))) aroundNum++;
			if (this->setMineLayout.contains(QPoint(x - 1, y + 1))) aroundNum++;
			if (this->setMineLayout.contains(QPoint(x, y + 1))) aroundNum++;
			if (this->setMineLayout.contains(QPoint(x + 1, y + 1))) aroundNum++;

			if (!aroundNum)
			{
				this->mineModel_->setData(index, QBrush(QColor("gray")), Qt::BackgroundColorRole);

				OpenMine(index.sibling(y - 1, x - 1));
				OpenMine(index.sibling(y - 1, x));
				OpenMine(index.sibling(y - 1, x + 1));
				OpenMine(index.sibling(y, x - 1));
				OpenMine(index.sibling(y, x + 1));
				OpenMine(index.sibling(y + 1, x - 1));
				OpenMine(index.sibling(y + 1 ,x));
				OpenMine(index.sibling(y + 1, x + 1));

				int x1 = x - 1, y1 = y - 1;
				int x2 = x, y2 = y - 1;
				int x3 = x + 1, y3 = y - 1;
				int x4 = x - 1, y4 = y;
				int x5 = x + 1, y5 = y;
				int x6 = x - 1, y6 = y + 1;
				int x7 = x, y7 = y + 1;
				int x8 = x + 1, y8 = y + 1;

				auto i = 1;
			}
			else
			{
				this->mineModel_->setData(index, aroundNum, Qt::DisplayRole);
				this->mineModel_->setData(index, QBrush(QColor("green")), Qt::BackgroundColorRole);
			}
		}
	}

	// 超出棋盘范围
	else
	{
		rec = true;
	}

	return rec;
}
