#ifndef COLIS_H
#define COLIS_H


#include <QWidget>
#include <QString>

class Colis
{
public:
    Colis();
    Colis(float longueur, float largeur, float hauteur, QString type);
    QByteArray toJson();
    void fromJson(QByteArray);
    float volume();
    void setDestinataire(const QString &newDestinataire);
    void setPays(const QString &newPays);
    void setPoids(const float &newPoids);
    QString toString();

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
