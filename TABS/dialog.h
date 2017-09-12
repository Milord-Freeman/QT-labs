#ifndef DIALOG_H
#define DIALOG_H

#include "ui_dialog.h"

class Dialog : public QDialog, private Ui::Dialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
private slots:
    void on_buttonBox_accepted();
signals:
    void tableGetted(int a, int b); // СПециальный слот для передачи инфы по ширине и высоте.
};

#endif // DIALOG_H
