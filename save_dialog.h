#ifndef SAVE_DIALOG_H
#define SAVE_DIALOG_H

#include <QDialog>
#include <QFile>
#include <QFileDialog>
//#include <QDir>

namespace Ui {
class Save_Dialog;
}

class Save_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Save_Dialog(QWidget *parent = nullptr);
    ~Save_Dialog();

private slots:
    void on_pushButton_clicked();
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

private:
    Ui::Save_Dialog *ui;
};

#endif // SAVE_DIALOG_H
