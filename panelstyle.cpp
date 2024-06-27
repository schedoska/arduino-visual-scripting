#include "panelstyle.h"
#include <QDebug>

PanelStyle::PanelStyle()
{
    QFont czcioneczka("chinese.msyh.ttf");
    Czcionka = czcioneczka;
    Czcionka.setPixelSize(13);
}

void PanelStyle::setSize(int Szerokosc, int Wysokosc)
{
    this->Szerokosc = Szerokosc;
    this->Wysokosc = Wysokosc;
}

void PanelStyle::draw(QPainter *Malarz)
{
    Malarz->setPen(Qt::NoPen);

    Malarz->setBrush(QBrush(QColor(69,64,76)));
    Malarz->drawRoundedRect(QRect(0,0,Szerokosc,Wysokosc),Roundness,Roundness);

    switch(Wariant)
    {
        case PanelStyleVariant::Green:
            Malarz->setBrush(QBrush(QColor(82,191,84)));
            break;

        case PanelStyleVariant::Blue:
            Malarz->setBrush(QBrush(QColor(50,103,190)));
            break;

        case PanelStyleVariant::Orange:
            Malarz->setBrush(QBrush(QColor(255,137,94)));
            break;

        case PanelStyleVariant::Red:
            Malarz->setBrush(QBrush(QColor(255,58,71)));
            break;
    }

    //Gorny Pasek
    Malarz->drawRoundedRect(QRect(0,0,Szerokosc,WysokoscPolaTytulu),Roundness,Roundness);
    Malarz->drawRect(0,Roundness,Szerokosc,WysokoscPolaTytulu-Roundness);

    //Dolny Pasek
    Malarz->drawRoundedRect(QRect(0,Wysokosc-13,Szerokosc,3),2,2);

    Malarz->setFont(Czcionka);
    Malarz->setPen(Qt::white);
    Malarz->drawText(7,20,Ttitle);
}

