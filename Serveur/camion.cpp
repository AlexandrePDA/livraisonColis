#include "camion.h"
#include <QFile>


Camion::Camion(QString destination)
{
    mDestination = destination;
    mMaxPoids = 40000;
    mMaxVolume = 40000000;
}

float Camion::totalVolume()
{
    float volume = 0;
    for(int i=0; i<mColis.size(); i++)
    {
        volume += mColis[i].getVolume();
    }

    return volume;
}

float Camion::totalPoids()
{
    float poids = 0 ;
    for(int i =0; i<mColis.size(); i++)
    {
        poids += mColis[i].getPoids();
    }

    return poids;

}

void Camion::bonTransport()
{
    QString fichier = "bonTransport.txt"; // dans le build

    QFile file(fichier);

    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
    // écrire dans le fichier en utilisant un flux :
    QTextStream out(&file);
    for(int i = 0; i < mColis.size(); i++)
    {
         out << mColis[i].toString() << "\n" ;
    }
    // Fermer le fichier
    file.close();
    }

}

bool Camion::addColis(Colis c)
{
    if(this->totalPoids() + c.getPoids() > mMaxPoids  || this->totalVolume() + c.getVolume() > mMaxVolume )
    {
        return false;
    }
    mColis.push_back(c);
    return true;
}

QString Camion::getDestination()
{
    return mDestination;
}
