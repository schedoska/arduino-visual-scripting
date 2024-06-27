#include "muxpnael.h"
#include <QGraphicsScene>

#define SZEROKOSC_PANELU 70
#define WYSOKOSC_PANELU 100
#define OFFSET 20
#define WYSOKOSC_BTN 17
#define SZEROKOSC_BTN 50

MuxPnael::MuxPnael(int x, int y)
    : Panel(SZEROKOSC_PANELU,100)
{
    setPos(x,y);
    setColorVariant(PanelStyleVariant::Blue);
    setTitle("OR Gate");

    x_pos = SZEROKOSC_PANELU/2-SZEROKOSC_BTN/2;
    Wysokosc = 96;
    NumberOfSlots = 0;

    SingleOutputNode = new Node(this, NodeType::OutputNode, QPoint(13,20));
    AddNode(SingleOutputNode);
}

void MuxPnael::initialize()
{
    AddBtn = new QPushButton("+");
    AddBtn->setMinimumSize(10,10);
    AddBtn->setStyleSheet("border: double; background-color: rgb(100,100,100);"
                          " font-size: 19; color: white; outline; outline-radius: 4;"
                          "icon: cd-icon; border-width: 2; border-color: rgb(130,130,130);");
    connect(AddBtn, &QPushButton::pressed, this, &MuxPnael::addInputNode);
    AddSlotButton = scene()->addWidget(AddBtn);
    AddSlotButton->setParentItem(this);
    AddSlotButton->setGeometry(
                QRectF(x_pos, 50, SZEROKOSC_BTN, WYSOKOSC_BTN));

    RemoveBtn = new QPushButton("-");
    RemoveBtn->setMinimumSize(10,10);
    RemoveBtn->setStyleSheet("border: double; background-color: rgb(100,100,100);"
                             " font-size: 19; color: white; outline; outline-radius: 4;"
                             "icon: cd-icon; border-width: 2; border-color: rgb(130,130,130);");
    connect(RemoveBtn, &QPushButton::pressed, this, &MuxPnael::removeInputNode);
    RemoveSlotButton = scene()->addWidget(RemoveBtn);
    RemoveSlotButton->setParentItem(this);
    RemoveSlotButton->setGeometry(
                QRectF(x_pos, 80, SZEROKOSC_BTN, WYSOKOSC_BTN));

    addInputNode();
    addInputNode();
}

void MuxPnael::UpdateButtonsAndNodePos()
{
    AddSlotButton->setPos(x_pos, NumberOfSlots * 16 + 38);
    if(NumberOfSlots > 6) AddBtn->setDisabled(true);
    else AddBtn->setEnabled(true);

    RemoveSlotButton->setPos(x_pos, NumberOfSlots * 16 + WYSOKOSC_BTN + 41);
    if(NumberOfSlots == 2) RemoveBtn->setDisabled(true);
    else RemoveBtn->setEnabled(true);

    SingleOutputNode->setPos(SZEROKOSC_PANELU - 13, 39 + (NumberOfSlots - 1) * 8);
}

void MuxPnael::addInputNode()
{
    Node *Input_node = new Node(this, NodeType::InputNode, QPoint(13, NumberOfSlots * 16 + 39));
    ListOfInputNodes.append(Input_node);
    AddNode(Input_node);
    NumberOfSlots ++;
    Wysokosc += 16;

    UpdateButtonsAndNodePos();
    UpdateSize(SZEROKOSC_PANELU,Wysokosc);
    UpdateNodesPosition();
}

void MuxPnael::removeInputNode()
{
    Node *Do_usuniecia = ListOfInputNodes.takeLast();
    DeleteNode(Do_usuniecia);
    ListOfInputNodes.removeOne(Do_usuniecia);
    NumberOfSlots --;
    Wysokosc -= 16;

    UpdateButtonsAndNodePos();
    UpdateSize(SZEROKOSC_PANELU,Wysokosc);
    UpdateNodesPosition();
}












