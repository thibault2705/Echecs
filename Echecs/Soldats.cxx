// Soldat.cxx

#include "Piece.h"
#include "Soldats.h"
#include "Echiquier.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

// ROI (VUA)

Roi::Roi(bool isWhite)
:Piece(4, (isWhite) ? 1 : 8, isWhite)
{
          
}
      
string 
Roi::getSymbol() const
{
	return ((m_white) ? "R" : "r");
} 

bool 
Roi::mouvementValid(Echiquier &e, int x, int y) const
{
    if(Piece::mouvementValid(e, x, y)) // aller ou enlever une piece
    {
        int dx, dy;
        dx = abs(m_x - x);
        dy = abs(m_y - y);
        Piece *p = e.getPiece(x,y);
    
        return ((dx==1 && dy==0) || (dx==0 && dy==1));
    }
    
    else return false; // case vide ou destination ayant une piece de même couleur
    
}

// FOU (TUONG)

Fou::Fou()
{
  
}
Fou::Fou(bool isLeft, bool isWhite) // pour initialiser une piece Fou
:Piece((isLeft) ? 3:6, (isWhite) ? 1:8, isWhite)
{
  
}
      
Fou::Fou(int x, int y, bool isWhite)
:Piece(x, y, isWhite)
{
            
}
      
string 
Fou::getSymbol() const
{
  return ((m_white) ? "F" : "f");
}
      
bool 
Fou::mouvementValid(Echiquier &e, int x, int y) const
{
    if(Piece::mouvementValid(e, x, y)) // aller ou enlever une piece
    { 
        int dx, dy;
        dx = abs(m_x - x);
        dy = abs(m_y - y);
        Piece *p = e.getPiece(x,y);
   
        if((dx==dy) && (dx>0)) // diagonale
        {
            if(y>m_y) // diagonale en bas
            {
                if(x>m_x) // a droite
                {
                    for(int i=m_x+1; i<x; i++)
                        for(int j=m_y+1; j<y; j++)
                            if(e.getPiece(i,j)!=0) return false;
                }
                
                else if(x<m_x) // a gauche
                {
                    for(int i=m_x-1; i>x; i--)
                        for(int j=m_y+1; j<y; j++)
                            if(e.getPiece(i,j)!=0) return false;
                }
                
                return true;
            }
            
            else if (y<m_y) // diagonale en haut
            {
                if(x>m_x) // a droite
                {
                    for(int i=m_x+1; i<x; i++)
                        for(int j=m_y-1; j>y; j--)
                            if(e.getPiece(i,j)!=0) return false;
                }
                
                else if(x<m_x) // a gauche
                {
                    for(int i=m_x-1; i>x; i--)
                        for(int j=m_x-1; j>y; j--)
                            if(e.getPiece(i,j)!=0) return false;
                }
                
                return true;
            }
            
            else return false;
        }
        
        else return false;
    }
    
    else return false;   
}

// TOUR (XE)
Tour::Tour()
{
  
}

Tour::Tour(bool isLeft, bool isWhite) 
:Piece((isLeft) ? 1:8, (isWhite) ? 1:8, isWhite)
{
          
} 
      
Tour::Tour(int x, int y, bool isWhite)
:Piece(x, y, isWhite)
{
            
}
      
string 
Tour::getSymbol() const
{
    return ((m_white) ? "T" : "t");
}

bool 
Tour::mouvementValid(Echiquier &e, int x, int y) const
{
    if(Piece::mouvementValid(e, x, y)) // aller ou enlever une piece
    {
        int dx, dy;
        dx = abs(m_x - x);
        dy = abs(m_y - y);
        Piece *p = e.getPiece(x,y);

        int debut, fin;
        if(dx==0 && dy>0) // vertical
        {
            if(m_y>y) 
            {
                debut = y;
                fin = m_y;
            }
            
            else
            {
                debut = m_y;
                fin = y;
            }
            
            for(int j=debut+1; j<fin; j++) // tester s'il y a une piece entre 2 position           
                if(e.getPiece(x,j)!=0) return false;
            
            return true; // sinon c'est valid
        }
        
        else if(dx>0 && dy==0) // horizontal
        {
            if(m_x>x) 
            {
                debut = x;
                fin = m_x;
            }
            
            else
            {
                debut = m_x;
                fin = x;
            }
            
            for(int i=debut+1; i<fin; i++) // tester s'il y a une piece entre 2 position 
                if(e.getPiece(i,y)!=0) return false;
            
            return true; // sinon c'est valid
        }
        
        else return false; // autre cas
    }
    
    else return false; // case vide ou destination ayant une piece de même couleur
}


