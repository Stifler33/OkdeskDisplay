#ifndef INFORMDISPLAY_H
#define INFORMDISPLAY_H

#include <QMainWindow>
#include <okdeskapi.h>
#include <QList>
#include "formtask.h"

QT_BEGIN_NAMESPACE
namespace Ui { class InformDisplay; }

QT_END_NAMESPACE


class InformDisplay : public QMainWindow
{
    Q_OBJECT

public:
    InformDisplay(QWidget *parent = nullptr);
    ~InformDisplay();

private:
    QList<Tasks> listTasksID;    
    QList<Tasks>::iterator findTask(int num);
    Ui::InformDisplay *ui;
    //QPair<int, FormTask> numberAndTask;
    QMap<int, FormTask*> mapTask;
    bool thereIsTask(int numberTask);
public slots:
    void acceptTasks(QList<Tasks> _listTasks);
};
#endif // INFORMDISPLAY_H
