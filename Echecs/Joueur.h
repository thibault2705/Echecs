// Joueur.h

#ifndef JOUEUR_H
#define JOUEUR_H

#include <iostream>
#include "Echiquier.h"
#include "Piece.h"
using namespace std;

class Joueur {
	protected: // pour utiliser dans 2 joueurs herites
		bool m_white;
		Piece *my_pieces[16];
	
	public:
		Joueur();
		Joueur(bool isWhite);
		virtual ~Joueur();
		
		bool isWhite();
		bool isBlack();
		
		void affiche();
		void placePieces(Echiquier &e);
		
		bool operator==(Joueur &j) const;
		void changeCouleur(bool isWhite);
		
};

#endif