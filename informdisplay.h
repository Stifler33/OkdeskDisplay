#ifndef INFORMDISPLAY_H
#define INFORMDISPLAY_H

#include <QMainWindow>
#include <okdeskapi.h>
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
    Ui::InformDisplay *ui;
    //QPair<int, FormTask> numberAndTask;
    QList<QPair<int, FormTask*>> qlistTask;
public slots:
    void acceptTasks(QList<Tasks> _listTasks);
};
#endif // INFORMDISPLAY_H
