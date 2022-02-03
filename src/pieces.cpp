#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "pieces.h"

using namespace sf;
using namespace std;

Piece::~Piece() {};

// void Piece::printPiece(){};

Empty::Empty()
{
    color = Color::White;
};

Empty::Empty(Color c)
{
    color = c;
}

Empty::~Empty(){};

void Empty::printPiece()
{
    cout << "This is space is empty.\n";
}



Pawn::Pawn() {};

Pawn::Pawn(Color c)
{
    color = c;
}

Pawn::~Pawn(){};

void Pawn::printPiece()
{
    cout << "This is a pawn.\n";
}


King::King() {};

King::King(Color c)
{
    color = c;
}

King::~King(){};

void King::printPiece()
{
    cout << "This is a king.\n";
}