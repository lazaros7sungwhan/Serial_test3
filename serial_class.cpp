#include "serial_class.h"

QTimer *mytimer;
QSerialPort *Serial_1=new QSerialPort;
QString Serial_Class::Serialport_portname="",Serial_Class::recieved_data="111";

Serial_Class::Serial_Class(QObject *parent):QObject(parent)
{
    mytimer=new QTimer(this);
    connect(mytimer,SIGNAL(timeout()),this,SLOT(execute()));
}

void Serial_Class::run_Class()
{
    Serial_1->setPortName(Serialport_portname);
    Serial_1->setBaudRate(QSerialPort::Baud115200);
    Serial_1->setParity(QSerialPort::NoParity);
    Serial_1->setDataBits(QSerialPort::Data8);
    Serial_1->setStopBits(QSerialPort::OneStop);
    Serial_1->setFlowControl(QSerialPort::NoFlowControl);

     if(!Serial_1->open(QIODevice::ReadWrite))
     {
         qDebug()<<"opening error";
     }
    mytimer->start(100);
}
void Serial_Class::execute()
{
    while(Serial_1->canReadLine())
    {
        recieved_data=Serial_1->readLine();
    }
    if(recieved_data!="")
    {
        qDebug()<<recieved_data;
    }
}
