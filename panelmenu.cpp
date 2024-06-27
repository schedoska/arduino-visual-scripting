#include "panelmenu.h"
#include <QtDebug>
#include <QApplication>
#include <QPushButton>
#include "pininputpanel.h"
#include <QStyle>
#include "pinoutputpanel.h"
#include "muxpnael.h"
#include "mathcompraratorpanel.h"

PanelMenu::PanelMenu(FlowChartScene *scena, QPoint pos)
{
    this->scena = scena;
    currentMousePos = pos;

    init_Inputs();
    init_Outputs();
    init_Mathematical();
    init_Converters();

    //setStyleSheet("background: rgb(90,90,90)");
}

void PanelMenu::init_Inputs()
{
    Inputs = new QMenu(this);
    Inputs->setTitle("Inputs");

    DigitalInput = new QAction("Digital Input",this);
    connect(DigitalInput, &QAction::triggered, this, &PanelMenu::AddDigitalInput);
    Inputs->addAction(DigitalInput);

    addMenu(Inputs);
}

void PanelMenu::init_Outputs()
{
    Outputs = new QMenu(this);
    Outputs->setTitle("Outputs");

    DigitalOutput = new QAction("Digital Output",this);
    connect(DigitalOutput, &QAction::triggered, this, &PanelMenu::AddDigitalOutput);
    Outputs->addAction(DigitalOutput);

    addMenu(Outputs);
}

void PanelMenu::init_Mathematical()
{
    Mathematical_Exp = new QMenu(this);
    Mathematical_Exp->setTitle("Mathematical Blocks");

    Gain = new QAction("Gain",this);
    connect(Gain, &QAction::triggered, this, &PanelMenu::AddGainBlock);
    Mathematical_Exp->addAction(Gain);

    Comparator = new QAction("Comparator",this);
    connect(Comparator, &QAction::triggered, this, &PanelMenu::AddComparator);
    Mathematical_Exp->addAction(Comparator);

    addMenu(Mathematical_Exp);
}

void PanelMenu::init_Converters()
{
    Converters = new QMenu(this);
    Converters->setTitle("Converters");

    Mux = new QAction("Mux",this);
    Mux->setWhatsThis("This Mux block");
    connect(Mux, &QAction::triggered, this, &PanelMenu::AddMux);
    Converters->addAction(Mux);

    addMenu(Converters);
}

void PanelMenu::AddDigitalInput()
{
    PinInputPanel *nowy_panel = new PinInputPanel(currentMousePos.x(), currentMousePos.y());
    scena->AddPanel(nowy_panel);
}

void PanelMenu::AddDigitalOutput()
{
    PinOutputPanel *nowy_panel = new PinOutputPanel(currentMousePos.x(), currentMousePos.y());
    scena->AddPanel(nowy_panel);
}

void PanelMenu::AddGainBlock()
{
    GainPanel *nowy_panel = new GainPanel(currentMousePos.x(), currentMousePos.y());
    scena->AddPanel(nowy_panel);
}

void PanelMenu::AddMux()
{
    MuxPnael *nowy_panel = new MuxPnael(currentMousePos.x(), currentMousePos.y());
    scena->AddPanel(nowy_panel);
}

void PanelMenu::AddComparator()
{
    MathCompraratorPanel *nowy_panel = new MathCompraratorPanel(currentMousePos.x(), currentMousePos.y());
    scena->AddPanel(nowy_panel);
}

