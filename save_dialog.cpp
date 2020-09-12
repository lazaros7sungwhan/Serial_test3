#include "save_dialog.h"
#include "ui_save_dialog.h"
#include "mainwindow.h"

QString strFilter = "bitmap file (*.bmp) ;; text file (*.txt) ;; All files (*.*)";
QString strfilename;
Save_Dialog::Save_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Save_Dialog)
{
    ui->setupUi(this);
}

Save_Dialog::~Save_Dialog()
{
    delete ui;
}

void Save_Dialog::on_pushButton_clicked()
{
    {

        //QString strFileName = QFileDialog::getOpenFileName(this, "Open a file", QDir::homePath() , strFilter);
        strfilename=QFileDialog::getSaveFileName(this,"Open a file",QDir::homePath(),strFilter);
        if(strfilename.contains(".txt",Qt::CaseInsensitive))
        ui->lineEdit->setText(strfilename);
        else
        {
            strfilename+=".txt";
            ui->lineEdit->setText(strfilename);
        }
    }
}

void Save_Dialog::on_buttonBox_accepted()
{
    MainWindow::directory_1=strfilename;
}

void Save_Dialog::on_buttonBox_rejected()
{
    this->close();
}
