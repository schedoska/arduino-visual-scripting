#include "connectionline.h"
#include <QPainter>
#include <QPainterPath>
#include <QtMath>
#include <QDebug>
#include <QGraphicsSceneContextMenuEvent>
#include <node.h>

ConnectionLine::ConnectionLine()
{
    setZValue(10);
    InputNodePos = QPoint(0,0);
    OutputNodePos = QPoint(0,0);
}

void ConnectionLine::UpdateInputNodePos(QPoint Pos)
{
    InputNodePos = Pos;
    update();
}

void ConnectionLine::UpdateOutputNodePos(QPoint Pos)
{
    OutputNodePos = Pos;
    update();
}

void ConnectionLine::InitializeNodeConnection(QPointF inputPos, QPointF outputPos)
{
    UpdateInputNodePos(inputPos.toPoint());
    UpdateOutputNodePos(outputPos.toPoint());
    OutputNodeConnected = true;
    InputNodeConected = true;
}

int ConnectionLine::type() const
{
    return 2;
}

void ConnectionLine::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //luk
    int CurveIndex = qFabs(OutputNodePos.x() - InputNodePos.x()) / 2.;

    QPainterPath luk;
    luk.moveTo(OutputNodePos);
    luk.cubicTo(OutputNodePos.x() + CurveIndex, OutputNodePos.y(), InputNodePos.x() - CurveIndex,
                InputNodePos.y(), InputNodePos.x(), InputNodePos.y());

    QPen dlugopis(QColor(97,228,184));
    dlugopis.setCapStyle(Qt::RoundCap);
    dlugopis.setWidth(3);

    painter->setRenderHint(QPainter::Antialiasing,true);
    painter->setPen(dlugopis);
    painter->drawPath(luk);

    //kropki na koncach
    int Rozmiar_kropki = 6;
    painter->setBrush(QBrush(QColor(38,168,211)));
    painter->setPen(Qt::NoPen);

    if(OutputNodeConnected)
    {
        painter->drawEllipse(OutputNodePos.x()-Rozmiar_kropki/2,OutputNodePos.y()-Rozmiar_kropki/2,
                             Rozmiar_kropki,Rozmiar_kropki);
    }
    if(InputNodeConected)
    {
        painter->drawEllipse(InputNodePos.x()-Rozmiar_kropki/2,InputNodePos.y()-Rozmiar_kropki/2,
                             Rozmiar_kropki,Rozmiar_kropki);
    }
}

void ConnectionLine::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{
    event->ignore();
    QGraphicsItem::contextMenuEvent(event);
}

QRectF ConnectionLine::boundingRect() const
{
    return QRectF(0,0,2000,2000);
}

QPainterPath ConnectionLine::shape() const
{
    QPainterPath GhostShape;
    GhostShape.addRect(0,0,0,0);
    return GhostShape;
}
