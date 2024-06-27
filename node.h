#ifndef NODE_H
#define NODE_H

#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include "connectionline.h"

enum NodeType{InputNode, OutputNode};

class Node: public QGraphicsObject
{
    Q_OBJECT
public:
    Node(QGraphicsItem *parento, NodeType typ, QPoint pos);
    void addConnectionLine(ConnectionLine *linnia);
    void addConnectedNode(Node *node);
    void PanelPositionChangedUpdate();
    void disconnectNode();

    bool isOccupied()                   {return Occupied;}
    Node *getConnectedNode()            {return ConnectedNode;}
    ConnectionLine *getConnectedLine()  {return ConnectionLiniia;}
    QString getNodeName()               {return NodeName;}
    void setNodeName(QString Name)      {NodeName = Name;}

    NodeType NodeType;

private:
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget = nullptr) override;
    QRectF boundingRect() const override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

    ConnectionLine *ConnectionLiniia;
    Node *ConnectedNode;

    int Wymiar;
    bool Occupied = false;
    QString NodeName;

signals:
    void NodeClickedSignal(Node *node);
};

#endif // NODE_H
