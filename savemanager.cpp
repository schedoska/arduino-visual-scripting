#include "savemanager.h"
#include <QFile>
#include <QtDebug>

SaveManager::SaveManager(FlowChartScene *scena)
{
    this->scena = scena;
}

void SaveManager::SaveScene(QString filepath)
{
    QFile plik(filepath);
    plik.open(QIODevice::WriteOnly | QIODevice::Text);

    foreach(Panel *panel, scena->getListaPaneli())
    {
        panel->SavePanelToFile(&plik);
    }

    plik.write("-Node Connections-\n");

    foreach(Panel *panel, scena->getListaPaneli())
    {
        panel->SaveNodeConnectionsToFile(&plik);
    }
}
