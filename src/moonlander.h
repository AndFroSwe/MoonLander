/**************************************
 * File: moonlander.h
 * Author: Andreas Fröderberg
 * Description: Moon lander game made in SDL. Safely land the landing shuttle on
 * the moon!
 * This game is made as an SDL learning experience.
 **************************************/

#ifndef MOONLANDER_H_
#define MOONLANDER_H_ 

// *** Includes ***
#include <stdio.h>
#include <SDL2/SDL.h> // SDL main header
#include <SDL2/SDL_image.h>

// *** Macros ***
// To print debug messages, define DBG_PRINT 
#ifdef DEBUG_PRINT
    #define DBG_PRINT(s) printf("%s\n", s);
#else
    #define DBG_PRINT(s);
#endif

// *** Function protoypes ***
bool init(); // Initiates SDL 
SDL_Surface* loadSurface(char*); // Loads an image to a sruface
void close(); // Frees resources on closing program 

#endif /* ifndef MOONLANDER_H_ */
