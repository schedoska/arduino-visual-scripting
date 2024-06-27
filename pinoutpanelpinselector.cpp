#include "pinoutpanelpinselector.h"
#include <QPainter>
#include <QtDebug>

PinOutPanelPinSelector::PinOutPanelPinSelector(QGraphicsItem *parento, PinSelectorValuesData *data, QPoint pos)
{
    setParentItem(parento);
    this->data = data;
    setPos(pos);

    QFont czcioneczka("chinese.msyh.ttf");
    Czcionka = czcioneczka;
    Czcionka.setPixelSize(9);

    Wysokosc_pola = 187;
    Szeroksc_pola = 84;

    Wysokosc_Kwadratu = 11;
    Szerokosc_Kwadratu = 12;

    initRectPositions(3,3,2);
}

void PinOutPanelPinSelector::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::NoPen);

    drawNotSelectedRects(painter);
    drawSelectedRects(painter);
    drawTexts(painter);
}

QRectF PinOutPanelPinSelector::boundingRect() const
{
    return QRectF(0,0,Szeroksc_pola,Wysokosc_pola);
}

void PinOutPanelPinSelector::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    checkRectClickEvent(event->pos().toPoint());
    event->ignore();
    update();
}

void PinOutPanelPinSelector::initRectPositions(int OdlegloscOdOX, int OdlegloscOdGory, int Sep)
{
    int OdlegloscOdosiX = OdlegloscOdOX;
    int Poczatekodgory = OdlegloscOdGory;
    int sep = Sep;

    PIN13.setRect(Szeroksc_pola/2+OdlegloscOdosiX,Poczatekodgory,Szerokosc_Kwadratu,Wysokosc_Kwadratu);
    PIN12.setRect(Szeroksc_pola/2+OdlegloscOdosiX,Poczatekodgory+1*(Wysokosc_Kwadratu+sep),Szerokosc_Kwadratu,Wysokosc_Kwadratu);
    PIN11.setRect(Szeroksc_pola/2+OdlegloscOdosiX,Poczatekodgory+2*(Wysokosc_Kwadratu+sep),Szerokosc_Kwadratu,Wysokosc_Kwadratu);
    PIN10.setRect(Szeroksc_pola/2+OdlegloscOdosiX,Poczatekodgory+3*(Wysokosc_Kwadratu+sep),Szerokosc_Kwadratu,Wysokosc_Kwadratu);
    PIN9.setRect(Szeroksc_pola/2+OdlegloscOdosiX,Poczatekodgory+4*(Wysokosc_Kwadratu+sep),Szerokosc_Kwadratu,Wysokosc_Kwadratu);
    PIN8.setRect(Szeroksc_pola/2+OdlegloscOdosiX,Poczatekodgory+5*(Wysokosc_Kwadratu+sep),Szerokosc_Kwadratu,Wysokosc_Kwadratu);
    PIN7.setRect(Szeroksc_pola/2+OdlegloscOdosiX,Poczatekodgory+6*(Wysokosc_Kwadratu+sep),Szerokosc_Kwadratu,Wysokosc_Kwadratu);
    PIN6.setRect(Szeroksc_pola/2+OdlegloscOdosiX,Poczatekodgory+7*(Wysokosc_Kwadratu+sep),Szerokosc_Kwadratu,Wysokosc_Kwadratu);
    PIN5.setRect(Szeroksc_pola/2+OdlegloscOdosiX,Poczatekodgory+8*(Wysokosc_Kwadratu+sep),Szerokosc_Kwadratu,Wysokosc_Kwadratu);
    PIN4.setRect(Szeroksc_pola/2+OdlegloscOdosiX,Poczatekodgory+9*(Wysokosc_Kwadratu+sep),Szerokosc_Kwadratu,Wysokosc_Kwadratu);
    PIN3.setRect(Szeroksc_pola/2+OdlegloscOdosiX,Poczatekodgory+10*(Wysokosc_Kwadratu+sep),Szerokosc_Kwadratu,Wysokosc_Kwadratu);
    PIN2.setRect(Szeroksc_pola/2+OdlegloscOdosiX,Poczatekodgory+11*(Wysokosc_Kwadratu+sep),Szerokosc_Kwadratu,Wysokosc_Kwadratu);
    PIN1.setRect(Szeroksc_pola/2+OdlegloscOdosiX,Poczatekodgory+12*(Wysokosc_Kwadratu+sep),Szerokosc_Kwadratu,Wysokosc_Kwadratu);
    PIN0.setRect(Szeroksc_pola/2+OdlegloscOdosiX,Poczatekodgory+13*(Wysokosc_Kwadratu+sep),Szerokosc_Kwadratu,Wysokosc_Kwadratu);

    PINA0.setRect(Szeroksc_pola/2-OdlegloscOdosiX-Szerokosc_Kwadratu,Poczatekodgory+8*(Wysokosc_Kwadratu+sep),
                  Szerokosc_Kwadratu,Wysokosc_Kwadratu);
    PINA1.setRect(Szeroksc_pola/2-OdlegloscOdosiX-Szerokosc_Kwadratu,Poczatekodgory+9*(Wysokosc_Kwadratu+sep),
                  Szerokosc_Kwadratu,Wysokosc_Kwadratu);
    PINA2.setRect(Szeroksc_pola/2-OdlegloscOdosiX-Szerokosc_Kwadratu,Poczatekodgory+10*(Wysokosc_Kwadratu+sep),
                  Szerokosc_Kwadratu,Wysokosc_Kwadratu);
    PINA3.setRect(Szeroksc_pola/2-OdlegloscOdosiX-Szerokosc_Kwadratu,Poczatekodgory+11*(Wysokosc_Kwadratu+sep),
                  Szerokosc_Kwadratu,Wysokosc_Kwadratu);
    PINA4.setRect(Szeroksc_pola/2-OdlegloscOdosiX-Szerokosc_Kwadratu,Poczatekodgory+12*(Wysokosc_Kwadratu+sep),
                  Szerokosc_Kwadratu,Wysokosc_Kwadratu);
    PINA5.setRect(Szeroksc_pola/2-OdlegloscOdosiX-Szerokosc_Kwadratu,Poczatekodgory+13*(Wysokosc_Kwadratu+sep),
                  Szerokosc_Kwadratu,Wysokosc_Kwadratu);
}

