#ifndef SAVEMANAGER_H
#define SAVEMANAGER_H

#include <flowchartscene.h>

class SaveManager
{
public:
    SaveManager(FlowChartScene *scena);
    void SaveScene(QString filepath);

private:
    FlowChartScene *scena;

};

#endif // SAVEMANAGER_H