// REINE (HAU)

Reine::Reine(bool isWhite)
:Piece(5, (isWhite) ? 1 : 8, isWhite), 
Fou(5, (isWhite) ? 1 : 8, isWhite), 
Tour(5, (isWhite) ? 1 : 8, isWhite)   
{
          
}

Reine::Reine(int x, int y, bool isWhite)
:Piece(x, y, isWhite), 
Fou(x, y, isWhite), 
Tour(x, y, isWhite)
{
    
}
      
string 
Reine::getSymbol() const
{
    return ((m_white) ? "Q" : "q");
}
 
bool 
Reine::mouvementValid(Echiquier &e, int x, int y) const
{
    return (Fou::mouvementValid(e, x, y) || Tour::mouvementValid(e, x, y));
}

// CALAVIER (NGUA)

Cavalier::Cavalier(bool isLeft, bool isWhite)
:Piece((isLeft) ? 2:7, (isWhite) ? 1:8, isWhite) 
{
          
}

Cavalier::Cavalier(int x, int y, bool isWhite)
:Piece(x, y, isWhite)
{
    
}
      
string 
Cavalier::getSymbol() const 
{
    return ((m_white) ? "C" : "c");
}

bool  
Cavalier::mouvementValid(Echiquier &e, int x, int y) const
{
    if(Piece::mouvementValid(e, x, y))
    {
        int dx, dy;
        dx = abs(m_x - x);
        dy = abs(m_y - y);
        Piece *p = e.getPiece(x,y);
    
        // aller ou enlever une pieces
        return ((dx==1 && dy == 2) || (dx==2 && dy==1));
    }
    
    else return false; // case vide ou destination ayant une piece de même couleur    
}


// PION (TOT)

Pion::Pion(int x, int y, bool isWhite) 
:Piece(x, y, isWhite)
{
          
}

string 
Pion::getSymbol() const 
{
    return ((m_white) ? "P" : "p");
}

bool 
Pion::mouvementValid(Echiquier &e, int x, int y) const
{
    if(Piece::mouvementValid(e, x, y)) // aller ou enlever une piece
    {
        int dx, dy;
        
        dx = x - m_x; 
        (m_white) ? (dy = y - m_y) : (dy = m_y - y);
        
        if(e.getPiece(x,y) == 0) // avancer 1 ou 2
        {
            if(dx==0)
            {
                if(m_nbDeplacement==0) // avancer 1 ou 2 pas pour la 1ere fois
                    return (dy==1 || dy==2);
            
                else                // avancer 1 pas pour les autres fois
                    return (dy==1);
            }
            
            else if((dx==1 || dx ==-1) && dy==1)
            {
                if(m_white)
                    return (e.getPiece(x,y-1)!=0 && e.getPiece(x,y-1)->isWhite()!=m_white  
                        && e.getPiece(x,y-2)!=0 && e.getPiece(x,y-2)->isWhite()==m_white);
                
                else
                    return (e.getPiece(x,y+1)!=0 && e.getPiece(x,y+1)->isWhite()!=m_white  
                        && e.getPiece(x,y+2)!=0 && e.getPiece(x,y+2)->isWhite()==m_white);
            }
            
            else return false;
        } 
                
        else if(e.getPiece(x,y)->isWhite() != m_white) // enlever une piece en diagonale
            return ((dx==1 || dx==-1) && dy==1);
        
        else return false; // case vide ou destination ayant une piece de même 
    }
    else return false;
}
