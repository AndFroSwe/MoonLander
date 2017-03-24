/**************************************
 * File: moonlander.h
 * Author: Andreas Fröderberg
 * Description: Moon lander game made in SDL. Safely land the landing shuttle on
 * the moon!
 * This game is made as an SDL learning experience.
 *
 * Todo-list:
 **************************************/

#ifndef MOONLANDER_H_
#define MOONLANDER_H_ 

// *** Includes ***
#include <stdio.h>
#include <SDL2/SDL.h> // SDL main header
#include <SDL2/SDL_image.h>
#include "debug.h" // Debug prints
#include "config.h" // Global variables
// ** Class headers **
#include "Ship.h"
#include "LTexture.h"


// *** Function protoypes ***
bool init(); // Initiates SDL 
SDL_Surface* loadSurface(char*); // Loads an image to a sruface
bool loadMedia(); // Load all media
void close(); // Frees resources on closing program 

#endif /* ifndef MOONLANDER_H_ */
