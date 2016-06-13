// Joueur.cxx

#include <iostream>
#include "Joueur.h"

using namespace std;

Joueur::Joueur()
{
	//cout << "Joueur cree" << endl;
}

Joueur::Joueur(bool isWhite)
{
	//cout << "Un joueur cree" << endl;
	m_white = isWhite;
}

Joueur::~Joueur()
{
	//cout << "Joueur detruit" << endl;
}

bool
Joueur::isWhite()
{
	return m_white;
}

bool
Joueur::isBlack()
{
	return !m_white;
}
void
Joueur::affiche()
{
	cout << "-----" << endl;
	for(int i=0;i<16;i++)
	{
		my_pieces[i]->affiche();
		cout << my_pieces[i]->getSymbol() << endl;
	}
}

void 
Joueur::placePieces(Echiquier &e)
{
	for(int i=0;i<16;i++)
	{
		e.placer(my_pieces[i]);
	}
}

bool
Joueur::operator==(Joueur &j) const
{
	return m_white == j.m_white;
}

void
Joueur::changeCouleur(bool isWhite)
{
	m_white=isWhite;
}