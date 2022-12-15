#ifndef WIDGET_H
#define WIDGET_H


#include <QWidget>
#include <QString>
#include <QTcpSocket>
#include <QMap>
#include <QJsonObject>
#include <QJsonDocument>
#include "colis.h"


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    QString toString();


private slots:
    void imConnected();
    void imDisconnected();
    void dataIsComing();
    void connectToServer();
    void sendColis();
    Colis sendInfosColis();
    float setWeight();



private:
    Ui::Widget *ui;
    QTcpSocket* mSock;
    QMap<QString, Colis> mType;
};
#endif // WIDGET_H
