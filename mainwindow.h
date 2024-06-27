#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "customviewport.h"
#include <QPushButton>
#include "flowchartscene.h"
#include <loadmanager.h>
#include <savemanager.h>

class MainWindow: public QMainWindow
{
    Q_OBJECT;
public:
    MainWindow();

private:
    CustomViewPort *Ekran;
    FlowChartScene *Scena;

    QPushButton *AddNewPanel_btn;
    QPushButton *LoadButton;
    QPushButton *SaveButton;

    LoadManager *LoadManager;
    SaveManager *SaveManager;

    void resizeEvent(QResizeEvent *evento) override;
    void initButtons();

public slots:
    void LoadScene();
    void SaveScene();
};

#endif // MAINWINDOW_H
