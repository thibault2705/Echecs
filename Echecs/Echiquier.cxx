/** 
 * Mise en oeuvre de Echiquier.h
 *
 * @file Echiquier.cxx
 */

#include <iostream>
// A besoin de la declaration de la classe
#include "Echiquier.h"
#include "Piece.h"
#include "Soldats.h"
#include <string>
#include <typeinfo>
#include <vector>

using namespace std;

/**
 * Constructeur par d�faut.
 * Initialise � vide l'echiquier.
 */
Echiquier::Echiquier()
{
    for(int i=0;i<64;i++)
        m_cases[i]=NULL;
}


/**
 * Recupere la piece situee sur une case.
 *
 * @param x un entier entre 1 et 8
 * @param y un entier entre 1 et 8
 *
 * @return 0 si aucune piece n'est sur cette case et un pointeur
 * vers une piece sinon.
 */
Piece* Echiquier::getPiece( int x, int y )
{
    int n = (x-1) + (y-1) * 8;
    // (4-1) + (2-1)* 8 = 3 + 8 = 11
    
    if(m_cases[n]!=NULL)
        return m_cases[n];
    else
        return 0;
}

  
/**
 * Place une piece sur l'echiquier, aux coordonnees specifiees dans la piece.
 *
 * @param p un pointeur vers une piece
 *
 * @return 'true' si le placement s'est bien passe, 'false' sinon
 * (case occupee, coordonnees invalides, piece vide )
 */
bool Echiquier::placer( Piece* p )
{
    int n = (p->x()-1) + (p->y()-1) * 8;
    
    if (m_cases[n]==NULL)
    {
        m_cases[n] = p;
        return true;
    }
    else
        return false;
}


/**
 * Deplace une piece sur l'echiquier, des coordonnees specifiees
 * dans la piece aux coordonnees x,y. 
 *
 * @param p un pointeur vers une piece
 * @param x un entier entre 1 et 8
 * @param y un entier entre 1 et 8
 *
 * @return 'true' si le placement s'est bien passe, 'false' sinon
 * (case occupee, coordonnees invalides, piece vide, piece pas
 * presente au bon endroit sur l'echiquier)
 */
bool Echiquier::deplacer( Piece* p, int x2, int y2 )
{
    int x1 = p->x();
    int y1 = p->y();
    
    if(p!=NULL)
    {
        enleverPiece(x1,y1);
        enleverPiece(x2,y2);
        p->move(x2,y2);
        placer(p);
        
        return true;
    }
    else
        return false;
}


/**
 * Enleve la piece situee sur une case (qui devient vide).
 *
 * @param x un entier entre 1 et 8
 * @param y un entier entre 1 et 8
 *
 * @return 0 si aucune piece n'est sur cette case et le pointeur
 * vers la piece enlevee sinon.
 */
Piece* Echiquier::enleverPiece( int x, int y )
{
    int n = (x-1) + (y-1) * 8;
    
    if(m_cases[n]!=NULL)
    {
        Piece * p = m_cases[n];
        m_cases[n]=NULL;
        return p;
    }
    else
        return 0;
}

Roi* Echiquier::getRoi(bool isWhite)
{
    Roi *pRoi;
    
    for(int i=0;i<64; i++)
    {
        pRoi=dynamic_cast<Roi *>(m_cases[i]);
        if(pRoi!=NULL && pRoi->isWhite()==isWhite)
            return pRoi;
    }
    
    return 0;
}

/**
* Tester si le Roi est echec ... mais je n'arrive pas a faire
*/
int
Echiquier::estEchec(bool isWhite)
{
    Roi *pRoi = getRoi(isWhite);
    
    int tabX[4];
    int tabY[4];
    int nbCases = 0;
      
    int nbEchec = 0;
    
    for(int i=0; i<64; i++) //sauvegarder les cases valides du Roi
    {   
        if(pRoi->mouvementValid(*this, pRoi->x(), pRoi->y()-1))
        {
            tabX[nbCases] = pRoi->x();
            tabY[nbCases] = pRoi->y()-1;
            nbCases++;
        }
        
        if(pRoi->mouvementValid(*this, pRoi->x(), pRoi->y()+1))
        {
            tabX[nbCases] = pRoi->x();
            tabY[nbCases] = pRoi->y()+1;
            nbCases++;
        }
        
        if(pRoi->mouvementValid(*this, pRoi->x()-1, pRoi->y()))
        {
            tabX[nbCases] = pRoi->x()-1;
            tabY[nbCases] = pRoi->y();
            nbCases++;
        }
        
        if(pRoi->mouvementValid(*this, pRoi->x()+1, pRoi->y()))
        {
            tabX[nbCases] = pRoi->x()+1;
            tabY[nbCases] = pRoi->y();
            nbCases++;
        }
    }
    
    if(nbCases>0)
    {
        for(int i=0; i<64; i++)
        {
            if(m_cases[i]!=NULL)
            {
                for(int k=0; k<nbCases; k++)
                {
                    if(m_cases[i]->mouvementValid(*this, tabX[k], tabY[k]))
                        nbEchec++;
                }
            }
        }
    }
    
    return nbEchec;
}

