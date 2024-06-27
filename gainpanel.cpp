#include "gainpanel.h"
#include <QLineEdit>
#include <QGraphicsScene>
#include <QDebug>
#include <QDoubleValidator>

#define SZEROKOSC_PANELU 125
#define WYSOKOSC_PANELU 85

GainPanel::GainPanel(int x, int y)
    : Panel(SZEROKOSC_PANELU,WYSOKOSC_PANELU)
{
    setPos(x, y);
    setTitle("Gain");
    setColorVariant(PanelStyleVariant::Orange);

    Input_node = new Node(this, NodeType::InputNode, QPoint(13,WYSOKOSC_PANELU/2+7));
    AddNode(Input_node);

    Output_node = new Node(this, NodeType::OutputNode, QPoint(SZEROKOSC_PANELU-13,WYSOKOSC_PANELU/2+7));
    AddNode(Output_node);

    Gain = 1;
}

void GainPanel::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Panel::paint(painter,option,widget);
}

void GainPanel::initialize()
{
    QFont czcioneczka("chinese.msyh.ttf");
    czcioneczka.setPixelSize(11);

    QLineEdit *edytor = new QLineEdit;
    edytor->setGeometry(300,300,100,30);
    edytor->setMaxLength(6);
    edytor->setAlignment(Qt::AlignCenter);
    edytor->setFrame(1);
    edytor->setFont(czcioneczka);
    edytor->setStyleSheet("color: white; background-color: rgb(107,107,107)");
    edytor->setValidator(new QDoubleValidator(-10000,10000,3));
    LineEdytor = scene()->addWidget(edytor);
    LineEdytor->setParentItem(this);
    LineEdytor->setGeometry(QRect(30,Input_node->pos().y() - 9,20,18));
}










