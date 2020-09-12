#ifndef SERIAL_CLASS_H
#define SERIAL_CLASS_H

#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>

#include <QtDebug>
#include <QTimer>


class Serial_Class:private QObject
{
    Q_OBJECT
public:
    Serial_Class(QObject *parent=0);
    void run_Class();
    static QString Serialport_portname,recieved_data;


public slots:
    void execute();
private:

};

#endif // SERIAL_CLASS_H
