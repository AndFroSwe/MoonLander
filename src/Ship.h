/*********************************
 * File: Ship.h
 * Author: Andreas Fröderberg
 * Description: Ship class header. The ship is the game object that is
 * controlled by the player.
 *********************************/

#ifndef SHIP_H_
#define SHIP_H_ 

// *** Includes ***
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "debug.h"
#include "LTexture.h"

class Ship
{
    public:
        // *** Constructors and destructors ***
        Ship(); // Default constructor
        ~Ship(); // Destructor
        // *** Methods ***
        void handleEvent(SDL_Event &); // Handle button presses
        void move(); // Moves the ship
        void render(SDL_Renderer*,  SDL_Rect*); // Renders the ship
        bool addTexture(SDL_Renderer*, char*); // Adds a texture object to the class

    private:
        // *** Shape parameters ***
        static const int width = 20;
        static const int height = 30;
        // *** Spatial parameters ***
        int xPos, yPos;
        int xVel, yVel;
        int xAcc, yAcc;
        // *** Texture object
        LTexture texture;
};

#endif /* ifndef SHIP_H_ */
