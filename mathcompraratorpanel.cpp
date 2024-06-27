#include "mathcompraratorpanel.h"
#include <QGraphicsScene>
#include <QDebug>
#include <Panels_data/comparatorpaneldata.h>

#define SZEROKOSC_PANELU 160
#define WYSOKOSC_PANELU 88

#define INPUTA_NAME "InputNodeA"
#define INPUTB_NAME "InputNodeB"
#define OUTPUT_NAME "OutputNode"

MathCompraratorPanel::MathCompraratorPanel(int x, int y)
    : Panel(SZEROKOSC_PANELU, WYSOKOSC_PANELU)
{
    setPos(x,y);
    setColorVariant(PanelStyleVariant::Orange);
    setTitle("Comparator");

    InputNode_A = new Node(this, NodeType::InputNode, QPoint(13,39));
    AddNode(InputNode_A);

    InputNode_B = new Node(this, NodeType::InputNode, QPoint(13,62));
    AddNode(InputNode_B);

    OutputNode = new Node(this, NodeType::OutputNode, QPoint(SZEROKOSC_PANELU - 13, 51));
    AddNode(OutputNode);

    modeCounter = 1;
    updateComparatorMode();
}

void MathCompraratorPanel::initialize()
{
    setNodesNames();

    CompareButton = new QPushButton("=");
    CompareButton->setStyleSheet("background-color: rgb(90,90,90); border: none; "
                                 "font-size: 15; color: white");
    CompareButton->setMinimumSize(QSize(10,10));
    CompareButton->setGeometry(78,37,25,25);
    connect(CompareButton, &QPushButton::pressed, this, &MathCompraratorPanel::changeComparatorMode);

    CompBtn = scene()->addWidget(CompareButton);
    CompBtn->setParentItem(this);

    updateButtonText();
}

void MathCompraratorPanel::setComparatorMode(uint modeCount)
{
    modeCounter = modeCount;
    updateComparatorMode();
}

uint MathCompraratorPanel::getModeCount()
{
    return modeCounter;
}

void MathCompraratorPanel::SavePanelToFile(QFile *plik)
{
    ComparatorPanelData::SaveToFile(this, plik);
}

void MathCompraratorPanel::setNodesNames()
{
    InputNode_A->setNodeName(ComparatorPanelData::GetPanelSubName() +
                             "_" + INPUTA_NAME + "_" +
                             QString::number(getIndex()));
    //------------------------------------------------------------------
    InputNode_B->setNodeName(ComparatorPanelData::GetPanelSubName() +
                             "_" + INPUTB_NAME + "_" +
                             QString::number(getIndex()));
    //------------------------------------------------------------------
    OutputNode->setNodeName(ComparatorPanelData::GetPanelSubName() +
                            "_" + OUTPUT_NAME + "_" +
                            QString::number(getIndex()));
}

void MathCompraratorPanel::updateComparatorMode()
{
    if(modeCounter == 0) mode = ComparatorMode::AbiggerThenB;
    if(modeCounter == 1) mode = ComparatorMode::AequalToB;
    if(modeCounter == 2) mode = ComparatorMode::AsmallerThenB;
}

void MathCompraratorPanel::updateButtonText()
{
    switch (mode)
    {
    case ComparatorMode::AbiggerThenB:
        CompareButton->setText(">");
        break;
    case ComparatorMode::AequalToB:
        CompareButton->setText("=");
        break;
    case ComparatorMode::AsmallerThenB:
        CompareButton->setText("<");
        break;
    }
}

void MathCompraratorPanel::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Panel::paint(painter,option,widget);

    QFont Czcionka = getFont();
    Czcionka.setPixelSize(12);

    painter->setPen(Qt::white);
    painter->setBrush(QBrush(Qt::white));
    painter->setFont(Czcionka);

    painter->drawText(InputNode_A->pos() + QPoint(12,5), "A");
    painter->drawText(InputNode_B->pos() + QPoint(12,5), "B");
    painter->drawText(50,55,"if  A");
    painter->drawText(115,55,"B");
}

void MathCompraratorPanel::changeComparatorMode()
{
    modeCounter ++;
    if(modeCounter > 2)
    {
        modeCounter = 0;
    }
    updateComparatorMode();
    updateButtonText();
}








