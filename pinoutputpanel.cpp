#include "pinoutputpanel.h"
#include <QDebug>
#include <Panels_data/pinoutputpaneldata.h>

#define INSELHI_NAME "InputSelectedHigh"
#define INSELLO_NAME "InputSelectedLow"

PinOutputPanel::PinOutputPanel(int x, int y)
    : Panel(100,270)
{
    setColorVariant(PanelStyleVariant::Red);
    setTitle("Output");
    setPos(x,y);

    InputNode_SetSelectedHigh = new Node(this, NodeType::InputNode, QPoint(13,228));

    AddNode(InputNode_SetSelectedHigh);

    InputNode_SetSelectedLow = new Node(this, NodeType::InputNode, QPoint(13,244));
    AddNode(InputNode_SetSelectedLow);

    SelectorArea = new PinOutPanelPinSelector(this, &PinSelectorData, QPoint(8,30));
}

void PinOutputPanel::setPinValuesData(PinSelectorValuesData data)
{
    PinSelectorData = data;
    SelectorArea->update();
}

PinSelectorValuesData PinOutputPanel::getValuesData()
{
    return PinSelectorData;
}

void PinOutputPanel::SavePanelToFile(QFile *plik)
{
    PinOutputPanelData::SaveToFile(this, plik);
}

void PinOutputPanel::initialize()
{
    InputNode_SetSelectedHigh->setNodeName  (PinOutputPanelData::GetPanelSubName() +
                                            "_" + INSELHI_NAME + "_" +
                                             QString::number(getIndex()));
    //----------------------------------------------------------------------------------
    InputNode_SetSelectedLow->setNodeName   (PinOutputPanelData::GetPanelSubName() +
                                            "_" + INSELLO_NAME + "_" +
                                             QString::number(getIndex()));
}

void PinOutputPanel::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::white);
    QFont czcionka(getFont());
    czcionka.setPixelSize(11);

    Panel::paint(painter,option,widget);
    painter->setRenderHint(QPainter::TextAntialiasing);
    painter->setFont(czcionka);
    painter->drawText(24,232,"Set high");
    painter->drawText(24,248,"Set low");
}
