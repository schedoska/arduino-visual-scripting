#ifndef PININPUTPANEL_H
#define PININPUTPANEL_H

#include <panel.h>
#include <pinoutpanelpinselector.h>

class PinInputPanel : public Panel
{
public:
    PinInputPanel(int x, int y);
    void setPinValuesData(PinSelectorValuesData data);
    PinSelectorValuesData getValuesData();

private:
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget = nullptr) override;

    Node *OutputNode_ReadIfSelectedHigh;
    Node *OutputNode_ReadIfSelectedLow;

    PinSelectorValuesData PinSelectorData;
    PinOutPanelPinSelector *SelectorArea;
};

#endif // PININPUTPANEL_H
