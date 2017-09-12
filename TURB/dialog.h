#ifndef DIALOG_H
#define DIALOG_H

#include "ui_dialog.h"
#include <QTableWidgetItem>
#include <QDateTime>
#include <QString>

class Dialog : public QDialog, private Ui::Dialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);

signals:
    push_task(QTableWidgetItem *name_task,
              QTableWidgetItem *path_task,
              QTableWidgetItem *date_task,
              QTableWidgetItem *period_task
            );
private slots:
    void on_buttonBox_accepted();
};

#endif // DIALOG_H
