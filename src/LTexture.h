/*********************************
 * File: LTexture.h
 * Author: Andreas Fröderberg
 * Description: SDL texture wrapper.
 *
 * Todo-list:
 * TODO: Stretch surface before loading
 * TODO: Add option to define size of blitted image
 *********************************/

#ifndef LTEXTURE_H
#define LTEXTURE_H

// *** Includes ***
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "debug.h"

class LTexture
{
private:
    SDL_Texture *mTexture; // SDL texture
    int mWidth, mHeight; // Image dimension

public:
    // *** Constructors and destructors ***
    LTexture(); // Default constructor
    ~LTexture(); // Destructor
    // *** Methods ***
    bool loadFromFile(SDL_Renderer*, char*, bool); // Loads a texture
    void render(SDL_Renderer*, int, int, SDL_Rect*); // Render to screen
    void mFree(); // Deallocates resources used by texture
// *** Getters and Setters***
int getWidth();
int getHeight();
bool setWidth(int); // Sets width and does validation
bool setHeight(int); // Sets height and does validation
};
    

#endif /* LTEXTURE_H */
