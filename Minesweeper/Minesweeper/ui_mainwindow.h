/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action8_8;
    QAction *action16_16;
    QAction *action10_10;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menu;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(414, 422);
        action8_8 = new QAction(MainWindow);
        action8_8->setObjectName(QString::fromUtf8("action8_8"));
        action16_16 = new QAction(MainWindow);
        action16_16->setObjectName(QString::fromUtf8("action16_16"));
        action10_10 = new QAction(MainWindow);
        action10_10->setObjectName(QString::fromUtf8("action10_10"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 414, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(action8_8);
        menu->addSeparator();
        menu->addAction(action10_10);
        menu->addSeparator();
        menu->addAction(action16_16);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        action8_8->setText(QCoreApplication::translate("MainWindow", "\345\210\235\347\272\247", nullptr));
        action16_16->setText(QCoreApplication::translate("MainWindow", "\351\253\230\347\272\247", nullptr));
        action10_10->setText(QCoreApplication::translate("MainWindow", "\344\270\255\347\272\247", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\346\211\253\351\233\267", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
