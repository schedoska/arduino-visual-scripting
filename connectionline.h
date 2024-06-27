#ifndef CONNECTIONLINE_H
#define CONNECTIONLINE_H

#include <QGraphicsItem>

class ConnectionLine: public QGraphicsItem
{
public:
    ConnectionLine();
    void UpdateInputNodePos(QPoint Pos);
    void UpdateOutputNodePos(QPoint Pos);

    void InitializeNodeConnection(QPointF inputPos, QPointF outputPos);

    bool InputNodeConected = false;
    bool OutputNodeConnected = false;

    int type() const override;

private:
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget = nullptr) override;
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event) override;
    QRectF boundingRect() const override;
    QPainterPath shape() const override;

    QPoint InputNodePos;
    QPoint OutputNodePos;
};

#endif // CONNECTIONLINE_H
