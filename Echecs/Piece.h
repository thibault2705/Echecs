/** 
 * Header de Piece.cxx
 *
 * @file Piece.h
 */
#ifndef PIECE_H
#define PIECE_H

#include <stdlib.h>
#include <string>

using namespace std;

class Echiquier;
/**
 * Declaration d'une classe mod�lisant une piece de jeu d'echec.
 */
class Piece 
{
  protected:
      int m_x;
      int m_y;
      bool m_white;
      int m_nbDeplacement;
  
  public:
      Piece();
      Piece(int x, int y, bool white);
      virtual ~Piece();
      void init( int x, int y, bool white);
      void move( int x, int y);
      int x();
      int y();
      bool isWhite();
      bool isBlack();
      
      void setCouleur(bool isWhite);
      virtual void affiche() const;
      virtual string getSymbol() const;
      virtual bool mouvementValid(Echiquier &e, int x, int y) const;
      
      bool memeEndroit(Piece &p);
      void augmenterNbDeplacement();
      int getNbDeplacement() const;
}; 

#endif // !defined Piece_h

