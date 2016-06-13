/** 
 * Programme test de Piece
 *
 * @file testPiece.cxx
 */

// Utile pour l'affichage
#include <iostream>

#include "Echiquier.h"
#include "Piece.h"
#include "Soldats.h"
#include "Joueur.h"
#include "JoueurBlanc.h"
#include "JoueurNoir.h"

// Pour utiliser les flux de iostream sans mettre "std::" tout le temps.
using namespace std;

Echiquier e;
 

JoueurBlanc joueurB;
JoueurNoir joueurN;
Joueur joueurCourant = joueurN;
Joueur champion;
bool endGame = false;

/**
 * Afficher nom de joueurCourant a l'instance
 */
void annoncerJoueur()
{
    cout << endl;
    if(joueurCourant.isWhite()) 
        cout << "Au BLANC de jouer (symbols en MAJUSCULS)" << endl << endl;
    else 
        cout << "Au NOIR de jouer (symbols en minusculs)" << endl << endl;
}

/**
 * Return nom du joueur
 */
string getNomJoueur(bool isWhite)
{
    return (isWhite) ? "Joueur BLANC": "Joueur NOIR";
}


/**
 * Afficher champion
 */
void afficherChampion(bool isWhite)
{
    cout << endl << "CONGRATULATION! " << getNomJoueur(isWhite) << " gagne le jeux!" << endl;
}

/**
 * Effacer et afficher echiquier
 */
void clear_screen()
{
    system("clear");
    cout << "..............:::ECHECS:::.............." << endl << endl;
    e.affiche();
    if(!endGame)
        annoncerJoueur();
}

/**
 * Changer le joueurCourant
 */
void passerJoueur()
{
    (joueurCourant.isWhite()) ? (joueurCourant.changeCouleur(false))
                                     : (joueurCourant.changeCouleur(true));
} 

/**
 * Afficher la choix de promotion
 */
void choisirPromotion(bool isWhite, int x, int y)
{
    int choix;
    
    while (choix<1 || choix>4)
    {
        clear_screen();
        cout << "PROMOTION" << endl;
        cout << "--Changer cette Pion(" << x << ", " << y << ") en ...?" << endl;
        cout << "     (1) - Reine" << endl;
        cout << "     (2) - Tour" << endl;
        cout << "     (3) - Fou" << endl;
        cout << "     (4) - Cavalier" << endl;
        cout << "--Votre choix: ";
        cin >> choix;
    }
    e.promotion(isWhite, choix, x, y);
    
}

/**
 * Placer piece
 */
void jouer() 
{    
    int x, y;
    Piece *p;
    do {
        clear_screen();
        cout << "--Choisir piece (x y):  ";
        cin >> x >> y;
        
        p = e.getPiece(x,y);
    } while(p==NULL);
    
    if(p!=0 && 
        ((p->isBlack() && joueurCourant.isBlack()) || 
            (p->isWhite() && joueurCourant.isWhite())))
            {
                cout << "PIECE   :  " << p->getSymbol() << endl;
                cout << "Déplacé :  " << p->getNbDeplacement() << " fois" << endl;
                int xn, yn;
                cout << "--Placer a (x y) : ";
                cin >> xn >> yn;
                
                if (p->mouvementValid(e, xn, yn))
                {   
                    e.deplacer(p, xn, yn);
                    p->augmenterNbDeplacement();
                    
                    Roi * pRoi = dynamic_cast<Roi *>(e.getPiece(xn, yn));
                    if(pRoi!=NULL) endGame=true;
                    
                    else if(e.testerPromotion(xn, yn))
                            choisirPromotion(p->isWhite(), xn, yn);
                    
                    else if(e.testerPriseEnPassant(xn, yn))
                    {
                        cout << "enlever" << endl;
                        
                        e.enleverPiece(xn, y);
                    }
                                             
                    
                }
            } 
}

/**
 * Afficher le choix de roque
 */
void choisirRoque(bool isWhite)
{
    int choix;
    bool isLeft;
    
    while(choix<1 || choix>2)
    {
        clear_screen();
        cout << "ROQUE" << endl;
        cout << "--Roque Roi avec Tour a gauche(1) ou a droite(2) ?" << endl;
        cin >> choix;
    }
    (choix==1) ? (isLeft=true) : (isLeft=false); 
       
    e.roque(isWhite, isLeft); 
}

/**
 * Capituler
 */

void choisirCapituler(bool isWhite)
{
    endGame=true;
    passerJoueur();
}

/**
 * Menu play
 */
void menuPlay()
{
    int choix;
    
    while(choix<1 || choix>3)
    {
        cout << "\t  +--------------------+" << endl;
        cout << "\t  |  1 - Placer piece  |" << endl;
        cout << "\t  |  2 - Roque         |" << endl;
        cout << "\t  |  3 - Capituler     |" << endl;
        cout << "\t  +--------------------+" << endl;
   
        cout << "Votre choix: ";
        cin >> choix;
        clear_screen();
    }
    
    switch (choix)
    {
        case 1: jouer(); break;
        case 2: choisirRoque(joueurCourant.isWhite()); break;
        case 3: choisirCapituler(joueurCourant.isWhite()); break;
    } 
} 

/**
 * Programme principal
 */
int main( int argc, char** argv )
{   
    joueurB.placePieces(e);
    joueurN.placePieces(e);
    
    
    clear_screen();  
    
    while (!endGame)
    {
        menuPlay();
        passerJoueur();
        clear_screen();
    }
    
    afficherChampion(joueurCourant.isBlack());
    
    return 0;
    // les objets definis dans cette fonction sont automatiquement d�truits.
}
