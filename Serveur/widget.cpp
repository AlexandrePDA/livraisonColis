#include "widget.h"
#include "./ui_widget.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QTableWidget>
#include <QFile>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    mServer = new QTcpServer(this);
    connect(mServer,SIGNAL(newConnection()),this,SLOT(clientConnected()));
    mServer->listen(QHostAddress::Any,9090);


    mListCamions.append(new Camion("France"));
    mListCamions.append(new Camion("Allemagne"));
    mListCamions.append(new Camion("Espagne"));

}

Widget::~Widget()
{
    delete ui;
}

void Widget::clientConnected()
{
     QTcpSocket* sockClient = mServer->nextPendingConnection();
     mClients << sockClient;
     connect(sockClient,SIGNAL(readyRead()),this,SLOT(dataIsComing()));
     connect(sockClient,SIGNAL(disconnected()),this,SLOT(clientDisconnected()));
     qDebug() << "qqun frappe à la porte" << sockClient->peerAddress().toString();
     sockClient->write("Coucou");
}
void Widget::clientDisconnected()
{
    QTcpSocket* sock = (QTcpSocket*)sender();
    mClients.removeAll(sock);
    sock->deleteLater();
}
void Widget::dataIsComing()
{
    QTcpSocket* sock = (QTcpSocket*)sender();
    QByteArray data = sock->readAll();

    QJsonObject oRecu = QJsonDocument::fromJson(data).object();
    qDebug() <<oRecu;

    if(oRecu.isEmpty() == false)
    {
    Colis c;
    c.fromJson(data);
    addColisUI(c.getPays(), c);
    }

}

void Widget::addColisUI(QString destination, Colis c)
{

    // dispatch dans UI selon destination
    QTableWidget* tw = NULL;
    if(c.getPays() == "France")
    tw=ui->twFrance;

    if(c.getPays() == "Espagne")
    tw=ui->twEspagne;

    if(c.getPays() == "Allemagne")
    tw=ui->twAllemagne;

    // ajout par ligne de destinataire, poids, volume dans ui
    if (tw !=  NULL)
    {
    int Ligne = tw->rowCount();
    tw->setRowCount(Ligne + 1);
    tw->setCellWidget(Ligne, 0, new QLabel(QString(c.getDestinataire())));
    tw->setCellWidget(Ligne, 1, new QLabel(QString::number(c.getPoids())));
   tw->setCellWidget(Ligne, 2, new QLabel(QString::number(c.getVolume())));
    }

    // gere les camions selon poids et volume
    for(int i=0; i<mListCamions.size(); i++)
    {
        if(c.getPays() == mListCamions[i]->getDestination())
        {
            if(!mListCamions[i]->addColis(c))
            {
                // camion plein -> on supprime
                tw->clear();
                tw->setRowCount(0);
                 // bon de commande à creer avec bonTransport()
                mListCamions[i]->bonTransport();
                // on retire celui plein
                mListCamions.removeAt(i);
                // on cree un nouveau camion avec destination et on y ajoute le colis
                qDebug() << "nouveau camion";
                Camion* camion = new Camion(c.getPays());
                mListCamions.append(camion);
                camion->addColis(c);
                return;
            }
        }
    }


}









