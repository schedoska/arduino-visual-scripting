#ifndef PINOUTPUTPANELDATA_H
#define PINOUTPUTPANELDATA_H

#include <pinoutputpanel.h>
#include <QDataStream>
#include <QFile>

#define NAME "Pin Output (Digital)"
#define SUBNAME "PinOutputDigital"

class PinOutputPanelData
{
public:
    static bool ComparePanelName(QString name);
    static PinOutputPanel* LoadFromFile(QFile *plik);
    static void SaveToFile(PinOutputPanel *panel,QFile *plik);
    static QString GetPanelSubName();

private:
    PinOutputPanelData();
};

#endif // PINOUTPUTPANELDATA_H
