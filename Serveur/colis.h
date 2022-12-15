#ifndef COLIS_H
#define COLIS_H

#include <QWidget>

class Colis
{
public:
    Colis();
    Colis(float longueur, float largeur, float hauteur);
    void setPays(const QString &newPays);
    void setDestinataire(const QString &newDestinataire);
    QString toString();
    void setPoids(const float &newPoids);
    QByteArray toJson();
    void fromJson(QByteArray);
    QString getPays();
    float getPoids();
    float getVolume();
    QString getDestinataire();
    //Colis operator+(const Colis& p) const;

protected:
    float mWidth;
    float mLength;
    float mHeight;
    float mWeight;
    QString mCountry;
    QString mCustomer;
    QString mType;


};

#endif // COLIS_H
