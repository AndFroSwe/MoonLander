/*********************************
 * File: LTexture.h
 * Author: Andreas Fröderberg
 * Description: SDL texture wrapper.
 *********************************/

#ifndef LTEXTURE_H
#define LTEXTURE_H

// *** Includes ***
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

// *** Macros ***
// To print debug messages, define DBG_PRINT_CLASS 
#ifdef DEBUG_PRINT
    #define DBG_PRINT_CLASS(s) printf("--- %s ---\n", s);
#else
    #define DBG_PRINT_CLASS(s);
#endif

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
    bool loadFromFile(SDL_Renderer*, char*); // Loads a texture
    void render(SDL_Renderer*, int, int); // Render to screen
    void mFree(); // Deallocates resources used by texture
// *** Getters ***
int getWidth();
int getHeight();
};
    

#endif /* LTEXTURE_H */
