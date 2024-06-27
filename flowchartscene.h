#ifndef FLOWCHARTSCENE_H
#define FLOWCHARTSCENE_H

#include <QGraphicsScene>
#include "pinoutputpanel.h"
#include "pininputpanel.h"
#include "gainpanel.h"
#include "connectionline.h"
#include <QTimer>
#include <QGraphicsProxyWidget>

class FlowChartScene: public QGraphicsScene
{
public:
    FlowChartScene();
    QList<Panel*> getListaPaneli();
    QList<ConnectionLine*> getListaConnectionLines();

public slots:
    //void TestAddPanel();
    void NodeClickedRequest(Node *node);
    void AddPanel(Panel *panel);
    void AddPanelWithIndex(Panel *panel);
    void DeleteRequestReciver(Panel *panel);
    void NodeDisconnectRequest(Node *node);
    void NodeDeleteReciver(Node *node);
    void ClearScene();
    void MakeConnection(Node *Inputnode, Node *OutputNode);

private:
    QList<Panel*> ListaPaneli;
    QList<ConnectionLine*> ListaConnectionLines;

    bool isMakingConnection = false;
    Node *currentStartConnectionNode;
    ConnectionLine *currentConnectionLine;
    Node *currentPotentialEndNode = nullptr;
    QTimer Czasomierz;
    int NearestNodeTolerance;
    uint currentPanelIndex;

    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event) override;
    void AddNewConnection(Node *startNode);
    void EndConnecting();
    Node* FindNearestNode(QPoint MousePos,NodeType SzukanyTyp, int Radius);

    QGraphicsProxyWidget *MenuPanelow;
};

#endif // FLOWCHARTSCENE_H
