/** 
 * Mise en oeuvre de Piece.h
 *
 * @file Piece.cxx
 */

// A besoin de la declaration de la classe
#include "Piece.h"
#include "Echiquier.h"
#include <iostream>
using namespace std;

Piece::Piece()
{
  //cout << "Une piece creee" << endl;
  // ne fait rien => objet instancie mais non valide.
}

Piece::Piece(int x, int y, bool isWhite)
{
    //cout << "Une piece creee" << endl;
    m_x = x;
    m_y = y;
    m_white = isWhite;
    m_nbDeplacement = 0;
}

Piece::~Piece()
{
    //cout << "Une piece detruite" << endl;
}

void
Piece::init( int x, int y, bool white )
{
  m_x = x;
  m_y = y;
  m_white = white;
}

void
Piece::move( int x, int y )
{
  m_x = x;
  m_y = y;
}

int
Piece::x()
{
  return m_x;
}

int
Piece::y()
{
  return m_y;
}

bool
Piece::isWhite()
{
  return m_white;
}

bool
Piece::isBlack()
{
    return !m_white;
}

void
Piece::setCouleur(bool isWhite)
{
    m_white=isWhite;  
}

void
Piece::affiche() const
{
    cout << "Piece: x=" << m_x << " y=" << m_y << " " << endl;
}

string
Piece::getSymbol() const
{
    return ((m_white) ? "B" : "N");
}

bool 
Piece::mouvementValid(Echiquier &e, int x, int y) const
{
    Piece *p = e.getPiece(x,y);
    
    int n = (x-1) + (y-1) * 8;
    // return true
    // si la destination est vide
    // ou a une piece d'autre couleur
    return ((p==0 || (p!=0 && p->isWhite()!=m_white)) 
              && n>=0 && n<64);
}

bool 
Piece::memeEndroit(Piece &p)
{
    return (m_x==p.x() && m_y==p.y());
}

void 
Piece::augmenterNbDeplacement()
{
    m_nbDeplacement++;
}

int 
Piece::getNbDeplacement() const
{
    return m_nbDeplacement;
}