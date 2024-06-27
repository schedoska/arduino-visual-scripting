#include "pinoutputpaneldata.h"
#include "pinoutpanelpinselector.h"
#include <QTextStream>

bool PinOutputPanelData::ComparePanelName(QString name)
{
    return (name == NAME ? true : false);
}

PinOutputPanel* PinOutputPanelData::LoadFromFile(QFile *plik)
{
    QDataStream stream(plik);
    QList<bool> values;

    int x, y;
    PinSelectorValuesData data;

    QString Indx = plik->readLine().trimmed();
    uint index = Indx.toInt();

    QString Poz = plik->readLine().trimmed();
    x = Poz.split(' ').at(0).toInt();
    y = Poz.split(' ').at(1).toInt();

    for(int n = 0; n < 20; n++)
    {
        QString value = plik->readLine().trimmed();
        if(value == "on") values.append(true);
        else values.append(false);
    }

    data.PINA0 = values.at(0);
    data.PINA1 = values.at(1);
    data.PINA2 = values.at(2);
    data.PINA3 = values.at(3);
    data.PINA4 = values.at(4);
    data.PINA5 = values.at(5);

    data.PIN0 = values.at(6);
    data.PIN1 = values.at(7);
    data.PIN2 = values.at(8);
    data.PIN3 = values.at(9);
    data.PIN4 = values.at(10);
    data.PIN5 = values.at(11);
    data.PIN6 = values.at(12);
    data.PIN7 = values.at(13);
    data.PIN8 = values.at(14);
    data.PIN9 = values.at(15);
    data.PIN10 = values.at(16);
    data.PIN11 = values.at(17);
    data.PIN12 = values.at(18);
    data.PIN13 = values.at(19);

    PinOutputPanel *panel = new PinOutputPanel(x,y);
    panel->setPinValuesData(data);
    panel->setIndex(index);

    return panel;
}

void PinOutputPanelData::SaveToFile(PinOutputPanel *panel, QFile *plik)
{
    QTextStream stream(plik);
    plik->write("$\npanel:\n");
    plik->write(NAME);
    plik->write("\n");

    stream << panel->getIndex() << '\n';
    stream << panel->pos().x() << ' ' << panel->pos().y() << '\n';

    PinSelectorValuesData data = panel->getValuesData();
    QList<bool> Values;

    Values.append(data.PINA0);
    Values.append(data.PINA1);
    Values.append(data.PINA2);
    Values.append(data.PINA3);
    Values.append(data.PINA4);
    Values.append(data.PINA5);

    Values.append(data.PIN0);
    Values.append(data.PIN1);
    Values.append(data.PIN2);
    Values.append(data.PIN3);
    Values.append(data.PIN4);
    Values.append(data.PIN5);
    Values.append(data.PIN6);
    Values.append(data.PIN7);
    Values.append(data.PIN8);
    Values.append(data.PIN9);
    Values.append(data.PIN10);
    Values.append(data.PIN11);
    Values.append(data.PIN12);
    Values.append(data.PIN13);

    for(int n = 0; n < 20; n++)
    {
        if(Values.at(n) == true) stream << "on\n";
        else stream << "off\n";
    }
}

QString PinOutputPanelData::GetPanelSubName()
{
    return SUBNAME;
}

PinOutputPanelData::PinOutputPanelData()
{

}
