#include "dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);
}

void Dialog::on_buttonBox_accepted()
{
    emit tableGetted(lineEdit->text().toInt(), lineEdit_2->text().toInt());// Передаем в сигнал данные о ширине.
}
