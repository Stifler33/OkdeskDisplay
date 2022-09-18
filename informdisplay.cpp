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
    for (auto task = oldListTask.begin(); task != oldListTask.end(); task++)
    {
        if (task->number == num) return task;
    }
    return oldListTask.end();
}

QList<Tasks>::iterator InformDisplay::findTask(QList<Tasks> &list, int num)
{
    for (auto task = list.begin(); task != list.end(); task++)
    {
        if (task->number == num) return task;
    }
    return list.end();
}

bool InformDisplay::thereIsTask(int numberTask)
{
    for (auto task : oldListTask)
    {
        if (task.number == numberTask) return true;
    }
    return false;
}

void InformDisplay::addNewFormTask(Tasks newTask)
{
    oldListTask.push_back(newTask);
    FormTask *form = new FormTask;
    form->showTask(newTask);
    ui->verticalLayout->addWidget(form);
    mapTask.insert(newTask.number, form);
}

void InformDisplay::addNewFormTask(QList<Tasks> listNewTask)
{
    foreach(auto newTask, listNewTask)
    {
        oldListTask.push_back(newTask);
        FormTask *form = new FormTask;
        form->showTask(newTask);
        ui->verticalLayout->addWidget(form);
        mapTask.insert(newTask.number, form);
    }
}

void InformDisplay::acceptTasks(QList<Tasks> newListTask)
{//Просматриваем поступившие заявки
   // bool thereIsNewTask = false;
    //bool taskEdit = false;
//если QList с текущими заявками пустой то копируем в него новые заявки и выводим на экран
    if (oldListTask.isEmpty())
    {
        oldListTask = newListTask;
        addNewFormTask(oldListTask);
       // thereIsNewTask = true;
    }else{//если не пустой - просматриваем то что поступило и обновляем информацию
        foreach(auto oldTask, oldListTask)//идем по старому списку заявок
        {
            auto oldTaskFromTheNewList = findTask(newListTask, oldTask.number);//ищем в новом списке старую заявку
            if (oldTaskFromTheNewList != newListTask.end())//если нашли то обновляем в ней информацию
            {
                oldTask.company = oldTaskFromTheNewList->company;
                oldTask.theme = oldTaskFromTheNewList->theme;
                mapTask[oldTask.number]->showTask(*oldTaskFromTheNewList);
            }else{//если не нашли то удаляем
                //mapTask[oldTaskFromTheNewList->number]->close();
                ui->verticalLayout->removeWidget(mapTask[oldTaskFromTheNewList->number]);
                mapTask.erase(mapTask.find(oldTaskFromTheNewList->number));
            }
        }


        for (auto newTask : newListTask)//идем по новому списку заявок
        {
            if (!thereIsTask(newTask.number))
            {
                addNewFormTask(newTask);
            }
        }
    }


}
