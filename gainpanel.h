#ifndef GAINPANEL_H
#define GAINPANEL_H

#include "panel.h"
#include <QGraphicsProxyWidget>

class GainPanel : public Panel
{
public:
    GainPanel(int x, int y);
    void initialize() override;

private:
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget = nullptr) override;

    Node *Input_node;
    Node *Output_node;
    QGraphicsProxyWidget *LineEdytor;
    int Gain;
};

#endif // GAINPANEL_H
