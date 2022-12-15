#include "widget.h"
#include "./ui_widget.h"
#include <QSettings>
#include <QRandomGenerator>
#include "colis.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);


    mSock = new QTcpSocket(this);
    connect(mSock,SIGNAL(connected()),this,SLOT(imConnected()));
    connect(mSock,SIGNAL(disconnected()),this,SLOT(imDisconnected()));
    connect(mSock,SIGNAL(readyRead()),this,SLOT(dataIsComing()));



    // lien avec doc settings.ini
    QSettings settings("settings.ini", QSettings::IniFormat);
    ui->cbDestination->addItems(settings.value("pays").toString().split(","));
    QStringList types = settings.childGroups();
    ui->cbTaille->addItems(types);
    for(QString s : types)
    {
        settings.beginGroup(s); // on entre
        float largeur = settings.value("largeur").toFloat(); // on recupere
        float longueur = settings.value("longueur").toFloat();
        float hauteur = settings.value("hauteur").toFloat();
        Colis colis(largeur, longueur, hauteur , s);
        mType[s] = colis;
        settings.endGroup(); // on sort
    }

    connect(ui->pbValider, SIGNAL(clicked()), this, SLOT(sendColis()));
    mSock->connectToHost("127.0.0.1", 9090);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::imConnected()
{
    mSock->write("I'm connected !");
}

void Widget::imDisconnected()
{

}

void Widget::dataIsComing()
{
    qDebug() << mSock->readAll();
}

void Widget::connectToServer()
{
    mSock->connectToHost("127.0.0.1",9090);
}

void Widget::sendColis()
{
    mSock->write(sendInfosColis().toJson());
}


Colis Widget::sendInfosColis()
{

    // cree colis
   Colis c = mType[ui->cbTaille->currentText()];
   c.setDestinataire(ui->leNom->text());
   c.setPays(ui->cbDestination->currentText());
   c.setPoids(setWeight());

    qDebug() <<c.toString();

    return c;
}

float Widget::setWeight()
{
    float poids = (float)QRandomGenerator::global()->bounded(10,5000)/100;
    return poids;
}





