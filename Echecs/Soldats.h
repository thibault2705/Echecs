// Roi.h

#ifndef SOLDATS_H
#define SOLDATS_H

#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

class Echiquier;

class Roi : public Piece {
	public:
      Roi(bool isWhite);
      
      virtual string getSymbol() const;
      virtual bool mouvementValid(Echiquier &e, int x, int y) const;
};

class Fou : virtual public Piece {
   public:
      Fou();
      Fou(bool isLeft, bool isWhite); // pour initialiser une piece Fou
      Fou(int x, int y, bool isWhite);
      
      virtual string getSymbol() const;
      virtual bool mouvementValid(Echiquier &e, int x, int y) const;
      
};

class Tour : virtual public Piece {
   public:
      Tour();
      Tour(bool isLeft, bool isWhite);  
      Tour(int x, int y, bool isWhite);
      
      virtual string getSymbol() const;
      virtual bool mouvementValid(Echiquier &e, int x, int y) const;
};

class Reine : public Fou, public Tour {
   public:
      Reine(bool isWhite);
      Reine(int x, int y, bool isWhite);
      
      virtual string getSymbol() const;
      virtual bool mouvementValid(Echiquier &e, int x, int y) const;
};

class Cavalier : virtual public Piece {
   public:
      Cavalier(bool isLeft, bool isWhite);
      Cavalier(int x, int y, bool isWhite);
      
      virtual string getSymbol() const;
      virtual bool mouvementValid(Echiquier &e, int x, int y) const;
};

class Pion : virtual public Piece {
   public:
      Pion(int x, int y, bool isWhite);
      
      virtual string getSymbol() const;
      virtual bool mouvementValid(Echiquier &e, int x, int y) const;
};

#endif