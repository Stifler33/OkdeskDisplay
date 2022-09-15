#ifndef OKDESKAPI_H
#define OKDESKAPI_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QIODevice>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QTimer>
#include <QMediaPlayer>
struct Tasks
{
    int number;
    QString status;
    QString theme;
    QString company;
    QString color;    
    bool operator == (Tasks a)
    {
        if (a.theme != theme) return false;
        if (a.company != company) return false;
        if (a.number != number) return false;
        return true;
    }
    bool operator != (Tasks a)
    {
        if (a.theme != theme) return true;
        if (a.company != company) return true;
        if (a.number != number) return true;
        return false;
    }
};
class OkdeskApi : public QObject
{
    Q_OBJECT
QString accountApi;
QString accountName;
QString url = "https://%1.okdesk.ru/api/v1/%2/?api_token=%3%4";
QNetworkAccessManager *netManager;
QNetworkRequest getHelpStatusTask;
QNetworkRequest getAllTask;
QNetworkRequest getNewTasks;
QJsonDocument jsonDoc;
QMediaPlayer *player;
struct commandApi{
    QString issuesList = "issues/list";
    QString statusTaskOpen = "&status_codes[]=opened";
    QString getHelpStatusesTask = "issues/statuses";
};
commandApi command;


void parsingJson();
public:
    //explicit OkdeskApi(QObject *parent = nullptr);
    OkdeskApi();
    QTimer *timerRefresh;
    QList<Tasks> listTasks;
signals:
void newTasks(QList<Tasks> _listTasks);
void sendResultConnect(QString result);
void signalSend(QNetworkRequest _request);

public slots:

void setAccountSettings(QString name, QString api);
void getResponse(QNetworkReply *replyNetwork);
void sendRequest(QNetworkRequest _request);
void requestNewTasks();
};
Q_DECLARE_METATYPE(QList<Tasks>);
#endif // OKDESKAPI_H
