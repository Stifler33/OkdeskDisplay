#ifndef SETPARAMETERACCOUNT_H
#define SETPARAMETERACCOUNT_H

#include <QWidget>
namespace Ui {
class setParameterAccount;
}

class setParameterAccount : public QWidget
{
    Q_OBJECT

public:
    setParameterAccount();
    ~setParameterAccount();
    Ui::setParameterAccount *ui;
public slots:
    void getParameters();
    void showResultConnect(QString result);
signals:
    void callConnect(QString name, QString api);
    void connectCompleted();
};

#endif // SETPARAMETERACCOUNT_H
