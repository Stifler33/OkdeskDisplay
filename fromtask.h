#ifndef FROMTASK_H
#define FROMTASK_H

#include <QWidget>
#include "okdeskapi.h"

namespace Ui {
class FromTask;
}

class FromTask : public QWidget
{
    Q_OBJECT

public:
    explicit FromTask(QWidget *parent = nullptr);
    ~FromTask();    
    void showTask(QList<Tasks> _listTask);
private:
    Ui::FromTask *ui;
};

#endif // FROMTASK_H
