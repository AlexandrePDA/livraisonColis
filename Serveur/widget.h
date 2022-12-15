#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QList>
#include "camion.h"
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

private slots:
    void clientConnected();
    void clientDisconnected();
    void dataIsComing();
    void addColisUI(QString destination, Colis c);


private:
    Ui::Widget *ui;
    QTcpServer* mServer;
    QList<QTcpSocket*> mClients;
    QList<Camion*> mListCamions;

};
#endif // WIDGET_H
