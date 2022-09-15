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
    QString str = "%1 %2 %3";
    ui->textEdit->clear();
    for (auto task : _listTasks)
    {
        ui->textEdit->append(str.arg(task.number).arg(task.theme, task.company));
    }

}
