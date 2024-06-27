#ifndef PINOUTPANELPINSELECTOR_H
#define PINOUTPANELPINSELECTOR_H

#include <QGraphicsObject>
#include <QGraphicsSceneMouseEvent>
#include <QFont>

struct PinSelectorValuesData
{
    bool PINA0 = false;
    bool PINA1 = false;
    bool PINA2 = false;
    bool PINA3 = false;
    bool PINA4 = false;
    bool PINA5 = false;

    bool PIN0 = false;
    bool PIN1 = false;
    bool PIN2 = false;
    bool PIN3 = false;
    bool PIN4 = false;
    bool PIN5 = false;
    bool PIN6 = false;
    bool PIN7 = false;
    bool PIN8 = false;
    bool PIN9 = false;
    bool PIN10 = false;
    bool PIN11 = false;
    bool PIN12 = false;
    bool PIN13 = false;
};

class PinOutPanelPinSelector : public QGraphicsObject
{
public:
    PinOutPanelPinSelector(QGraphicsItem *parento, PinSelectorValuesData *data, QPoint pos);

private:
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget = nullptr) override;
    QRectF boundingRect() const override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

    void initRectPositions(int OdlegloscOdOX,int OdlegloscOdGory, int Sep);
    void checkRectClickEvent(QPoint mousePos);

    void drawSelectedRects(QPainter *painter);
    void drawNotSelectedRects(QPainter *painter);
    void drawTexts(QPainter *painter);

    PinSelectorValuesData *data;
    int Wysokosc_pola;
    int Szeroksc_pola;
    int Wysokosc_Kwadratu;
    int Szerokosc_Kwadratu;

    QFont Czcionka;

    QRect PIN13;
    QRect PIN12;
    QRect PIN11;
    QRect PIN10;
    QRect PIN9;
    QRect PIN8;
    QRect PIN7;
    QRect PIN6;
    QRect PIN5;
    QRect PIN4;
    QRect PIN3;
    QRect PIN2;
    QRect PIN1;
    QRect PIN0;

    QRect PINA0;
    QRect PINA1;
    QRect PINA2;
    QRect PINA3;
    QRect PINA4;
    QRect PINA5;
};

#endif // PINOUTPANELPINSELECTOR_H
