#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "pieces.h"
#include "gamemanager.h"

using namespace std;
using namespace sf;

Tile::Tile() {};

Tile::Tile(int i, int x, int y, int size)
{
    index = i;
    rect.setSize(Vector2f(size, size));
    rect.setPosition(x, y);
}

Tile::~Tile() {};

void Tile::setColor(Color color)
{
    rect.setFillColor(color);
}

void Tile::setOutline(Color color, int t)
{
    rect.setOutlineColor(color);
    rect.setOutlineThickness(t);
}

int Tile::getOutlineThickness()
{
    return rect.getOutlineThickness();
}

// void Tile::updatePiece(Piece *p)
// {
//     cout << "Calling updatePiece...\n";
//     p.printPiece();
//     piece = p;
//     cout << "Assigned...\n";
//     piece->printPiece();
// }

// void Tile::updatePiece()
// {
//     piece = NULL;
// }

// Piece* Tile::getPiece()
// {
//     return piece;
// }


void GameManager::setTiles(int t_size, int offset)
{
    int row = 0;
    int col = 0;
    int x, y = 0;

    Color c1 = Color::Black;
    Color c2 = Color::White;

    for(int i = 0; i < 64; i++)
    {
        if(col == 8)
        {
            col = 0;
            row++;
            Color tmp = c1;
            c1 = c2;
            c2 = tmp;
        }
        x = (col*t_size)+offset;
        y = (row*t_size)+offset;
        Tile tile(i, x, y, t_size);
        if(col%2)
        {
            tile.setColor(c1);
        }
        else
        {
            tile.setColor(c2);
        }
        col++;
        board.push_back(tile);
    }
}

void GameManager::drawBoard(RenderWindow& window)
{
    cout << "Drawing board..." << endl;
    window.clear(bgColor);
    for(int i = 0; i < 64; i++)
    {
        window.draw(board[i].rect);
    }
}

void GameManager::setPieces()
{
    //pass
}

GameManager::GameManager()
{
    Color bg(128,128,128);
    bgColor = bg;
}

GameManager::GameManager(Color color)
{
    bgColor = color;
}

GameManager::~GameManager() {};

void GameManager::startGame(int t_size, int offset, RenderWindow& window)
{
    setTiles(t_size, offset);
    drawBoard(window);
    window.display();
}

void GameManager::selectSpace(int index, RenderWindow& window)
{
    window.clear(bgColor);
    Color none(0,0,0,0);
    if(hi == index)
    {
        board[index].setOutline(none, 0);
        hi = -1;
    }
    else
    {
        if (0 <= hi)
            board[hi].setOutline(none, 0);
        board[index].setOutline(Color::Red, 2);
        hi = index;
    }
    drawBoard(window);
    window.draw(board[index].rect);
    window.display();
}

// Piece& GameManager::getPiece(int i)
// {
//     return board[i].piece;
// }

// void GameManager::selectPiece(int location, Piece *p)
// {
//     cout << "Selecting Piece...\n";
//     board[location].getPiece(p);
//     p.printPiece();
// }

// void GameManager::movePiece(int location, Piece& p)
// {
//     board[location].updatePiece(p);
// }