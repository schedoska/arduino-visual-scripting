#include "customviewport.h"
#include <QDebug>
#include <QMouseEvent>
#include <QScrollBar>
#include <QGraphicsItem>

CustomViewPort::CustomViewPort(QGraphicsScene *scena, QWidget *parento)
{
   setScene(scena);
   setParent(parento);

   setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
   setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
   setMouseTracking(true);
   centerOn(width()/2.,height()/2.);
   CenterPoint = QPointF(width()/2.,height()/2.);

   setFrameShape(QFrame::NoFrame);
   Cien_Style = new TopShadow(this,1200,7);
}

void CustomViewPort::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::RightButton)
    {
        isMoving = true;
        StartClickPoint = event->pos();
    }
        QGraphicsView::mousePressEvent(event);
}

void CustomViewPort::mouseReleaseEvent(QMouseEvent *event)
{
    isMoving = false;
    CenterPoint = potentialCenterPoint;
    QGraphicsView::mouseReleaseEvent(event);
}

void CustomViewPort::mouseMoveEvent(QMouseEvent *event)
{
    if(isMoving)
    {
        QPointF delta = StartClickPoint - event->pos();
        potentialCenterPoint = CenterPoint + delta;

        if(potentialCenterPoint.x() < width()/2.) potentialCenterPoint.setX(width()/2.);
        if(potentialCenterPoint.y() < height()/2.) potentialCenterPoint.setY(height()/2.);
        if(potentialCenterPoint.x() > sceneRect().width() - width()/2.) potentialCenterPoint.setX(sceneRect().width() - width()/2.);
        if(potentialCenterPoint.y() > sceneRect().height() - height()/2.) potentialCenterPoint.setY(sceneRect().height() - height()/2.);
        centerOn(potentialCenterPoint);
    }
    QGraphicsView::mouseMoveEvent(event);
}

void CustomViewPort::resizeEvent(QResizeEvent *event)
{
    if(CenterPoint.x() < width()/2.) CenterPoint.setX(width()/2.);
    if(CenterPoint.y() < height()/2.) CenterPoint.setY(height()/2.);
    if(CenterPoint.x() > sceneRect().width() - width()/2.) CenterPoint.setX(sceneRect().width() - width()/2.);
    if(CenterPoint.y() > sceneRect().height() - height()/2.) CenterPoint.setY(sceneRect().height() - height()/2.);
    centerOn(CenterPoint);

    Cien_Style->UpdateWidth(width());
    Cien_Style->update();
}













