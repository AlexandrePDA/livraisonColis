# livraisonColis

## _Objectifs_

Developper un programme permettant de gérer les colis de Noel pour un marchand en ligne.
Le but est de gérer la livraison en répartissant des colis dans le bon camion.
3 types de colis sont disponibles, chacun d’eux aura des dimensions en largeur, longueur et hauteur spécifiques, paramétrables dans un fichier de configuration. Chaque colis aura également un poids aléatoire défini lors de sa création. Ces colis auront pour destination un pays parmi les trois suivants : (France, Espagne, Allemagne)
- Créer une interface de génération de commande permettant de choisir un type de 
colis, le nom du client et le pays de destination. Le poids, lui sera une valeur générée
aléatoirement entre 0.1kg et 50.0kg.
- Le colis est envoyé (en JSON) à un serveur de remplissage des camions qui 
recensera toutes les demandes.
- Le serveur affichera dans une interface la liste de colis pour chaque camion.

Un camion peut stocker 40 m3 et/ou 40 tonnes maximum, il faut donc faire partir le 
camion (et commencer une nouvelle liste) avant d’atteindre l’une des deux limites.
Pour que le camion parte et laisse sa place à un autre, un fichier de bon de 
transport avec la liste de tous les colis et leurs dimensions est crée.




## Installation

- Cloner le code
- Utiliser QT Creator avec la version correspondante dans le CMakeList.txt.
- Remplir le fichier settings.ini comme ceci :



```
[General]
pays="Allemagne,France,Espagne"
[Petit]
	longueur=10
	largeur=10
	hauteur=10
[Moyen]
	longueur=50
	largeur=50
	hauteur=50
[Grand]
	longueur=100
	largeur=100
	hauteur = 100
```
