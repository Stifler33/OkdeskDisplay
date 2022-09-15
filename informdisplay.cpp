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

QList<Tasks>::iterator InformDisplay::findTask(int num)
{
    for (auto task = listTasksID.begin(); task != listTasksID.end(); task++)
    {
        if (task->number == num) return task;
    }
    return listTasksID.end();
}

bool InformDisplay::thereIsTask(int numberTask)
{
    for (auto task : listTasksID)
    {
        if (task.number == numberTask) return true;
    }
    return false;
}

void InformDisplay::acceptTasks(QList<Tasks> _listTasks)
{
    bool thereIsNewTask = false;
    bool taskEdit = false;

    if (listTasksID.isEmpty())
    {
        listTasksID = _listTasks;
        thereIsNewTask = true;
    }else{
        for (auto newTask : _listTasks)
        {
            auto i = findTask(newTask.number);
            if (i != listTasksID.end())
            {
                i->theme = newTask.theme;
                i->company = newTask.company;
            }
        }
    }

    if (thereIsNewTask)
    {
        for (auto newTask : listTasksID)
        {
            FormTask *form = new FormTask;
            form->showTask(newTask);
            ui->verticalLayout->addWidget(form);
            mapTask.insert(newTask.number, form);
        }
    }
}
