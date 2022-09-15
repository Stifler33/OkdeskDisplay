#include "okdeskapi.h"

OkdeskApi::OkdeskApi()
{
    netManager = new QNetworkAccessManager(this);
    timerRefresh = new QTimer(this);
    connect(netManager, &QNetworkAccessManager::finished, this, &OkdeskApi::getResponse);
    connect(timerRefresh, &QTimer::timeout, this, &OkdeskApi::requestNewTasks);
    player = new QMediaPlayer(this);

    player->setVolume(100);
}

void OkdeskApi::setAccountSettings(QString name, QString api)
{
    accountName = name;
    accountApi = api;
    getHelpStatusTask.setUrl(QUrl(url.arg(accountName, command.getHelpStatusesTask, accountApi, "")));
    emit signalSend(getHelpStatusTask);
}

void OkdeskApi::requestNewTasks()
{
    getNewTasks.setUrl(QUrl(url.arg(accountName, command.issuesList, accountApi, command.statusTaskOpen)));
    emit signalSend(getNewTasks);
}

void OkdeskApi::getResponse(QNetworkReply *replyNetwork)
{


    if (replyNetwork->error() == QNetworkReply::NoError){
        if (replyNetwork->request() == getHelpStatusTask)
        {
            emit sendResultConnect("connect completed");
            //requestNewTasks();
            timerRefresh->setInterval(1000);
            timerRefresh->start();
        }
        if (replyNetwork->request() == getNewTasks)
        {
            jsonDoc = QJsonDocument::fromJson(replyNetwork->readAll());
            parsingJson();
        }
    }else{
        emit sendResultConnect(replyNetwork->errorString());
    }

}

void OkdeskApi::sendRequest(QNetworkRequest _request)
{
    netManager->get(_request);
}

void OkdeskApi::parsingJson()
{
    if (jsonDoc.isArray())
    {
        QJsonArray array = jsonDoc.array();
        QList<Tasks> buffer;
        for (auto i = array.begin(); i != array.end(); i++)
        {
            Tasks tasks;
            QJsonObject obj;
            if (i->isObject()){
                obj = i->toObject();
                if (!obj.empty()){
                    tasks.number = obj["id"].toInt();
                    tasks.status = obj["status"].toObject()["name"].toString();
                    tasks.color = obj["status"].toObject()["color"].toString();
                    tasks.theme = obj["title"].toString();
                    tasks.company = obj["company"].toObject()["name"].toString();
                }
            }
            buffer.push_back(tasks);
        }
        if (buffer != listTasks)
        {          
            listTasks = buffer;
            emit newTasks(listTasks);
            if (!buffer.isEmpty())
            {
                player->setMedia(QUrl::fromLocalFile("message.mp3"));
                player->play();
            }else{
                player->setMedia(QUrl::fromLocalFile("message_not.mp3"));
                player->play();
            }
        }

    }
}






















