#ifndef FORMTASK_H
#define FORMTASK_H

#include <QWidget>
#include "okdeskapi.h"

namespace Ui {
class FormTask;
}

class FormTask : public QWidget
{
    Q_OBJECT

public:
    explicit FormTask(QWidget *parent = nullptr);
    ~FormTask();
    void showTask(QList<Tasks> listTask);
private:
    Ui::FormTask *ui;
};

#endif // FORMTASK_H
