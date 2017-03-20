/*********************************
 * File: Ship.cpp
 * Author: Andreas Fröderberg
 * Description: Source file for ship class.
 *********************************/

#include "Ship.h"

// *** Constructors and destructors ***
Ship::Ship()
{
    DBG_PRINT_CLASS("Default constructor", "Ship");
    // Starting postiion
    xPos = 10;
    yPos = 10;
    // Starting speed
    xVel = 0;
    yVel = 0;
    // Starting acceleration
    xAcc = 0;
    yAcc = 0;
} // end Ship

Ship::~Ship()
{

}

// *** Methods ***
void Ship::handleEvent(SDL_Event &e)
{
    DBG_PRINT_CLASS("handleEvent", "Ship");

    // If a key was pressed
    if (e.type == SDL_KEYDOWN && e.key.repeat == 0) 
    {
        // Handle keys pressed
        switch (e.key.keysym.sym) {
            // Adjust movement
            case SDLK_UP: yVel -= 10; break;
            case SDLK_RIGHT: xVel += 10; break;
            case SDLK_DOWN: yVel += 10; break;
            case SDLK_LEFT: xVel -= 10; break;
        } // end switch
    }
    else if (e.type == SDL_KEYUP && e.key.repeat == 0) 
    {
        // Handle keys released
        switch (e.key.keysym.sym) {
            // Adjust movement
            case SDLK_UP: yVel += 10; break;
            case SDLK_RIGHT: xVel -= 10; break;
            case SDLK_DOWN: yVel -= 10; break;
            case SDLK_LEFT: xVel += 10; break;
        } // end switch
    } // end if
} // end handleEvent

void Ship::move()
{
    DBG_PRINT_CLASS("move", "Ship");
    // Move the ship
    xPos += xVel;
    yPos += yVel;
}

void Ship::render(SDL_Renderer *r, LTexture &t)
{
    DBG_PRINT_CLASS("render", "Ship");

    // Set rendering space and render to screen
    t.render(r, xPos, yPos);

}