/**
* Tester si joueur peut faire roque
*/
bool
Echiquier::roque(bool isWhite, bool isLeft)
{
    int nbCases=0;
    //if(estEchec(isWhite)>0) return false;
    //else 
    //{
        int nRoi, nTour;
    
        // prendre la position pour tester
        if(isWhite)
        {
            nRoi = 3;        
            (isLeft) ? nTour=0 : nTour=7;
        }
    
        else
        {
            nRoi = 59;
            (isLeft) ? nTour= 56 : nTour=63;
        }
       
        Roi * pRoi = dynamic_cast<Roi *>(m_cases[nRoi]);
        Tour * pTour = dynamic_cast<Tour *>(m_cases[nTour]);
        
        if(pRoi!=NULL && pTour!=NULL 
            && pRoi->isWhite()==isWhite && pTour->isWhite()==isWhite)
        {
            int nbDeplacementRoi = pRoi->getNbDeplacement(); 
            int nbDeplacementTour = pTour->getNbDeplacement();
    
            if(nbDeplacementRoi==0 && nbDeplacementTour==0) // tester si Roi et Tour n'ont pas deja deplacer            
            {                                                   
                int xTour, yTour, xRoiMouve, xTourMove;
                (isWhite) ? yTour=1 : yTour=8;
        
                int debut, fin; // pour faire la boucle ci-dessous
                if(isLeft)
                {
                    xTour=1;
                    debut = xTour;
                    fin = 4;
                    
                    xTourMove = 3;
                    xRoiMouve = 2;  
                }
            
                else
                {
                    xTour=8;
                    debut = 4;
                    fin = xTour;
                    
                    xTourMove = 5;
                    xRoiMouve = 6;
                }
        
                for(int i=debut+1; i<fin; i++) // tester s'il y a quelques pieces 
                    if(getPiece(i, yTour)!=0)  // entre Roi et Tour
                        nbCases++;
                        
                if(nbCases==0)
                {
                   
                    pTour->move(xTourMove, yTour);
                    enleverPiece(4, yTour);
       
                    pRoi->move(xRoiMouve, yTour);
                    enleverPiece(xTour, yTour);
                    
                    placer(pRoi);
                    placer(pTour);    
        
                    pRoi->augmenterNbDeplacement();
                    pTour->augmenterNbDeplacement();
                    return true;
                }
                else return false;       
            }
    
            else return false;
        }
        else return false;
    //}
}

/**
 * Tester si c'est une promotion
 */
bool 
Echiquier::testerPromotion(int x, int y)
{
    Pion * pPion = dynamic_cast<Pion *>(getPiece(x,y));
    
    if(pPion!=NULL)
    {
        int xPion, yPion;
        if(pPion->isWhite() && y==8)
        {
            return true;
        }
        else if(pPion->isBlack() && y==1)
        {   
            return true;
        }
        else return false;
    }
    else return false;
}

/**
 * Tester si c'est une prise en passant
 */
bool 
Echiquier::testerPriseEnPassant(int x, int y)
{
    Pion * pPion = dynamic_cast<Pion *>(getPiece(x,y));
    
    if(pPion!=NULL)
    {
        if(pPion->isWhite())
            return (getPiece(x, y-1)!=0 && getPiece(x, y-1)->isWhite()!=pPion->isWhite()
                    && getPiece(x, y-2)!=0 && getPiece(x, y-2)->isWhite()==pPion->isWhite());
        else 
            return (getPiece(x, y+1)!=0 && getPiece(x, y+1)->isWhite()!=pPion->isWhite()
                    && getPiece(x, y+2)!=0 && getPiece(x, y+2)->isWhite()==pPion->isWhite());    
    }
    else return false;
}

/**
* Faire promotion
*/
void
Echiquier::promotion(bool isWhite, int choix, int x, int y)
{
    int n = (x-1) + (y-1) * 8;
    
    enleverPiece(x, y);

    switch(choix)
    {
        case 1:
            m_cases[n] = new Reine(x, y, isWhite);
            break;
        case 2:
            m_cases[n] = new Tour(x, y, isWhite);
            break;
        case 3:
            m_cases[n] = new Fou(x, y, isWhite);
            break;
        case 4:
            m_cases[n] = new Cavalier(true, isWhite);
            break;       
    }   
}

/**
 * Affiche l'echiquier avec des # pour les cases noires et . pour
 * les blanches si elles sont vides, et avec B pour les pieces
 * blanches et N pour les pieces noires.
 */
void Echiquier::affiche()
{
    cout << endl << "      1   2   3   4   5   6   7   8 " << endl;
    cout << "    +---+---+---+---+---+---+---+---+" << endl;
 
    for ( int y = 1; y <= 8; ++y )
    {
        cout << "  " << y << " |";
        for ( int x = 1; x <= 8; ++x )
	      {
	           string c;
	           Piece* p = getPiece(x, y);
               
	           if ( p == 0 ) 
	               c = ( ( x + y ) % 2 ) == 0 ? " # |" : " . |";
	           else
               {
                   c = " " + p->getSymbol() + " |";
               }
	           cout << c;
	       }
         cout << " " << y << endl;
         cout << "    +---+---+---+---+---+---+---+---+" << endl;
     }
     cout << "      1   2   3   4   5   6   7   8 " << endl; 
}

  

