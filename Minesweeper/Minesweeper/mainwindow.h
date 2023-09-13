#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "centerface.h"
#include "clickbutton.h"
#include <QToolBar>
#include <QTime>

#define LEVEL 6
#define BOMB_NUMBER 10
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
//    void clickButtonExendNull(ClickButton* bBI[LEVEL][LEVEL],ClickButton* eB,int bI[LEVEL+1][LEVEL+1],int i,int j);
private:
    ClickButton* bombButtonInfo[LEVEL][LEVEL];//按键状态
    int bombInfo[LEVEL+1][LEVEL+1];//炸弹信息
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
