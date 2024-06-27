#include "loadmanager.h"
#include <QFile>
#include <QtDebug>
#include <Panels_data/pinoutputpaneldata.h>
#include <Panels_data/comparatorpaneldata.h>

LoadManager::LoadManager(FlowChartScene *scena)
{
    this->scena = scena;
}

void LoadManager::LoadScene(QString FilePath)
{
    QFile plik;
    plik.setFileName(FilePath);
    plik.open(QIODevice::ReadOnly | QIODevice::Text);

    if(plik.isOpen() == false)
    {
        qDebug() << "Nie Udało się otworzyć pliku: " + FilePath;
        return;
    }

    scena->ClearScene();
    this->plik = &plik;
    stream = new QDataStream(&plik);

    StartLoading();
    plik.close();
}

void LoadManager::StartLoading()
{
    while(plik->atEnd() == false)
    {
        ProcessLine();
    }
    qDebug() << "End of file " << scena->items().length();
}

void LoadManager::ProcessLine()
{
    QString Linia = plik->readLine().trimmed();

    if      (Linia == "panel:") ProcessPanel();
    else if (Linia == "-Node Connections-") CreateListOfInputNodes();
    else if (Linia == "node connection:")   ProcessNodeConnection();
}

void LoadManager::ProcessPanel()
{
    QString PanelName = plik->readLine().trimmed();
    Panel *panel = nullptr;

    if(PinOutputPanelData::ComparePanelName(PanelName))
        panel = PinOutputPanelData::LoadFromFile(plik);

    else if(ComparatorPanelData::ComparePanelName(PanelName))
        panel = ComparatorPanelData::LoadFromFile(plik);

    if(panel == nullptr) return;
    else scena->AddPanelWithIndex(panel);
}

void LoadManager::ProcessNodeConnection()
{
    QString NodeNames = plik->readLine().trimmed();
    QString InputNodeName = NodeNames.split(' ').at(0);
    QString OutputNodeName = NodeNames.split(' ').at(1);

    Node *Input = FindNodeByName(InputNodeName);
    Node *Output = FindNodeByName(OutputNodeName);

    if(Input == nullptr || Output == nullptr) return;

    scena->MakeConnection(Input, Output);
}

void LoadManager::CreateListOfInputNodes()
{
    ListOfInputNodes.clear();
    ListOfOutputNodes.clear();

    foreach(Panel *panel, scena->getListaPaneli())
    {
        ListOfInputNodes.append(panel->getInputNodes());
        ListOfOutputNodes.append(panel->getOutputNodes());
    }
}

Node *LoadManager::FindNodeByName(QString name)
{
    foreach(Node *node, ListOfInputNodes)
    {
        if(node->getNodeName() == name) return node;
    }
    foreach(Node *node, ListOfOutputNodes)
    {
        if(node->getNodeName() == name) return node;
    }
    return nullptr;
}

















