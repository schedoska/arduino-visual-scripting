#ifndef LOADMANAGER_H
#define LOADMANAGER_H

#include <flowchartscene.h>
#include <QFile>

class LoadManager
{
public:
    LoadManager(FlowChartScene *Scena);
    void LoadScene(QString FilePath);

private:
    FlowChartScene *scena;
    QFile *plik;
    QDataStream *stream;

    void StartLoading();
    void ProcessLine();
    void ProcessPanel();
    void ProcessNodeConnection();
    void CreateListOfInputNodes();

    Node* FindNodeByName(QString name);

    QList<Node*> ListOfInputNodes;
    QList<Node*> ListOfOutputNodes;
};

#endif // LOADMANAGER_H
