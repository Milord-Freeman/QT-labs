#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    setupUi(this);
    setCentralWidget(tableWidget);
}

void MainWindow::table_getted(int a, int b)
{
    tableWidget->setColumnCount(a);
    tableWidget->setRowCount(b);
}

void MainWindow::on_action_addRow_triggered()
{
   tableWidget->setRowCount(tableWidget->rowCount()+1);
}

void MainWindow::on_action_addColumn_triggered()
{
    tableWidget->setColumnCount(tableWidget->columnCount()+1);
}

void MainWindow::on_action_newTable_triggered()
{
    Dialog *w = new Dialog;
    connect(w,SIGNAL(tableGetted(int,int)), this, SLOT(table_getted(int, int)));
    w->show();
}

void MainWindow::on_action_delRow_triggered()
{
    tableWidget->removeRow(tableWidget->rowCount()-1);
}

void MainWindow::on_action_delColumn_triggered()
{
    tableWidget->removeColumn(tableWidget->columnCount()-1);
}

void MainWindow::on_action_save_triggered()
{
    QFile *file = new QFile("table.txt"); //Создаем файл для сохранения.
    if (!file->open(QIODevice::WriteOnly | QIODevice::Text)) //Проверяем, возможно ли открыть его для записи.
        return; // И в случае, если нет - то выходим из функции.
    QTextStream out(file); // Подключаем файл к потоку текстовому.
    out.setCodec(QTextCodec::codecForName("windows-1251")); // Выставляем кодировку для WIN
    for (int i=0; i<tableWidget->rowCount(); i++)
    {
        out << ";"; //Разделитель новой строки.
        for (int j=0; j<tableWidget->columnCount() ;j++)
        {
            out << "," << tableWidget->item(i,j)->text(); //Разделитель нового итема.
        }
    }
    file->close(); //Закрываем файл.
}

void MainWindow::on_action_load_triggered()
{
    QFile *file = new QFile("table.txt");
    if (!file->open(QIODevice::ReadOnly | QIODevice::Text)) //Проверяем, возможно ли открыть его для чтения.
        return;
    QTextStream input(file);
    QString all_data = input.readAll(); // Считываем все данные в одну большую строку.
    qDebug() << all_data;
    int rowCount = 0;
    int columnCount = 0;
    for (int i=0;i<all_data.length();i++)
        if (all_data[i]==",") rowCount++; else if (all_data[i]==";") columnCount++;
    tableWidget->clear();
    tableWidget->setRowCount(rowCount);
    tableWidget->setColumnCount(columnCount);

    QTableWidgetItem *item = new QTableWidgetItem;
    QString curr_item = 0;
    int curRow = -1; int curColumn = -1;

    for (int flag = 0; flag<all_data.length();flag++)
    {
        if (all_data[flag] == ";") curRow++; item->setText(curr_item); curr_item.clear();
        if (all_data[flag] == ",") curColumn++; item->setText(curr_item); curr_item.clear();
        curr_item.push_back(all_data[flag]);
     }

    file->close();
}
