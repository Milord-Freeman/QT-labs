#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    setupUi(this);

    tmr = new QTimer();
    tmr->setInterval(1000);

    QDateTime *start_time = new QDateTime(QDateTime::currentDateTime()); // start_time - время запуска программы.
    label_start->setText(start_time->toString()); // Вывод времени запуска на лейбл в программе, убрать в релизе.

    connect(tmr, SIGNAL(timeout()), this, SLOT(run_program()));
    // Как только таймер подает сигнал о таймауте (в нашем случае - раз в секунду)
    // запускается слот, который будет проверять, не надо ли запускать
    // какую-нибудь задачу. Слот описан в main_window

    tmr->start();

}

void MainWindow::run_program()
{

   label_cur->setText(QDateTime::currentDateTime().toString()); // Отображаем ход таймера

    for (int i=0;i<tableWidget->rowCount();i++)
    {
        if (label_cur->text() == tableWidget->item(i,2)->text())
        {
        QString program = tableWidget->item(i,1)->text(); // Запоминаем путь до программы
        QDateTime *temp = new QDateTime(QDateTime::fromString(tableWidget->item(i,2)->text()));
        label_run->setText(temp->toString());
        // Сейчас будет плохой код с if/else потому что switch case не работает со строками.
        if (tableWidget->item(i,3)->text() == "Каждую минуту") {label_run->setText(temp->addSecs(60).toString());}
        else if (tableWidget->item(i,3)->text() == "Каждый час") {label_run->setText(temp->addSecs(3600).toString());}
        else if (tableWidget->item(i,3)->text() == "Каждый день") {label_run->setText(temp->addDays(1).toString());}
        else if (tableWidget->item(i,3)->text() == "Каждую неделю") {label_run->setText(temp->addDays(7).toString());}
        else if (tableWidget->item(i,3)->text() == "Каждый месяц") {label_run->setText(temp->addMonths(1).toString());}
        else if (tableWidget->item(i,3)->text() == "Каждый год") {label_run->setText(temp->addMonths(12).toString());}
        // Это все нужно для обработки периода.
        //label_run->setText(temp->toString());
        tableWidget->item(i,2)->setText(label_run->text()); // Перезаписываем ближайшую дату.

        QProcess *myProcess = new QProcess(this);
        myProcess->startDetached(program);
        myProcess->waitForFinished(-1);
        qDebug() << myProcess->errorString();
        }
    }

}

void MainWindow::on_pushButton_calc_clicked()
{
    QString program = "calc";
    QProcess *myProcess = new QProcess(this);
    myProcess->startDetached(program);
    myProcess->waitForFinished(-1);
    qDebug() << myProcess->errorString();
}

void MainWindow::on_pushButton_new_row_clicked()
{
    Dialog *form = new Dialog(this); // Выделяем память на новую форму.
    form->show(); // Показываем эту форму.

    //Соединяем сигнал с формы и слот на главной форме.
    connect(form,
            SIGNAL(push_task(QTableWidgetItem*,
                             QTableWidgetItem*,
                             QTableWidgetItem*,
                             QTableWidgetItem*)),
            this,
            SLOT(get_task(QTableWidgetItem*,
                          QTableWidgetItem*,
                          QTableWidgetItem*,
                          QTableWidgetItem*))
            );
}

void MainWindow::get_task(QTableWidgetItem *name_task, //Название задачи
                          QTableWidgetItem *path_task, //Путь до программы, которую задача должна запускать.
                          QTableWidgetItem *date_task, // Дата ближайшего запуска задачи
                          QTableWidgetItem *period_task // Период, с которым должна запускатьтся задача.
                          )
{
    int current_row = tableWidget->rowCount(); // Запоминаем текущую строчку, с которой работаем.

    tableWidget->setRowCount(tableWidget->rowCount()+1);//Выделяем под новую строку память, увеличивая число ячеек таблицы на одну.
    // И заносим все данные в таблицу.
    tableWidget->setItem(current_row, 0, name_task);
    tableWidget->setItem(current_row, 1, path_task);
    tableWidget->setItem(current_row, 2, date_task);
    tableWidget->setItem(current_row, 3, period_task);
}
