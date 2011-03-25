#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QModelIndex>
#include "../state/state.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent, AUVC_State_Data *someData);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    AUVC_State_Data *stateData;

private slots:

};

#endif // MAINWINDOW_H
