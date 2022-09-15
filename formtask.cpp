#include "formtask.h"
#include "ui_formtask.h"

FormTask::FormTask(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormTask)
{
    ui->setupUi(this);
}

FormTask::~FormTask()
{
    delete ui;
}

void FormTask::showTask(Tasks task)
{
        ui->id->setText(QString("%1").arg(task.number));
        ui->company->setText(task.company);
        ui->theme->setText(task.theme);
}
