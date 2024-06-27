#ifndef PANELMENU_H
#define PANELMENU_H

#include <QMenu>
#include <flowchartscene.h>

class PanelMenu : public QMenu
{
    Q_OBJECT
public:
    PanelMenu(FlowChartScene *scena, QPoint pos);

private:
    QPoint currentMousePos;

    QMenu *Inputs;
    QMenu *Outputs;
    QMenu *Mathematical_Exp;
    QMenu *Converters;

    QAction *DigitalInput;
    QAction *DigitalOutput;

    QAction *Gain;
    QAction *Comparator;

    QAction *Mux;

    void init_Inputs();
    void init_Outputs();
    void init_Mathematical();
    void init_Converters();

    FlowChartScene *scena;

public slots:
    void AddDigitalInput();
    void AddDigitalOutput();
    void AddGainBlock();
    void AddMux();
    void AddComparator();
};

#endif // PANELMENU_H
