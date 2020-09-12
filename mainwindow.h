#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QtDebug>
#include <QTimer>
#include <QFile>
#include <QFileDialog>
#include "serial_class.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    static QString directory_1;

private slots:
    void on_pushButton_clicked();
    void DoWorker1();
    void DoWorker2();

    void on_actionSave_triggered();

    void on_actionExit_triggered();

private:
    Ui::MainWindow *ui;
    Serial_Class *myserial_class;

};
#endif // MAINWINDOW_H
