#include "fromtask.h"
#include "ui_fromtask.h"

FromTask::FromTask(QWidget *parent) : QWidget(parent), ui(new Ui::FromTask)
{
    ui->setupUi(this);
}

FromTask::~FromTask()
{
    delete ui;
}

void FromTask::showTask(QList<Tasks> _listTask)
{

}
