#include "node.h"
#include <QPainter>
#include <QDebug>

Node::Node(QGraphicsItem *parento, enum::NodeType typ, QPoint pos)
{
    setParentItem(parento);
    NodeType = typ;
    Wymiar = 13;
    setPos(pos);
    ConnectionLiniia = nullptr;
    ConnectedNode = nullptr;
    setNodeName("node");
}

void Node::addConnectionLine(ConnectionLine *linnia)
{
    ConnectionLiniia = linnia;
    if(NodeType == InputNode)
    {
        linnia->InputNodeConected = true;
    }
    else
    {
        linnia->OutputNodeConnected = true;
    }
    Occupied = true;
}

void Node::addConnectedNode(Node *node)
{
    ConnectedNode = node;
}

void Node::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPen dlugopis(QColor(58,48,73));
    dlugopis.setWidth(2);
    painter->setPen(dlugopis);
    painter->setBrush(QBrush(QColor(97,112,114)));

    painter->drawEllipse(-Wymiar/2,-Wymiar/2,Wymiar,Wymiar);
}

QRectF Node::boundingRect() const
{
    return QRectF(-Wymiar/2,-Wymiar/2,Wymiar,Wymiar);
}

void Node::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    //qDebug() << "Witam z node klikniete";
    //if(isOccupied() == false)
    emit NodeClickedSignal(this);
}

void Node::PanelPositionChangedUpdate()
{
    if(ConnectionLiniia == nullptr) return;

    if(NodeType == NodeType::OutputNode)
    {
       ConnectionLiniia->UpdateOutputNodePos(scenePos().toPoint());
    }
    else
    {
        ConnectionLiniia->UpdateInputNodePos(scenePos().toPoint());
    }

    ConnectionLiniia->update();
}

void Node::disconnectNode()
{
    ConnectionLiniia = nullptr;
    ConnectedNode = nullptr;
    Occupied = false;
}







