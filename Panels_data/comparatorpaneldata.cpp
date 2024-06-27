#include "comparatorpaneldata.h"
#include <QTextStream>

bool ComparatorPanelData::ComparePanelName(QString name)
{
    return (name == NAME ? true : false);
}

MathCompraratorPanel *ComparatorPanelData::LoadFromFile(QFile *plik)
{
    int x, y, modeCount;

    QString Indx = plik->readLine().trimmed();
    uint index = Indx.toInt();

    QString Poz = plik->readLine().trimmed();
    x = Poz.split(' ').at(0).toInt();
    y = Poz.split(' ').at(1).toInt();
    QString Mode = plik->readLine().trimmed();
    modeCount = Mode.toInt();

    MathCompraratorPanel *panel = new MathCompraratorPanel(x,y);
    panel->setComparatorMode(modeCount);
    panel->setIndex(index);

    return panel;
}

void ComparatorPanelData::SaveToFile(MathCompraratorPanel *panel, QFile *plik)
{
    QTextStream stream(plik);
    plik->write("$\npanel:\n");
    plik->write(NAME);
    plik->write("\n");

    stream << panel->getIndex() << '\n';
    stream << panel->pos().x() << ' ' << panel->pos().y() << '\n';
    stream << panel->getModeCount() << '\n';
}

QString ComparatorPanelData::GetPanelSubName()
{
    return SUBANAME;
}

ComparatorPanelData::ComparatorPanelData()
{

}
