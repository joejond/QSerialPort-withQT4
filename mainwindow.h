#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qserialport.h"
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QSerialPort *seri;
    void init_serial();

private:
    Ui::MainWindow *ui;

private slots:
    void dataTerkirim(qint64 bytes);
    void terimaDataSerial();
    void disconnectSerial();

};

#endif // MAINWINDOW_H
