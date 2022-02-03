#ifndef _PIECES_H
#define _PIECES_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

using namespace sf;


class Piece {
    protected:
        Color color;
    public:
        virtual ~Piece();
        virtual void printPiece() {};
}; 

class Empty : public Piece {
    public:
        Empty();
        Empty(Color c);
        ~Empty();
        void printPiece();
    
};

class Pawn : public Piece {
    public:
        Pawn();
        Pawn(Color c);
        ~Pawn();
        void printPiece();
};

class King : public Piece {
    public:
        King();
        King(Color c);
        ~King();
        void printPiece();
};


#endif