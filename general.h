#ifndef GENERAL_H
#define GENERAL_H
#include <QObject>
#include <QThread>
#include "setparameteraccount.h"
#include "okdeskapi.h"
#include "informdisplay.h"

class General : public QObject
{
    Q_OBJECT
    setParameterAccount *setWindow;
    OkdeskApi *okdeskApi;
    QThread thOkdeskApi;
    InformDisplay *informDisplay;
public:
    General();
    ~General();
};

#endif // GENERAL_H
