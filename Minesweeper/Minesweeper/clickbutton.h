#ifndef CLICKBUTTON_H
#define CLICKBUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QPixmap>
#include <QDebug>
#include <QMouseEvent>

class ClickButton : public QPushButton
{
    Q_OBJECT
public:
    explicit ClickButton(QWidget *parent = nullptr);
//    void mousePressEvent(QMouseEvent *e);
    void changeStateInfo();
private:
    bool stateInfo = false;//是否点到炸弹
signals:

public slots:
};

#endif // CLICKBUTTON_H
