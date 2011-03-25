#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtGui/QApplication>
#include <QString>
#include "../state.h"
#include "../datahub/datahub.h"
#include "../controllers/controllers.h"

MainWindow::MainWindow(QWidget *parent, AUVC_State_Data *someData) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    stateData(someData)
{
    ui->setupUi(this);
    ui->treeView->setModel(stateData);
}

MainWindow::~MainWindow()
{
    delete ui;
}
