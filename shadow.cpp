#include "shadow.h"
#include <QDebug>
#include <QPainter>

TopShadow::TopShadow(QWidget *parent, int width, int height)
{
    setParent(parent);
    Szerokosc = width;
    Wysokosc = height;

    setEnabled(false);
    setAttribute(Qt::WA_TransparentForMouseEvents);
    setGeometry(0,0,Szerokosc, Wysokosc);
}

void TopShadow::paintEvent(QPaintEvent *event)
{
    int Black_shade = 50;
    int Start_Transparency = 150;
    QPainter AustriackiMalarz(this);

    QLinearGradient gradientCien(0,0,0,Wysokosc);
    gradientCien.setColorAt(0,QColor(Black_shade,Black_shade,Black_shade,Start_Transparency));
    gradientCien.setColorAt(1,QColor(0,0,0,0));

    QBrush pedzel(gradientCien);
    AustriackiMalarz.setBrush(pedzel);
    AustriackiMalarz.setPen(Qt::NoPen);

    AustriackiMalarz.drawRect(0,0,Szerokosc,Wysokosc);
}

void TopShadow::UpdateWidth(int Width)
{
    Szerokosc = Width;
    setGeometry(0,0,Szerokosc, Wysokosc);
    update();
}
