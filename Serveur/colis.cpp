#include "colis.h"
#include <QJsonObject>
#include <QJsonDocument>

Colis::Colis()
{

}

Colis::Colis(float longueur, float largeur, float hauteur)
{
    mLength = longueur;
    mWidth = largeur;
    mHeight = hauteur;
}

QByteArray Colis::toJson()
{
    QJsonObject o;
    o["destinataire"] = mCustomer;
    o["destination"] = mCountry;
    o["type"] = mType;
    o["longueur"] = mLength;
    o["largeur"] = mWidth;
    o["hauteur"] = mHeight;
    o["poids"] = mWeight;

    QJsonDocument d(o);
    QByteArray sJson = d.toJson(QJsonDocument::Compact);

    return sJson;
}

void Colis::fromJson(QByteArray s)
{
    QJsonObject o = QJsonDocument::fromJson(s).object();
    mCustomer = o["destinataire"].toString();
    mCountry = o["destination"].toString();
    mType = o["type"].toString();
    mLength = o["longueur"].toDouble();
    mWidth = o["largeur"].toDouble();
    mHeight = o["hauteur"].toDouble();
    mWeight = o["poids"].toDouble();
}

QString Colis::getPays()
{
    return mCountry;
}

float Colis::getPoids()
{
    return mWeight;
}

float Colis::getVolume()
{
    return mWidth * mLength * mLength;
}

QString Colis::getDestinataire()
{
    return mCustomer;
}

/*
Colis Colis::operator+(const Colis& p) const
{
    Colis res = Colis(mWeight + p.mWeight);

    return res;
}*/

void Colis::setDestinataire(const QString &newDestinataire)
{
    mCustomer = newDestinataire;
}

void Colis::setPays(const QString &newPays)
{
    mCountry = newPays;
}

void Colis::setPoids(const float &newPoids)
{
    mWeight = newPoids;
}


QString Colis::toString()
 {
       QString s = QString("Longueur:%1 Largeur:%2, Hauteur: %3, Destinataire:%4 , Pays: %5 , Poids: %6 , Type : %7").arg(mLength).arg(mWidth).arg(mHeight).arg(mCustomer).arg(mCountry).arg(mWeight).arg(mType);
       return s;

}

