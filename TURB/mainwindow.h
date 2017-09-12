#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include "dialog.h"
#include <QString>
#include <QProcess>
#include <QDebug>
#include <QTimer>
#include <QDateTime>
#include <QTableWidget>
#include <QTableWidgetItem>

class MainWindow : public QMainWindow, private Ui::MainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    QTimer *tmr;

public slots:
    void get_task(QTableWidgetItem *name_task,
                  QTableWidgetItem *path_task,
                  QTableWidgetItem *date_task,
                  QTableWidgetItem *period_task);
private slots:
    void run_program();
    void on_pushButton_calc_clicked();
    void on_pushButton_new_row_clicked();
};

#endif // MAINWINDOW_H
