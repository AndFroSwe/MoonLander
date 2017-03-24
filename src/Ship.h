/*********************************
 * File: Ship.h
 * Author: Andreas Fröderberg
 * Description: Ship class header. The ship is the game object that is
 * controlled by the player.
 *
 * Todo-list:
 * TODO: Implement sprite animations
 * TODO: Implement gravity
 * TODO: Implement screen edge detection
 *********************************/

#ifndef SHIP_H_
#define SHIP_H_ 

// *** Includes ***
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "debug.h" // Debug prints
#include "config.h" // Global variables
// ** Class includes **
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
        // *** Ship game parameters ***
        static const int xSpeed = 10; // Max x speed
        static const int ySpeed = 10; // Max y speed
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
