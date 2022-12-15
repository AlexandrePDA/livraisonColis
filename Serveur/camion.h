#ifndef CAMION_H
#define CAMION_H

#include <QWidget>
#include <QString>
#include <QList>
#include "colis.h"

class Camion{

public:
    Camion(QString destination);
    float totalVolume();
    float totalPoids();
    void bonTransport();
    bool addColis(Colis);
    QString getDestination();

private:
    QString mDestination;
    QList<Colis> mColis;
    float mMaxPoids;
    float mMaxVolume;

};



#endif // CAMION_H
