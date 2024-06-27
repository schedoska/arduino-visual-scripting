#ifndef PANELSTYLE_H
#define PANELSTYLE_H

#include <QPainter>
#include <QString>
#include <QFrame>

enum PanelStyleVariant{Blue, Red, Orange, Green};

class PanelStyle
{
public:
    PanelStyle();

    void setTitle(QString title) {Ttitle = title;}
    void setWariant(PanelStyleVariant wariant) {Wariant = wariant;}
    void setSize(int Szerokosc, int Wysokosc);
    QFont getFont() {return Czcionka;}

    void draw(QPainter *Malarz);

private:
    int Szerokosc, Wysokosc;
    QString Ttitle = "Panel";
    QFont Czcionka;
    PanelStyleVariant Wariant = PanelStyleVariant::Red;

    int Roundness = 10;
    int WysokoscPolaTytulu = 27;

    QFrame cien;
};

#endif // PANELSTYLE_H
