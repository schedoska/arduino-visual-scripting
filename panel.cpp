#include "panel.h"
#include <QBrush>
#include <QLinearGradient>
#include <QPainter>
#include <QDebug>
#include <QGraphicsScene>
#include <QMenu>

Panel::Panel(int Szerokosc, int Wysokosc)
{
    this->Szerokosc = Szerokosc;
    this->Wysokosc = Wysokosc;
    Styl.setSize(Szerokosc,Wysokosc);

    setFlag(QGraphicsItem::ItemIsMovable);

    Czasomierz.setSingleShot(true);
    Czasomierz.start(100);
}

QList<Node *> &Panel::getOutputNodes()
{
    return ListaOutputNodes;
}

QList<Node *> &Panel::getInputNodes()
{
    return ListaInputNodes;
}

void Panel::AddNode(Node *node)
{
    if(node->NodeType == NodeType::InputNode)
    {
        getInputNodes().push_back(node);
    }
    else
    {
        getOutputNodes().push_back(node);
    }
    connect(node, &Node::NodeClickedSignal, this, &Panel::NodeClickedSignalReciver);
}

void Panel::DeleteNode(Node *node)
{
    if(node->NodeType == NodeType::InputNode)
    {
        getInputNodes().removeOne(node);
    }
    else
    {
        getOutputNodes().removeOne(node);
    }
    emit NodeDeleteRequest(node);
}

void Panel::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Styl.draw(painter);
}

QFont Panel::getFont()
{
    return Styl.getFont();
}

void Panel::setTitle(QString PanelName)
{
    Styl.setTitle(PanelName);
}

void Panel::setColorVariant(PanelStyleVariant wariant)
{
    Styl.setWariant(wariant);
}

void Panel::UpdateSize(int Szerokosc, int Wysokosc)
{
    this->Szerokosc = Szerokosc;
    this->Wysokosc = Wysokosc;
    Styl.setSize(Szerokosc,Wysokosc);

    prepareGeometryChange();
    update();
}

void Panel::initialize()
{
    return;
}

void Panel::SavePanelToFile(QFile *plik)
{
    return;
}

void Panel::SaveNodeConnectionsToFile(QFile *plik)
{
    QTextStream stream(plik);

    foreach(Node *node, getInputNodes())
    {
        if(!node->isOccupied()) continue;

        stream << "$\nnode connection:\n";
        stream << node->getNodeName() << ' '
        << node->getConnectedNode()->getNodeName()
        << '\n';
    }
}

QRectF Panel::boundingRect() const
{
    return QRectF(0,0,Szerokosc,Wysokosc);
}

void Panel::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    UpdateNodesPosition();
    QGraphicsItem::mouseMoveEvent(event);
}

void Panel::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{
    if(Czasomierz.isActive()) return;

    QMenu *meni = new QMenu;
    QAction *Delete = new QAction("Delete",this);
    meni->addAction(Delete);
    connect(Delete, &QAction::triggered, this ,&Panel::Delete);
    meni->exec(event->screenPos());
}

void Panel::UpdateNodesPosition()
{
    for(int q = 0; q < ListaInputNodes.length(); q++)
    {
        ListaInputNodes.at(q)->PanelPositionChangedUpdate();
    }
    for(int q = 0; q < ListaOutputNodes.length(); q++)
    {
        ListaOutputNodes.at(q)->PanelPositionChangedUpdate();
    }
}

void Panel::setIndex(uint index)
{
    this->index = index;
}

uint Panel::getIndex()
{
    return index;
}

void Panel::NodeClickedSignalReciver(Node *node)
{
    //qDebug() << "Node clicked hello from panel" << node;
    emit NodeClickedSignalSender(node);
}

void Panel::Delete()
{
    emit DeleteRequest(this);
}

