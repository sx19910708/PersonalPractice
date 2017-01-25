/********************************************************************************
** Form generated from reading UI file 'firstqtapp.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FIRSTQTAPP_H
#define UI_FIRSTQTAPP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FirstQtAppClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *FirstQtAppClass)
    {
        if (FirstQtAppClass->objectName().isEmpty())
            FirstQtAppClass->setObjectName(QStringLiteral("FirstQtAppClass"));
        FirstQtAppClass->resize(600, 400);
        menuBar = new QMenuBar(FirstQtAppClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        FirstQtAppClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(FirstQtAppClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        FirstQtAppClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(FirstQtAppClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        FirstQtAppClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(FirstQtAppClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        FirstQtAppClass->setStatusBar(statusBar);

        retranslateUi(FirstQtAppClass);

        QMetaObject::connectSlotsByName(FirstQtAppClass);
    } // setupUi

    void retranslateUi(QMainWindow *FirstQtAppClass)
    {
        FirstQtAppClass->setWindowTitle(QApplication::translate("FirstQtAppClass", "FirstQtApp", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FirstQtAppClass: public Ui_FirstQtAppClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FIRSTQTAPP_H
