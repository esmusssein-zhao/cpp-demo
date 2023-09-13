#include "centerface.h"

CenterFace::CenterFace(QWidget *parent) : QPushButton(parent)
{
    QPixmap pic;
    if(winFlag==1)
    {
        bool ret = pic.load(":/images/smile.png");
        if(!ret)
        {
            qDebug()<<"load error! at make smile.png;";
        }
        this->setFixedSize(pic.width()*0.3,pic.height()*0.3);
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pic);
        this->setIconSize(QSize(pic.width()*0.3,pic.height()*0.3));
    }
    else if(winFlag==0)
    {
        bool ret = pic.load(":/images/cry.png");
        if(!ret)
        {
            qDebug()<<"load error!at make cry.png;";
        }
        this->setFixedSize(pic.width()*0.3,pic.height()*0.3);
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pic);
        this->setIconSize(QSize(pic.width()*0.3,pic.height()*0.3));
    }
    else
    {
        bool ret = pic.load(":/images/normal.png");
        if(!ret)
        {
            qDebug()<<"load error!at make cry.png;";
        }
        this->setFixedSize(pic.width()*0.3,pic.height()*0.3);
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pic);
        this->setIconSize(QSize(pic.width()*0.3,pic.height()*0.3));
    }
}

void CenterFace::mousePressEvent(QMouseEvent *e)
{
    QPixmap pic;
    bool ret = pic.load(":/images/cry.png");
    if(!ret)
    {
        qDebug()<<"load error!at mouse press event;";
    }
    this->setFixedSize(pic.width()*0.3,pic.height()*0.3);
    this->setStyleSheet("QPushButton{border:0px;}");
    this->setIcon(pic);
    this->setIconSize(QSize(pic.width()*0.3,pic.height()*0.3));
    return QPushButton::mousePressEvent(e);
}

void CenterFace::mouseReleaseEvent(QMouseEvent *e)
{
    QPixmap pic;
    bool ret = pic.load(":/images/normal.png");
    if(!ret)
    {
        qDebug()<<"load error!at mouse relase event;";
    }
    this->setFixedSize(pic.width()*0.3,pic.height()*0.3);
    this->setStyleSheet("QPushButton{border:0px;}");
    this->setIcon(pic);
    this->setIconSize(QSize(pic.width()*0.3,pic.height()*0.3));
    return QPushButton::mousePressEvent(e);
}

//void CenterFace::changeWinFlag()
//{
//    winFlag = winFlag == 0?1:0;
//}
