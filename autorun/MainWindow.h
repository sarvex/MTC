#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    bool checkRegistry ();
    bool checkModem ();

    bool runSetup ();
    bool runApplication ();

    bool ejectModem ();

    QString installDirectory;
    bool amd;
};

#endif // MAINWINDOW_H
