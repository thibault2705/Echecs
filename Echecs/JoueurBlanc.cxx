// JoueurBlanc.cxx

#include <iostream>

#include "Joueur.h"
#include "JoueurBlanc.h"
#include "Piece.h"
#include "Soldats.h"

using namespace std;

JoueurBlanc::JoueurBlanc()
{
	//cout << "JoueurBlanc cree" << endl;
	
	my_pieces[0] = new Tour(true, true);
	my_pieces[1] = new Cavalier(true, true);
	my_pieces[2] = new Fou(true, true);
	my_pieces[3] = new Roi(true);
	my_pieces[4] = new Reine(true);
	my_pieces[5] = new Fou(false, true);
	my_pieces[6] = new Cavalier(false, true);
	my_pieces[7] = new Tour(false, true);
	my_pieces[8] = new Pion(1, 2, true);
	my_pieces[9] = new Pion(2, 2, true);
	my_pieces[10] = new Pion(3, 2, true);
	my_pieces[11] = new Pion(4, 2, true);
	my_pieces[12] = new Pion(5, 2, true);
	my_pieces[13] = new Pion(6, 2, true);
	my_pieces[14] = new Pion(7, 2, true);
	my_pieces[15] = new Pion(8, 2, true);
}

JoueurBlanc::~JoueurBlanc()
{
	//cout << "JoueurBlanc detruit" << endl;
}


