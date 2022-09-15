#include "general.h"

General::General()
{
    setWindow = new setParameterAccount;
    okdeskApi = new OkdeskApi;
    informDisplay = new InformDisplay;
    okdeskApi->moveToThread(&thOkdeskApi);
    connect(setWindow, &setParameterAccount::callConnect, okdeskApi, &OkdeskApi::setAccountSettings);
    connect(okdeskApi, &OkdeskApi::sendResultConnect, setWindow, &setParameterAccount::showResultConnect);
    connect(okdeskApi, &OkdeskApi::signalSend, okdeskApi, &OkdeskApi::sendRequest);

    //если произошло успешное подключение то закрываем окно подключения и запускаем информационный дисплей
    connect(setWindow, &setParameterAccount::connectCompleted, informDisplay, &InformDisplay::show);
    connect(setWindow, &setParameterAccount::connectCompleted, setWindow, &setParameterAccount::close);


    connect(okdeskApi, &OkdeskApi::newTasks, informDisplay, &InformDisplay::acceptTasks);

    thOkdeskApi.start();
    setWindow->show();
}

General::~General()
{
    thOkdeskApi.quit();
    thOkdeskApi.wait();
}
