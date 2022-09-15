#include "informdisplay.h"
#include "./ui_informdisplay.h"
InformDisplay::InformDisplay(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::InformDisplay)
{
    ui->setupUi(this);
}

InformDisplay::~InformDisplay()
{
    delete ui;
}

void InformDisplay::acceptTasks(QList<Tasks> _listTasks)
{
    for (auto task : _listTasks)
    {
        FormTask *formTask = new FormTask;
        foreach (auto _task, qlistTask)
        {
            if (_task.first == task.number)
            {
                continue;
            }
            qlistTask.push_back(QPair<int, FormTask*>{task.number, formTask});
            formTask->showTask(task);
            ui->verticalLayout->addWidget(formTask);
        }
    }
}
