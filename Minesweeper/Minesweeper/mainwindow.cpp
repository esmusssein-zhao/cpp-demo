#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //状态栏不能使用（无法在最上层），使用的工具栏
    QToolBar* toolbar = new QToolBar(this);
    //界面大小
    if(LEVEL==6)
    {
        this->setFixedSize(240,320);
    }
    //添加工具栏和默认位置
    addToolBar(Qt::TopToolBarArea,toolbar);
    //限定停靠位置
    toolbar->setAllowedAreas(Qt::TopToolBarArea);
    //是否可以移动
    toolbar->setFloatable(false);
    //中心图标按钮
    CenterFace* centerFace = new CenterFace;
    centerFace->setParent(this);
//    centerFace->setLayout();
    toolbar->addWidget(centerFace);

    //存放雷的数组初始化为0
    for(int i=0;i<LEVEL+1;i++)
    {
        for(int j=0;j<LEVEL+1;j++)
        {
            bombInfo[i][j]=0;
        }
    }

    //布雷
    srand(QTime::currentTime().msec());
    for(int i=0;i<BOMB_NUMBER;i++)
    {
        bool flag = false;
        {
            int x_b = rand()%LEVEL+1;
            int y_b = rand()%LEVEL+1;
            if(bombInfo[x_b][y_b]==1)
                flag = true;
            else
                bombInfo[x_b][y_b]=1;
        } while (flag);
    }

    //格子
    for(int i=0;i<LEVEL;i++)
    {
        for(int j=0;j<LEVEL;j++)
        {
            ClickButton* everyButton = new ClickButton;
            everyButton->setParent(this);
            everyButton->move(20+33*i,80+33*j);
            //按键
            connect(everyButton,&ClickButton::clicked,[=]()
            {
                //如果为雷
                if(bombInfo[i+1][j+1]==1)
                {
                    everyButton->changeStateInfo();
                    QPixmap pic;
                    int ret = pic.load(":/images/bomb0.jpg");
                    if(!ret)
                    {
                        qDebug()<<"error!at cube.jpg  create main button;";
                    }
                    everyButton->setFixedSize(pic.width()*0.5,pic.height()*0.5);
                    everyButton->setStyleSheet("QPushButton{border:0px;}");
                    everyButton->setIcon(pic);
                    everyButton->setIconSize(QSize(pic.width()*0.5,pic.height()*0.5));
                }
                //如果不为雷
                else
                {
                    int nearBombNumber;
                    nearBombNumber = bombInfo[i][j]+bombInfo[i+2][j+2]+bombInfo[i][j+1]+bombInfo[i+1][j+2]+bombInfo[i+1][j]+bombInfo[i][j+2]+bombInfo[i+2][j]+bombInfo[i+2][j+1];
                    QPixmap pic;
                    QString address = QString(":/images/%1.jpg").arg(nearBombNumber);
                    int ret = pic.load(address);
                    if(!ret)
                    {
                        qDebug()<<"error!at %1.jpg  create main button;";
                    }
                    everyButton->setFixedSize(pic.width()*0.5,pic.height()*0.5);
                    everyButton->setStyleSheet("QPushButton{border:0px;}");
                    everyButton->setIcon(pic);
                    everyButton->setIconSize(QSize(pic.width()*0.5,pic.height()*0.5));
//                    clickButtonExendNull(bombButtonInfo,everyButton,bombInfo,i,j);
                }
            });
        }
    }

}

//void MainWindow::clickButtonExendNull(ClickButton* bBI[LEVEL][LEVEL],ClickButton* eB,int bI[LEVEL+1][LEVEL+1],int i,int j)
//{

