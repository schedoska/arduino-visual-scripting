#ifndef MUXPNAEL_H
#define MUXPNAEL_H

#include <QPushButton>
#include <QGraphicsProxyWidget>
#include "panel.h"

class MuxPnael : public Panel
{
    Q_OBJECT
public:
    MuxPnael(int x, int y);
    int Wysokosc;
    void initialize() override;

private:
    QPushButton *AddBtn;
    QPushButton *RemoveBtn;
    QGraphicsProxyWidget *AddSlotButton;
    QGraphicsProxyWidget *RemoveSlotButton;

    int x_pos;

    unsigned NumberOfSlots;
    void UpdateButtonsAndNodePos();

    Node *SingleOutputNode;
    QList<Node*> ListOfInputNodes;

public slots:
    void addInputNode();
    void removeInputNode();
};

#endif // MUXPNAEL_H
