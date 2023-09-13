/********************************************************************************
** Form generated from reading UI file 'Minesweeper.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MINESWEEPER_H
#define UI_MINESWEEPER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MinesweeperClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MinesweeperClass)
    {
        if (MinesweeperClass->objectName().isEmpty())
            MinesweeperClass->setObjectName(QString::fromUtf8("MinesweeperClass"));
        MinesweeperClass->resize(600, 400);
        menuBar = new QMenuBar(MinesweeperClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        MinesweeperClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MinesweeperClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MinesweeperClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(MinesweeperClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        MinesweeperClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MinesweeperClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MinesweeperClass->setStatusBar(statusBar);

        retranslateUi(MinesweeperClass);

        QMetaObject::connectSlotsByName(MinesweeperClass);
    } // setupUi

    void retranslateUi(QMainWindow *MinesweeperClass)
    {
        MinesweeperClass->setWindowTitle(QCoreApplication::translate("MinesweeperClass", "Minesweeper", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MinesweeperClass: public Ui_MinesweeperClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MINESWEEPER_H
