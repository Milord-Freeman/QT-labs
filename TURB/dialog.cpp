#include "dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);
}



void Dialog::on_buttonBox_accepted()
{
    // Выделяем память под наши ячейки
    QTableWidgetItem *name_task = new QTableWidgetItem;
    //name_task->setText(lineEdit_name_task->text()); // Считываем название программы из поля.
    name_task->setText("test calc");
    QTableWidgetItem *path_task = new QTableWidgetItem;
    //path_task->setText(lineEdit_path_task->text()); // Считываем путь до проги из поля
    path_task->setText("calc");
    QTableWidgetItem *date_task = new QTableWidgetItem;
    //date_task->setText(dateTimeEdit_task->dateTime().toString()); //Переводим дату в текст
    date_task->setText(QDateTime::currentDateTime().addSecs(5).toString());
    QTableWidgetItem *period_task = new QTableWidgetItem;
    period_task->setText(comboBox_period_task->currentText()); // Считываем данные о периоде

    emit push_task(name_task, path_task, date_task, period_task); // Вырабатываем сигнал для передачи данных.

}
