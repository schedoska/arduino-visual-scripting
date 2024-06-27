#ifndef PINOUTPUTPANEL_H
#define PINOUTPUTPANEL_H

#include <panel.h>
#include "pinoutpanelpinselector.h"

class PinOutputPanel : public Panel
{
public:
    PinOutputPanel(int x, int y);
    void setPinValuesData(PinSelectorValuesData data);
    PinSelectorValuesData getValuesData();
    void SavePanelToFile(QFile *plik) override;
    void initialize() override;

private:
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget = nullptr) override;

    Node *InputNode_SetSelectedHigh;
    Node *InputNode_SetSelectedLow;

    PinSelectorValuesData PinSelectorData;
    PinOutPanelPinSelector *SelectorArea;
};

#endif // PINOUTPUTPANEL_H
