#include "clickbutton.h"

ClickButton::ClickButton(QWidget *parent) : QPushButton(parent)
{
    QPixmap pic;
    int ret = pic.load(":/images/cube.jpg");
    if(!ret)
    {
        qDebug()<<"error!at cube.jpg  create main button;";
    }
    this->setFixedSize(pic.width()*0.5,pic.height()*0.5);
    this->setStyleSheet("QPushButton{border:0px;}");
    this->setIcon(pic);
    this->setIconSize(QSize(pic.width()*0.5,pic.height()*0.5));
    qDebug()<<"按钮长："<<pic.width()<<"按钮宽："<<pic.height();
}

//void ClickButton::mousePressEvent(QMouseEvent *e)
//{
//    QPixmap pic;
//    //左击
//    if(e->buttons() == Qt::LeftButton)
//    {
//        //不是炸弹，先显示为空
//        if(!stateInfo)
//        {
//            int ret = pic.load(":/images/0.jpg");
//            if(!ret)
//            {
//                qDebug()<<"error!at cube.jpg  create main button;";
//            }
//            this->setFixedSize(pic.width()*0.5,pic.height()*0.5);
//            this->setStyleSheet("QPushButton{border:0px;}");
//            this->setIcon(pic);
//            this->setIconSize(QSize(pic.width()*0.5,pic.height()*0.5));
//            return QPushButton::mousePressEvent(e);
//        }
//        //是炸弹，爆炸信息为true
//        else
//        {
////            stateInfo=true;
//            int ret = pic.load(":/images/bomb0.jpg");
//            if(!ret)
//            {
//                qDebug()<<"error!at cube.jpg  create main button;";
//            }
//            this->setFixedSize(pic.width()*0.5,pic.height()*0.5);
//            this->setStyleSheet("QPushButton{border:0px;}");
//            this->setIcon(pic);
//            this->setIconSize(QSize(pic.width()*0.5,pic.height()*0.5));
//            return QPushButton::mousePressEvent(e);
//        }
//    }
//    //右击

//}

void ClickButton::changeStateInfo()
{
    {
        stateInfo = stateInfo == 0?1:0;
    }
}
