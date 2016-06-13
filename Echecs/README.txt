==========================================================================================
------------------------------------------------------------------------------------------
    ______________  ______________
   / ____/ ____/ / / / ____/ ____/
  / __/ / /   / /_/ / __/ / /     
 / /___/ /___/ __  / /___/ /___   
/_____/\____/_/ /_/_____/\____/   
                                  
Projet AP3 PO
--------------------------------
Professeur Joris SANSEN
Etudiante Anh Thu PHAN
Classe LINF14, PUFHCM

------------------------------------------------------------------------------------------
==========================================================================================


PRESENTATION

Le jeu d’échecs oppose deux joueurs de part et d’autre d’un plateau ou tablier appelé échiquier composé de 
soixante-quatre cases . et # nommées les cases blanches et les cases noires. Les joueurs jouent à tour de 
rôle en déplaçant l'une de leurs seize pièces (ou deux pièces en cas de roque), symbole en MAJUSCUL pour 
le camp des blancs, symbole en minuscul pour le camp des noirs. Chaque joueur possède au départ un roi, 
une dame, deux tours, deux fous, deux cavaliers et huit pions. Le but du jeu est d'infliger à son adversaire 
un échec et mat, une situation dans laquelle le roi d'un joueur est en prise sans qu'il soit possible d'y remédier.

(Dans ce projet, je n’arrive pas a faire “echec et mat”. Par cette raison, qui mange avant le roi de sa concurrant
devient champion)


DEPLACEMENT DES PIECES

- Le fou, la tour et la dame sont des pièces à longue portée (ou pièces de lignes) : elles peuvent se déplacer 
le long de lignes. Chaque camp possède deux fous : ils se déplacent toujours sur les cases d'une même couleur, 
en diagonales; chaque camp possède donc un fou de cases blanches, et un fou de cases noires.

- Le roi se déplace d'une seule case à la fois, il dispose d'une règle de déplacement spéciale : le roque.

- Le cavalier ne peut être intercepté par aucune des pièces autour de lui, il saute jusqu'à sa case d'arrivée.

- Le pion peut se déplacer sur les cases marquées d'une croix (sans pouvoir y capturer une pièce adverse), et peut
capturer sur les cases marquées d'un rond (sans pouvoir s'y déplacer si elles sont vides).

Chacun des pions peut se déplacer de deux cases à la fois lors de son tout premier déplacement.


REGLES SPECIALES

-- ROQUE
Le roque consiste à déplacer en un seul coup le roi et l'une des tours. Il y a deux façons de roquer :
	+ avec le roi et la tour de la colonne 1
	+ avec le roi et la tour de la colonne 8
Les conditions suivantes sont nécessaires pour pouvoir roquer :
+ aucune pièce ne se trouve entre le roi et la tour concernée ;
+ le roi et la tour concernée n'ont encore jamais joué ;
+ le roi n'est pas en échec ;
	+ la case traversée par le roi n'est contrôlée par aucune pièce adverse.


—- PRISE EN PASSANT
La prise en passant peut intervenir lorsqu'un camp vient de jouer un pion de deux cases (c'est possible lors 
d'un tout premier déplacement du pion) et, ce faisant, évite la confrontation avec un pion adverse.


— PROMOTION
La promotion du pion consiste à le transformer, au choix du joueur et indépendamment des pièces antérieurement 
perdues, en dame, en tour, en fou ou en cavalier de même couleur lorsqu'il atteint la dernière rangée de 
l'échiquier (la huitième pour les blancs et la première pour les noirs).

