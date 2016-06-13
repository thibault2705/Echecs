// JoueurNoir.cxx

#include <iostream>

#include "Joueur.h"
#include "JoueurNoir.h"
#include "Piece.h"
#include "Soldats.h"

using namespace std;

JoueurNoir::JoueurNoir()
{
	//cout << "JoueurNoir cree" << endl;
	
	my_pieces[0] = new Tour(true, false);
	my_pieces[1] = new Cavalier(true, false);
	my_pieces[2] = new Fou(true, false);
	my_pieces[3] = new Roi(false);
	my_pieces[4] = new Reine(false);
	my_pieces[5] = new Fou(false, false);
	my_pieces[6] = new Cavalier(false, false);
	my_pieces[7] = new Tour(false, false);
	my_pieces[8] = new Pion(1, 7, false);
	my_pieces[9] = new Pion(2, 7, false);
	my_pieces[10] = new Pion(3, 7, false);
	my_pieces[11] = new Pion(4, 7, false);
	my_pieces[12] = new Pion(5, 7, false);
	my_pieces[13] = new Pion(6, 7, false);
	my_pieces[14] = new Pion(7, 7, false);
	my_pieces[15] = new Pion(8, 7, false);
}

JoueurNoir::~JoueurNoir()
{
	//cout << "JoueurNoir detruit" << endl;
}
