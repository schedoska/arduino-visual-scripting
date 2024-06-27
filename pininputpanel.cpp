#include "pininputpanel.h"

PinInputPanel::PinInputPanel(int x, int y)
    : Panel(100,270)
{
    setColorVariant(PanelStyleVariant::Green);
    setTitle("Input");
    setPos(x,y);

    OutputNode_ReadIfSelectedHigh = new Node(this, NodeType::OutputNode, QPoint(87,228));
    AddNode(OutputNode_ReadIfSelectedHigh);

    OutputNode_ReadIfSelectedLow = new Node(this, NodeType::OutputNode, QPoint(87,244));
    AddNode(OutputNode_ReadIfSelectedLow);

    SelectorArea = new PinOutPanelPinSelector(this, &PinSelectorData, QPoint(8,30));
}

void PinInputPanel::setPinValuesData(PinSelectorValuesData data)
{
    PinSelectorData = data;
    SelectorArea->update();
}

PinSelectorValuesData PinInputPanel::getValuesData()
{
    return PinSelectorData;
}

void PinInputPanel::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::white);
    QFont czcionka(getFont());
    czcionka.setPixelSize(11);

    Panel::paint(painter,option,widget);
    painter->setRenderHint(QPainter::TextAntialiasing);
    painter->setFont(czcionka);
    painter->drawText(20,232,"Read if high");
    painter->drawText(20,248,"Read if low");
}
