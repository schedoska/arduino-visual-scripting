#ifndef SHADOW_H
#define SHADOW_H

#include <QWidget>

class TopShadow : public QWidget
{
public:
    TopShadow(QWidget *parent, int width, int height);
    void paintEvent(QPaintEvent *event) override;

    void UpdateWidth(int Width);

private:
    int Szerokosc = 100;
    int Wysokosc = 100;
};

#endif // SHADOW_H