//    int nearBombNumber = bI[i][j]+bI[i+2][j+2]+bI[i][j+1]+bI[i+1][j+2]+bI[i+1][j]+bI[i][j+2]+bI[i+2][j]+bI[i+2][j+1];
//    if(nearBombNumber==0)
//    {
//        if(i<1)
//        {
//            if(j<1)
//            {
//                i=i+1;j=j+2;
//                MainWindow::clickButtonExendNull(bBI,eB,bI,i,j);
//                i=i+2;j=j+2;
//                MainWindow::clickButtonExendNull(bBI,eB,bI,i,j);
//                i=i+2;j=j+1;
//                MainWindow::clickButtonExendNull(bBI,eB,bI,i,j);
//            };
//            if(j>0&&j<LEVEL-1)
//            {
//                i=i+1;
//                MainWindow::clickButtonExendNull(bBI,eB,bI,i,j);
//                i=i+1;j=j+2;
//                MainWindow::clickButtonExendNull(bBI,eB,bI,i,j);
//                i=i+2;
//                MainWindow::clickButtonExendNull(bBI,eB,bI,i,j);
//                i=i+2;j=j+1;
//                MainWindow::clickButtonExendNull(bBI,eB,bI,i,j);
//                i=i+2;j=j+2;
//                MainWindow::clickButtonExendNull(bBI,eB,bI,i,j);
//            }
//            if(j>LEVEL-2)
//            {
//                i=i+1;
//                MainWindow::clickButtonExendNull(bBI,eB,bI,i,j);
//                i=i+2;
//                MainWindow::clickButtonExendNull(bBI,eB,bI,i,j);
//                i=i+2;j=j+1;
//                MainWindow::clickButtonExendNull(bBI,eB,bI,i,j);
//            }
//            else
//            {
//                QPixmap pic;
//                QString address = QString(":/images/0.jpg");
//                int ret = pic.load(address);
//                if(!ret)
//                {
//                    qDebug()<<"error!at 0.jpg  create main button;";
//                }
//                eB->setFixedSize(pic.width()*0.5,pic.height()*0.5);
//                eB->setStyleSheet("QPushButton{border:0px;}");
//                eB->setIcon(pic);
//                eB->setIconSize(QSize(pic.width()*0.5,pic.height()*0.5));
//            }
//        }
//        if(i>0&&i<LEVEL-1)
//        {
//            if(j<1)
//            {
//                j=j+1;
//                MainWindow::clickButtonExendNull(bBI,eB,bI,i,j);
//                j=j+2;
//                MainWindow::clickButtonExendNull(bBI,eB,bI,i,j);
//                i=i+1;j=j+2;
//                MainWindow::clickButtonExendNull(bBI,eB,bI,i,j);
//                i=i+2;j=j+2;
//                MainWindow::clickButtonExendNull(bBI,eB,bI,i,j);
//                i=i+2;j=j+1;
//                MainWindow::clickButtonExendNull(bBI,eB,bI,i,j);
//            }
//            if(j>0&&j<LEVEL-1)
//            {
//                MainWindow::clickButtonExendNull(bBI,eB,bI,i,j);
//                i=i+2;j=j+2;
//                MainWindow::clickButtonExendNull(bBI,eB,bI,i,j);
//                j=j+1;
//                MainWindow::clickButtonExendNull(bBI,eB,bI,i,j);
//                i=i+1;j=j+2;
//                MainWindow::clickButtonExendNull(bBI,eB,bI,i,j);
//                i=i+1;
//                MainWindow::clickButtonExendNull(bBI,eB,bI,i,j);
//                j=j+2;
//                MainWindow::clickButtonExendNull(bBI,eB,bI,i,j);
//                i=i+2;
//                MainWindow::clickButtonExendNull(bBI,eB,bI,i,j);
//                i=i+2;j=j+1;
//                MainWindow::clickButtonExendNull(bBI,eB,bI,i,j);
//            }
//            if(j>LEVEL-2)
//            {
//                MainWindow::clickButtonExendNull(bBI,eB,bI,i,j);
//                j=j+1;
//                MainWindow::clickButtonExendNull(bBI,eB,bI,i,j);
//                i=i+1;
//                MainWindow::clickButtonExendNull(bBI,eB,bI,i,j);
//                i=i+2;
//                MainWindow::clickButtonExendNull(bBI,eB,bI,i,j);
//                i=i+2;j=j+1;
//                MainWindow::clickButtonExendNull(bBI,eB,bI,i,j);
//            }
//            else
//            {
//                QPixmap pic;
//                QString address = QString(":/images/0.jpg");
//                int ret = pic.load(address);
//                if(!ret)
//                {
//                    qDebug()<<"error!at 0.jpg  create main button;";
//                }
//                eB->setFixedSize(pic.width()*0.5,pic.height()*0.5);
//                eB->setStyleSheet("QPushButton{border:0px;}");
//                eB->setIcon(pic);
//                eB->setIconSize(QSize(pic.width()*0.5,pic.height()*0.5));
//            }
//        }
//        if(i>LEVEL-2)
//        {
//            if(j<1)
//            {
//                j=j+1;
//                MainWindow::clickButtonExendNull(bBI,eB,bI,i,j);
//                j=j+2;
//                MainWindow::clickButtonExendNull(bBI,eB,bI,i,j);
//                i=i+1;j=j+2;
//                MainWindow::clickButtonExendNull(bBI,eB,bI,i,j);
//            }
//            if(j>0&&j<LEVEL-1)
//            {
//                MainWindow::clickButtonExendNull(bBI,eB,bI,i,j);
//                j=j+1;
//                MainWindow::clickButtonExendNull(bBI,eB,bI,i,j);
//                j=j+2;
//                MainWindow::clickButtonExendNull(bBI,eB,bI,i,j);
//                i=i+1;
//                MainWindow::clickButtonExendNull(bBI,eB,bI,i,j);
//                i=i+1;j=j+2;
//                MainWindow::clickButtonExendNull(bBI,eB,bI,i,j);
//            }
//            if(j>LEVEL-2)
//            {
//                MainWindow::clickButtonExendNull(bBI,eB,bI,i,j);
//                i=i+1;
//                MainWindow::clickButtonExendNull(bBI,eB,bI,i,j);
//                j=j+1;
//                MainWindow::clickButtonExendNull(bBI,eB,bI,i,j);
//            }
//            else
//            {
//                QPixmap pic;
//                QString address = QString(":/images/0.jpg");
//                int ret = pic.load(address);
//                if(!ret)
//                {
//                    qDebug()<<"error!at 0.jpg  create main button;";
//                }
//                eB->setFixedSize(pic.width()*0.5,pic.height()*0.5);
//                eB->setStyleSheet("QPushButton{border:0px;}");
//                eB->setIcon(pic);
//                eB->setIconSize(QSize(pic.width()*0.5,pic.height()*0.5));
//            }
//        }
//        else
//        {
//            QPixmap pic;
//            QString address = QString(":/images/0.jpg");
//            int ret = pic.load(address);
//            if(!ret)
//            {
//                qDebug()<<"error!at 0.jpg  create main button;";
//            }
//            eB->setFixedSize(pic.width()*0.5,pic.height()*0.5);
//            eB->setStyleSheet("QPushButton{border:0px;}");
//            eB->setIcon(pic);
//            eB->setIconSize(QSize(pic.width()*0.5,pic.height()*0.5));
//        }
//    }
//    else
//    {
//        QPixmap pic;
//        QString address = QString(":/images/%1.jpg").arg(nearBombNumber);
//        int ret = pic.load(address);
//        if(!ret)
//        {
//            qDebug()<<"error!at %1.jpg  create main button;";
//        }
//        eB->setFixedSize(pic.width()*0.5,pic.height()*0.5);
//        eB->setStyleSheet("QPushButton{border:0px;}");
//        eB->setIcon(pic);
//        eB->setIconSize(QSize(pic.width()*0.5,pic.height()*0.5));
//   }
//}

MainWindow::~MainWindow()
{
    delete ui;
}

