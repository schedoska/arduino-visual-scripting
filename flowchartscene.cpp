#include "flowchartscene.h"
#include <QDebug>
#include <QtMath>
#include <QCursor>
#include <QMenu>
#include <QBrush>
#include <QGraphicsView>
#include "panelmenu.h"
#include "Panels_data/indexmanager.h"

FlowChartScene::FlowChartScene()
{
    Czasomierz.setSingleShot(true);
    setBackgroundBrush(QBrush(QColor(244, 255, 255)));
    NearestNodeTolerance = 30;
    MenuPanelow = nullptr;

    //currentPanelIndex = 1;
}

QList<Panel *> FlowChartScene::getListaPaneli()
{
    return ListaPaneli;
}

QList<ConnectionLine *> FlowChartScene::getListaConnectionLines()
{
    return ListaConnectionLines;
}

/*void FlowChartScene::TestAddPanel()
{
    PinInputPanel *panel = new PinInputPanel(50,50);
    ListaPaneli.append(panel);
    addItem(panel);
    panel->initialize();

    connect(panel, &Panel::NodeClickedSignalSender, this, &FlowChartScene::NodeClickedRequest);

    PinOutputPanel *panelo = new PinOutputPanel(100,50);
    ListaPaneli.append(panelo);
    addItem(panelo);
    panelo->initialize();

    connect(panelo, &Panel::NodeClickedSignalSender, this, &FlowChartScene::NodeClickedRequest);

    GainPanel *panel3 = new GainPanel(150,50);
    ListaPaneli.append(panel3);
    addItem(panel3);
    panel3->initialize();

    connect(panel3, &Panel::NodeClickedSignalSender, this, &FlowChartScene::NodeClickedRequest);
}*/

void FlowChartScene::NodeClickedRequest(Node *node)
{
    if(isMakingConnection == false && Czasomierz.isActive() == false && node->isOccupied() == false)
    {
        AddNewConnection(node);
    }
    else if(isMakingConnection == false && Czasomierz.isActive() == false && node->isOccupied() == true)
    {
        NodeDisconnectRequest(node);
    }
}

void FlowChartScene::AddPanel(Panel *panel)
{
    ListaPaneli.append(panel);
    addItem(panel);
    panel->setIndex(IndexManager::GiveFirstIndexAvailble(ListaPaneli));
    panel->initialize();
    connect(panel, &Panel::NodeClickedSignalSender, this, &FlowChartScene::NodeClickedRequest);
    connect(panel, &Panel::DeleteRequest, this, &FlowChartScene::DeleteRequestReciver);
    connect(panel, &Panel::NodeDeleteRequest, this, &FlowChartScene::NodeDeleteReciver);
}

void FlowChartScene::AddPanelWithIndex(Panel *panel)
{
    ListaPaneli.append(panel);
    addItem(panel);
    panel->initialize();
    connect(panel, &Panel::NodeClickedSignalSender, this, &FlowChartScene::NodeClickedRequest);
    connect(panel, &Panel::DeleteRequest, this, &FlowChartScene::DeleteRequestReciver);
    connect(panel, &Panel::NodeDeleteRequest, this, &FlowChartScene::NodeDeleteReciver);

    //if(currentPanelIndex <= panel->getIndex())
        //currentPanelIndex = panel->getIndex() + 1;
}

void FlowChartScene::DeleteRequestReciver(Panel *panel)
{   
    QList<Node*> Lista = panel->getInputNodes();
    Lista.append(panel->getOutputNodes());

    foreach(Node *node, Lista)
    {
        /*if(node->isOccupied() == false) continue;

        ConnectionLine *linia = node->getConnectedLine();
        node->getConnectedNode()->disconnectNode();
        ListaConnectionLines.removeOne(linia);
        removeItem(linia);
        delete linia;*/
        NodeDisconnectRequest(node);
    }

    ListaPaneli.removeOne(panel);
    removeItem(panel);
    delete panel;
}

void FlowChartScene::NodeDisconnectRequest(Node *node)
{
    if(node->isOccupied() == false) return;

    node->getConnectedNode()->disconnectNode();
    removeItem(node->getConnectedLine());
    ListaConnectionLines.removeOne(node->getConnectedLine());
    delete node->getConnectedLine();
    node->disconnectNode();
}

void FlowChartScene::NodeDeleteReciver(Node *node)
{
    NodeDisconnectRequest(node);
    removeItem(node);
    delete node;
}

void FlowChartScene::ClearScene()
{
    foreach(Panel *panel, ListaPaneli)
    {
        removeItem(panel);
        delete panel;
    }
    foreach(ConnectionLine *linia, ListaConnectionLines)
    {
        removeItem(linia);
        delete linia;
    }

    ListaConnectionLines.clear();
    ListaPaneli.clear();
    //currentPanelIndex = 1;
}

void FlowChartScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if(isMakingConnection == false)
    {
        QGraphicsScene::mouseMoveEvent(event);
        return;
    }

    if(currentStartConnectionNode->NodeType == NodeType::OutputNode)
        currentPotentialEndNode = FindNearestNode(event->scenePos().toPoint(),NodeType::InputNode, NearestNodeTolerance);
    else
        currentPotentialEndNode = FindNearestNode(event->scenePos().toPoint(),NodeType::OutputNode, NearestNodeTolerance);

    if(currentStartConnectionNode->NodeType == NodeType::OutputNode && currentPotentialEndNode == nullptr)
    {
        currentConnectionLine->UpdateInputNodePos(event->scenePos().toPoint());
    }
    else if(currentPotentialEndNode == nullptr)
    {
        currentConnectionLine->UpdateOutputNodePos(event->scenePos().toPoint());
    }
    else if(currentStartConnectionNode->NodeType == NodeType::OutputNode)
    {
        currentConnectionLine->UpdateInputNodePos(currentPotentialEndNode->scenePos().toPoint());
    }
    else
    {
         currentConnectionLine->UpdateOutputNodePos(currentPotentialEndNode->scenePos().toPoint());
    }

    currentConnectionLine->update();
    QGraphicsScene::mouseMoveEvent(event);
}

void FlowChartScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(isMakingConnection) EndConnecting();
    QGraphicsScene::mousePressEvent(event);
}

void FlowChartScene::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{
    QGraphicsItem *isItem = itemAt(event->scenePos(),views().at(0)->transform());

    if(isItem == nullptr)
    {
        PanelMenu *menu = new PanelMenu(this, event->scenePos().toPoint());
        menu->exec(event->screenPos());
    }
    else if(isItem->type() == 2)
    {
        PanelMenu *menu = new PanelMenu(this, event->scenePos().toPoint());
        menu->exec(event->screenPos());
    }

    QGraphicsScene::contextMenuEvent(event);
}

void FlowChartScene::AddNewConnection(Node *startNode)
{
    currentStartConnectionNode = startNode;
    isMakingConnection = true;

    //Stworzenie nowej Linni
    currentConnectionLine = new ConnectionLine();
    addItem(currentConnectionLine);
    if(startNode->NodeType == NodeType::InputNode) currentConnectionLine->InputNodeConected = true;
    if(startNode->NodeType == NodeType::OutputNode) currentConnectionLine->OutputNodeConnected = true;

    //Ustawienie Pozycji poczatkowej linni
    currentConnectionLine->UpdateOutputNodePos(startNode->scenePos().toPoint());
    currentConnectionLine->UpdateInputNodePos(startNode->scenePos().toPoint());
}

Node* FlowChartScene::FindNearestNode(QPoint MousePos, NodeType SzukanyTyp, int Radius)
{
    QList<Node*> WszytskieNodesSzukanegoTypu;

    for(int q = 0; q < ListaPaneli.length(); q++)
    {
        if(SzukanyTyp == NodeType::InputNode)
        {
            WszytskieNodesSzukanegoTypu.append(ListaPaneli.at(q)->getInputNodes());
        }
        else
        {
            WszytskieNodesSzukanegoTypu.append(ListaPaneli.at(q)->getOutputNodes());
        }
    }

    float shortestDistance = 1000000;
    Node *NearestNode = nullptr;
    //qDebug() << WszytskieNodesSzukanegoTypu;

    for(int q = 0; q < WszytskieNodesSzukanegoTypu.length(); q++)
    {
        QPoint WektorMiedzyNimi = MousePos - WszytskieNodesSzukanegoTypu.at(q)->scenePos().toPoint();
        float distance = sqrtf(pow(WektorMiedzyNimi.x(),2) + pow(WektorMiedzyNimi.y(),2));
        if(distance < shortestDistance)
        {
            shortestDistance = distance;
            NearestNode =  WszytskieNodesSzukanegoTypu.at(q);
        }
    }

    if(shortestDistance < Radius && NearestNode->isOccupied() == false) return NearestNode;
    return nullptr;
}

void FlowChartScene::MakeConnection(Node *Inputnode, Node *OutputNode)
{
    ConnectionLine *nowa_linia = new ConnectionLine();
    addItem(nowa_linia);
    nowa_linia->InitializeNodeConnection(Inputnode->scenePos(),OutputNode->scenePos());

    Inputnode->addConnectedNode(OutputNode);
    Inputnode->addConnectionLine(nowa_linia);
    OutputNode->addConnectedNode(Inputnode);
    OutputNode->addConnectionLine(nowa_linia);

    ListaConnectionLines.append(nowa_linia);
    nowa_linia->update();
}

void FlowChartScene::EndConnecting()
{
    if(currentPotentialEndNode == nullptr)
    {
        removeItem(currentConnectionLine);
        delete currentConnectionLine;
        isMakingConnection = false;
    }
    else
    {
        currentStartConnectionNode->addConnectionLine(currentConnectionLine);
        currentPotentialEndNode->addConnectionLine(currentConnectionLine);
        ListaConnectionLines.append(currentConnectionLine);

        currentStartConnectionNode->addConnectedNode(currentPotentialEndNode);
        currentPotentialEndNode->addConnectedNode(currentStartConnectionNode);

        if(currentPotentialEndNode->NodeType == NodeType::InputNode)
            currentConnectionLine->InputNodeConected = true;
        else currentConnectionLine->OutputNodeConnected = true;

        currentConnectionLine->update();

        isMakingConnection = false;
        Czasomierz.start(100);
    }
}