void PinOutPanelPinSelector::checkRectClickEvent(QPoint mousePos)
{
    if(PIN0.contains(mousePos)) data->PIN0 = !data->PIN0;
    if(PIN1.contains(mousePos)) data->PIN1 = !data->PIN1;
    if(PIN2.contains(mousePos)) data->PIN2 = !data->PIN2;
    if(PIN3.contains(mousePos)) data->PIN3 = !data->PIN3;
    if(PIN4.contains(mousePos)) data->PIN4 = !data->PIN4;
    if(PIN5.contains(mousePos)) data->PIN5 = !data->PIN5;
    if(PIN6.contains(mousePos)) data->PIN6 = !data->PIN6;
    if(PIN7.contains(mousePos)) data->PIN7 = !data->PIN7;
    if(PIN8.contains(mousePos)) data->PIN8 = !data->PIN8;
    if(PIN9.contains(mousePos)) data->PIN9 = !data->PIN9;
    if(PIN10.contains(mousePos)) data->PIN10 = !data->PIN10;
    if(PIN11.contains(mousePos)) data->PIN11 = !data->PIN11;
    if(PIN12.contains(mousePos)) data->PIN12 = !data->PIN12;
    if(PIN13.contains(mousePos)) data->PIN13 = !data->PIN13;

    if(PINA0.contains(mousePos)) data->PINA0 = !data->PINA0;
    if(PINA1.contains(mousePos)) data->PINA1 = !data->PINA1;
    if(PINA2.contains(mousePos)) data->PINA2 = !data->PINA2;
    if(PINA3.contains(mousePos)) data->PINA3 = !data->PINA3;
    if(PINA4.contains(mousePos)) data->PINA4 = !data->PINA4;
    if(PINA5.contains(mousePos)) data->PINA5 = !data->PINA5;
}

void PinOutPanelPinSelector::drawSelectedRects(QPainter *painter)
{
    painter->setBrush(QBrush(QColor(103,203,106)));
    if(data->PIN0) painter->drawRect(PIN0);
    if(data->PIN1) painter->drawRect(PIN1);
    if(data->PIN2) painter->drawRect(PIN2);
    if(data->PIN3) painter->drawRect(PIN3);
    if(data->PIN4) painter->drawRect(PIN4);
    if(data->PIN5) painter->drawRect(PIN5);
    if(data->PIN6) painter->drawRect(PIN6);
    if(data->PIN7) painter->drawRect(PIN7);
    if(data->PIN8) painter->drawRect(PIN8);
    if(data->PIN9) painter->drawRect(PIN9);
    if(data->PIN10) painter->drawRect(PIN10);
    if(data->PIN11) painter->drawRect(PIN11);
    if(data->PIN12) painter->drawRect(PIN12);
    if(data->PIN13) painter->drawRect(PIN13);

    if(data->PINA0) painter->drawRect(PINA0);
    if(data->PINA1) painter->drawRect(PINA1);
    if(data->PINA2) painter->drawRect(PINA2);
    if(data->PINA3) painter->drawRect(PINA3);
    if(data->PINA4) painter->drawRect(PINA4);
    if(data->PINA5) painter->drawRect(PINA5);
}

