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
    QList<Tasks> oldListTask;
    QList<Tasks>::iterator findTask(int num);
    QList<Tasks>::iterator findTask(QList<Tasks> &list,int num);
    Ui::InformDisplay *ui;
    //QPair<int, FormTask> numberAndTask;
    QMap<int, FormTask*> mapTask;
    bool thereIsTask(int numberTask);
    void addNewFormTask(Tasks newTask);
    void addNewFormTask(QList<Tasks> listNewTask);

public slots:
    void acceptTasks(QList<Tasks> newListTask);
};
#endif // INFORMDISPLAY_H
