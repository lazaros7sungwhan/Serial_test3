#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "serial_class.h"
#include "save_dialog.h"

QTimer *worker_1, *worker_2;
QString MainWindow::directory_1="";

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    myserial_class = new Serial_Class();
    foreach (const QSerialPortInfo &serialportinfo, QSerialPortInfo::availablePorts()) {
    ui->comboBox->addItem(serialportinfo.portName());
    }

    worker_1=new QTimer();
    connect(worker_1,SIGNAL(timeout()),this,SLOT(DoWorker1()));
    worker_2=new QTimer();
    connect(worker_2,SIGNAL(timeout()),this,SLOT(DoWorker2()));

    worker_2->start(1);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButton_clicked()
{
    Serial_Class::Serialport_portname=ui->comboBox->currentText();
    qDebug()<<"ok";
    myserial_class->run_Class();
    worker_1->start(10);
}
void MainWindow::DoWorker1()
{
    ui->lineEdit->setText(Serial_Class::recieved_data);
}
void MainWindow::DoWorker2()
{
    ui->label->setText(directory_1);
}

void MainWindow::on_actionSave_triggered()
{
  Save_Dialog save_dialog1;
  save_dialog1.setModal(true);
  save_dialog1.exec();
}

void MainWindow::on_actionExit_triggered()
{
    this->close();
}
