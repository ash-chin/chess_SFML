#ifndef _GAMEMANAGER_H
#define _GAMEMANAGER_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "pieces.h"

using namespace std;
using namespace sf;


class Tile {
    private:
        int index = 0;
        RectangleShape rect;
        friend class GameManager;
    public:
        // Piece *piece = NULL;
        Tile();
        Tile(int i, int x, int y, int size);
        ~Tile();
        void setColor(Color color);
        void setOutline(Color color, int t);
        int getOutlineThickness();
        // void updatePiece(Piece p);
        // void updatePiece();
        // Piece* getPiece();
};

class GameManager {
    private:
        Color bgColor;
        void setTiles(int t_size, int offset);
        void drawBoard(RenderWindow& window);
        void setPieces();
    public:
        vector<Tile> board;
        int hi = -1;
        GameManager();
        GameManager(Color color);
        ~GameManager();
        void startGame(int t_size, int offset, RenderWindow& window);
        void selectSpace(int index, RenderWindow& window);
        // Piece& getPiece(int i);
        // void selectPiece(int location, Piece *p);
        // void movePiece(int location, Piece& p);
};




#endif
