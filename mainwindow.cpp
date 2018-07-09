#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    init_serial();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::init_serial() {
    qDebug("inisial serial");
    seri = new QSerialPort(this);
//    connect(seri, SIGNAL());

    connect(seri, SIGNAL(bytesWritten(qint64)), this, SLOT(dataTerkirim(qint64)));
    connect(seri, SIGNAL(readyRead()), this, SLOT(terimaDataSerial()));
//    connect(seri, SIGNAL(d))

    seri->setPortName("/dev/ttyO1");
    seri->setBaudRate(230400, QSerialPort::AllDirections);
//    seri->setParity(QSerialPort::NoParity);
//    seri->setDataBits(QSerialPort::Data8);
//    seri->setStopBits(QSerialPort::)

    seri->open(QIODevice::ReadWrite);

    if (seri->isOpen()) {
        qDebug("Serial open");
    }
    else {
        qDebug("Serial not open");
    }
    seri->write("Halo bro");
    qDebug("barusan ngirim : Halo bro");

}

void MainWindow::terimaDataSerial() {
    QByteArray dataIn;
    dataIn = seri->readAll();
    qDebug() << "Serial terima:" << dataIn;

    QByteArray dataOut;
    dataOut.append("ok saya sudah terima");
    int statusKirim = seri->write(dataOut);

}

void MainWindow::dataTerkirim(qint64 bytes) {
    qDebug() << "data terkirim:" << bytes;
}

void MainWindow::disconnectSerial() {

}
