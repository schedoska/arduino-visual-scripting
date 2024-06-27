#ifndef COMPARATORPANELDATA_H
#define COMPARATORPANELDATA_H

#include "mathcompraratorpanel.h"
#include <QFile>

#define NAME "Comparator"
#define SUBANAME "Comparator"

class ComparatorPanelData
{
public:
    static bool ComparePanelName(QString name);
    static MathCompraratorPanel* LoadFromFile(QFile *plik);
    static void SaveToFile(MathCompraratorPanel *panel,QFile *plik);
    static QString GetPanelSubName();

private:
    ComparatorPanelData();
};

#endif // COMPARATORPANELDATA_H
