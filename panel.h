#ifndef PANEL_H
#define PANEL_H

#include <QGraphicsItem>
#include <node.h>
#include <QGraphicsSceneMouseEvent>
#include "panelstyle.h"
#include <QTimer>
#include <QFile>

class Panel: public QGraphicsObject
{
    Q_OBJECT
public:
    Panel(int Szerokosc, int Wysokosc);

    QList<Node *> &getOutputNodes();
    QList<Node *> &getInputNodes();

    void AddNode(Node* node);
    void DeleteNode(Node *node);
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget = nullptr) override;
    QFont getFont();
    void setTitle(QString PanelName);
    void setColorVariant(PanelStyleVariant wariant);
    void UpdateSize(int Szerokosc, int Wysokosc);
    void UpdateNodesPosition();
    void setIndex(uint index);
    uint getIndex();
    virtual void initialize();
    virtual void SavePanelToFile(QFile *plik);
    void SaveNodeConnectionsToFile(QFile *plik);

private:
    QRectF boundingRect() const override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event) override;

    int Szerokosc, Wysokosc;
    PanelStyle Styl;

    QList<Node*> ListaOutputNodes;
    QList<Node*> ListaInputNodes;

    QTimer Czasomierz;
    uint index;

public slots:
    void NodeClickedSignalReciver(Node *node);
    void Delete();

signals:
    void NodeClickedSignalSender(Node *node);
    void DeleteRequest(Panel *panel);
    void NodeDeleteRequest(Node *node);
};

#endif // PANEL_H
