#ifndef _BOARD_H
#define _BOARD_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "pieces.h"

using namespace std;
using namespace sf;


class Tile {
    public:
        int index;  // location on board
        bool isEmpty;
        RectangleShape rect;
        Tile();
        Tile(int index, int x, int y, int size);
        ~Tile();
        void setColor(Color color);
        void setOutline(Color color, int t);
        int getOutlineThickness();
        int getIndex();
        // Called by piece, not board. Checks if color
        // matches and is open.
        bool isOpen(Color color);
        void printLocation();
        Color getColor();
};

class Board : public Tile {
    private:
        void buildBoard(int size, int offset);    // called by constructor
    public:
        vector<Tile> tiles;
        Board();
        Board(int size, int offset);
        ~Board();
        void drawBoard(RenderWindow& window);
        void selectTile(int index, RenderWindow& window);
};

#endif