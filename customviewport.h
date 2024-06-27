#ifndef CUSTOMVIEWPORT_H
#define CUSTOMVIEWPORT_H

#include <QGraphicsView>
#include "shadow.h"

class CustomViewPort : public QGraphicsView
{
public:
    CustomViewPort(QGraphicsScene *scena, QWidget *parento);

    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

private:
    QPointF CenterPoint;
    QPointF StartClickPoint;
    QPointF potentialCenterPoint;
    bool isMoving = false;

    TopShadow *Cien_Style;
};

#endif // CUSTOMVIEWPORT_H