void PinOutPanelPinSelector::drawNotSelectedRects(QPainter *painter)
{
    painter->setBrush(QBrush(QColor(127,127,127)));
    if(!data->PIN13) painter->drawRect(PIN13);
    if(!data->PIN12) painter->drawRect(PIN12);
    if(!data->PIN11) painter->drawRect(PIN11);
    if(!data->PIN10) painter->drawRect(PIN10);
    if(!data->PIN9) painter->drawRect(PIN9);
    if(!data->PIN8) painter->drawRect(PIN8);
    if(!data->PIN7) painter->drawRect(PIN7);
    if(!data->PIN6) painter->drawRect(PIN6);
    if(!data->PIN5) painter->drawRect(PIN5);
    if(!data->PIN4) painter->drawRect(PIN4);
    if(!data->PIN3) painter->drawRect(PIN3);
    if(!data->PIN2) painter->drawRect(PIN2);
    if(!data->PIN1) painter->drawRect(PIN1);
    if(!data->PIN0) painter->drawRect(PIN0);

    if(!data->PINA0) painter->drawRect(PINA0);
    if(!data->PINA1) painter->drawRect(PINA1);
    if(!data->PINA2) painter->drawRect(PINA2);
    if(!data->PINA3) painter->drawRect(PINA3);
    if(!data->PINA4) painter->drawRect(PINA4);
    if(!data->PINA5) painter->drawRect(PINA5);
}

void PinOutPanelPinSelector::drawTexts(QPainter *painter)
{
    painter->setRenderHint(QPainter::TextAntialiasing);

    int Dis_to_sqr = 6;

    painter->setPen(QPen(Qt::white));
    painter->setFont(Czcionka);
    painter->drawText(PIN0.center()+QPoint(Szerokosc_Kwadratu/2+Dis_to_sqr,Wysokosc_Kwadratu/2),"00");
    painter->drawText(PIN1.center()+QPoint(Szerokosc_Kwadratu/2+Dis_to_sqr,Wysokosc_Kwadratu/2),"01");
    painter->drawText(PIN2.center()+QPoint(Szerokosc_Kwadratu/2+Dis_to_sqr,Wysokosc_Kwadratu/2),"02");
    painter->drawText(PIN3.center()+QPoint(Szerokosc_Kwadratu/2+Dis_to_sqr,Wysokosc_Kwadratu/2),"03");
    painter->drawText(PIN4.center()+QPoint(Szerokosc_Kwadratu/2+Dis_to_sqr,Wysokosc_Kwadratu/2),"04");
    painter->drawText(PIN5.center()+QPoint(Szerokosc_Kwadratu/2+Dis_to_sqr,Wysokosc_Kwadratu/2),"05");
    painter->drawText(PIN6.center()+QPoint(Szerokosc_Kwadratu/2+Dis_to_sqr,Wysokosc_Kwadratu/2),"06");
    painter->drawText(PIN7.center()+QPoint(Szerokosc_Kwadratu/2+Dis_to_sqr,Wysokosc_Kwadratu/2),"07");
    painter->drawText(PIN8.center()+QPoint(Szerokosc_Kwadratu/2+Dis_to_sqr,Wysokosc_Kwadratu/2),"08");
    painter->drawText(PIN9.center()+QPoint(Szerokosc_Kwadratu/2+Dis_to_sqr,Wysokosc_Kwadratu/2),"09");
    painter->drawText(PIN10.center()+QPoint(Szerokosc_Kwadratu/2+Dis_to_sqr,Wysokosc_Kwadratu/2),"10");
    painter->drawText(PIN11.center()+QPoint(Szerokosc_Kwadratu/2+Dis_to_sqr,Wysokosc_Kwadratu/2),"11");
    painter->drawText(PIN12.center()+QPoint(Szerokosc_Kwadratu/2+Dis_to_sqr,Wysokosc_Kwadratu/2),"12");
    painter->drawText(PIN13.center()+QPoint(Szerokosc_Kwadratu/2+Dis_to_sqr,Wysokosc_Kwadratu/2),"13");

    Dis_to_sqr = 16;

    painter->drawText(PINA0.center()-QPoint(Szerokosc_Kwadratu/2+Dis_to_sqr,-Wysokosc_Kwadratu/2),"A0");
    painter->drawText(PINA1.center()-QPoint(Szerokosc_Kwadratu/2+Dis_to_sqr,-Wysokosc_Kwadratu/2),"A1");
    painter->drawText(PINA2.center()-QPoint(Szerokosc_Kwadratu/2+Dis_to_sqr,-Wysokosc_Kwadratu/2),"A2");
    painter->drawText(PINA3.center()-QPoint(Szerokosc_Kwadratu/2+Dis_to_sqr,-Wysokosc_Kwadratu/2),"A3");
    painter->drawText(PINA4.center()-QPoint(Szerokosc_Kwadratu/2+Dis_to_sqr,-Wysokosc_Kwadratu/2),"A4");
    painter->drawText(PINA5.center()-QPoint(Szerokosc_Kwadratu/2+Dis_to_sqr,-Wysokosc_Kwadratu/2),"A5");
}











