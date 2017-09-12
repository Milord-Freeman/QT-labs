#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include "dialog.h"

//Библиотеки для работы с таблицей
#include <QTableWidget>
#include <QTableWidgetItem>
//Библиотеки для сохранения в файл и загрузки
#include <QFile>
#include <QString>
#include <QStringList>
#include <QSpinBox>
#include <QTextStream>
#include <QTextCodec>
#include <QDebug>

class MainWindow : public QMainWindow, private Ui::MainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
private slots:
    void table_getted(int a, int b); //

    void on_action_addRow_triggered();
    void on_action_addColumn_triggered();
    void on_action_newTable_triggered();
    void on_action_delRow_triggered();
    void on_action_delColumn_triggered();
    void on_action_save_triggered();
    void on_action_load_triggered();
};

#endif // MAINWINDOW_H
