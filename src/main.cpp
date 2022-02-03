// **************************************************
// Playing around with SFML. First through making
// some classes for boards and pieces and then
// implementing a basic game loop...?
// Last Edited: January 26, 2022
// **************************************************

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <memory>
#include <math.h>
#include "pieces.h"
#include "gamemanager.h"

using namespace std;
using namespace sf;

int main()
{
    // adjustable variables...
    const unsigned int tileSize = 100;
    const unsigned int boardDims = (tileSize * 8);
    const unsigned int winDim1 = 1200;
    const unsigned int winDim2 = 1000;
    const unsigned int FPS = 30;
    int offset = 100;
    Color bgColor(128,128,128);

    if (winDim1 < boardDims+offset | winDim2 < boardDims+offset)
    {
        cerr << "board goes offscreen, please adjust dimensions." << endl;
        return 1;
    }

    // start things up...
    RenderWindow window(VideoMode(winDim1, winDim2), "My Window");
    window.setFramerateLimit(FPS);    
    window.mapPixelToCoords(Mouse::getPosition(window));
    GameManager chessGame(bgColor);
    cout << "Starting game..." << endl;

    chessGame.startGame(tileSize, offset, window);

    // EXPERIMENTING WITH INHERITANCE & ASSIGNMENTS
    Pawn pawn(Color::Black);
    King king(Color::White);
    Piece& piece = pawn;
    cout << "Calling printPiece...\n";
    piece.printPiece();
    Piece *pp;
    Piece pie;
    pp = &king;
    pp->printPiece();
    // ---------------------------------------------
    Event event;

    while(window.isOpen())
    {
        while(window.pollEvent(event))
        {
            if(event.type == Event::Closed)
            {
                window.close();
                return 0;
            }

            if(event.type == Event::MouseButtonPressed)
            {
                Vector2i mousePos;
                mousePos = Mouse::getPosition(window);
                // check if board was clicked
                if((offset <= mousePos.y && mousePos.y <= offset+boardDims) && (offset <= mousePos.x && mousePos.x <= offset+boardDims))
                {
                    // calculate which tile clicked
                    cout << mousePos.y << ", " << mousePos.x << endl;
                    int col = floor((mousePos.x - (offset+floor(mousePos.x/tileSize)))/tileSize);
                    int row = floor((mousePos.y - (offset+floor(mousePos.y/tileSize)))/tileSize);
                    int index = col + (row * 8);
                    cout << "row: " << row << " col: " << col << " index: " << index << endl;
                    if((event.mouseButton.button == Mouse::Left) && (0<=index && index < 64))
                    {
                        chessGame.selectSpace(index, window);
                    }
                }
            }
        }
    }
    // delete empty;
    return 0;
}