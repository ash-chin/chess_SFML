#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "board.h"

using namespace std;
using namespace sf;


Tile::Tile(){}

Tile::Tile(int i, int x, int y, int size)
{
    index = i;
    rect.setSize(Vector2f(size, size));
    rect.setPosition(x, y);
    isEmpty = true;
}

Tile::~Tile() {};

void Tile::setColor(Color color)
{
    rect.setFillColor(color);
}

int Tile::getIndex() {return index;}

bool Tile::isOpen(Color color)
{
    // update later
    return isEmpty;
}

void Tile::printLocation()
{
    cout << "index: " << index << endl;
}

Color Tile::getColor()
{
    return rect.getFillColor();
}

void Board::setBoard(int size, int offset)
{
    int row = 0;
    int col = 0;
    int x, y = 0;
    // int size = 60;

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
        x = (col*size)+offset;
        y = (row*size)+offset;
        Tile tile(i, x, y, size);
        if(col%2)
        {
            tile.setColor(c1);
        }
        else
        {
            tile.setColor(c2);
        }
        col++;
        tiles.push_back(tile);
    }
}

Board::Board()
{
    setBoard(60, 0);
}

Board::Board(int size, int offset)
{
    setBoard(size, offset);
}


Board::~Board(){};

void Board::drawBoard(RenderWindow& window)
{
    cout << "Drawing board..." << endl;
    for(int i = 0; i < 64; i++)
    {
        tiles[i].rect.setOutlineThickness(0);
        window.draw(tiles[i].rect);
    }
}

void Board::selectTile(int index, RenderWindow& window)
{
    Color bgColor(128,128,128);
    window.clear(bgColor);
    if(tiles[index].rect.getOutlineThickness())
    {
        drawBoard(window);
        window.display();
    }
    else
    {
        drawBoard(window);
        tiles[index].rect.setOutlineThickness(2);
        tiles[index].rect.setOutlineColor(Color::Red);
        window.draw(tiles[index].rect);
        window.display();
    }
}

