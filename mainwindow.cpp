#include "mainwindow.h"
#include <QDebug>
#include <QFile>
#include <QStandardPaths>
#include <QIODevice>

MainWindow::MainWindow()
{
    setGeometry(300,150,1200,800);
    setMinimumSize(1000,600);
    //setStyleSheet("background-color: gray");
    Scena = new FlowChartScene();
    Scena->setSceneRect(0,0,2000,2000);

    Ekran = new CustomViewPort(Scena,this);
    Ekran->setGeometry(0,100,width(), height() - 100);

    LoadManager = new class LoadManager(Scena);
    SaveManager = new class SaveManager(Scena);

    initButtons();

    /*QFile plik;
    plik.setFileName("C:/Users/chedo/OneDrive/Pulpit/Trening.txt");
    plik.open(QIODevice::ReadOnly | QIODevice::Text);

    QDataStream stream(&plik);
    QString kas;
    stream >> kas;
    qDebug() << kas;

    QString napis = plik.readLine(100);
    qDebug() << napis.split(' ');
    plik.close();*/
}

void MainWindow::resizeEvent(QResizeEvent *evento)
{
    Ekran->setGeometry(0,100,width(), height() - 100);
    qDebug() << Ekran->geometry();
}

void MainWindow::initButtons()
{
    //AddNewPanel_btn = new QPushButton("Add Panel",this);
    //AddNewPanel_btn->setGeometry(20,20,100,60);
    //connect(AddNewPanel_btn, &QPushButton::clicked, Scena, &FlowChartScene::TestAddPanel);

    LoadButton = new QPushButton("Load File", this);
    LoadButton->setGeometry(30,20,100,60);
    connect(LoadButton, &QPushButton::clicked, this, &MainWindow::LoadScene);

    SaveButton = new QPushButton("Save File", this);
    SaveButton->setGeometry(150,20,100,60);
    connect(SaveButton, &QPushButton::clicked, this, &MainWindow::SaveScene);
}

void MainWindow::LoadScene()
{
    LoadManager->LoadScene("C:/Users/chedo/OneDrive/Pulpit/TreningSave.txt");
}

void MainWindow::SaveScene()
{
    SaveManager->SaveScene("C:/Users/chedo/OneDrive/Pulpit/TreningSave.txt");
}










