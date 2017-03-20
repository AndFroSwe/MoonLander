/*********************************
 * File: LTexture.cpp
 * Author: Andreas Fröderberg
 * Description: Source file for LTexture class.
 *********************************/

#include "LTexture.h"

// *** Constructors and destructors ***
LTexture::LTexture()
{
    DBG_PRINT_CLASS("Default constructor of LTexture");

    // Initialize everything to 0
    mTexture = NULL;
    mWidth = 0;
    mHeight = 0;
}

LTexture::~LTexture()
{
    DBG_PRINT_CLASS("Destructor of LTexture");
    mFree();
}

// *** Methods ***
bool LTexture::loadFromFile(SDL_Renderer *r, char *s)
{

    DBG_PRINT_CLASS("loadFromFile of LTexture");

    mFree(); // Get rid of existing texture

    SDL_Texture *newTexture = NULL;

    // Load image from specified path
    SDL_Surface *loadedSurface = IMG_Load(s);
    if (loadedSurface == NULL) {
        fprintf(stderr, "Unable to load file: %s. SDL_Error: %s\n", s, SDL_GetError());
    } else {
        SDL_SetColorKey(loadedSurface, // Surface
                SDL_TRUE, // Enable color key
                SDL_MapRGB(loadedSurface -> format, 0, // Red
                                                    0xFF, // Green
                                                    0xFF // Blue
                                                    ) // Pixel color
                );
        // Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface(r, loadedSurface);
        if (newTexture == NULL) {
            fprintf(stderr, "Failed to create texture from surface. SDL_Error: %s\n", SDL_GetError());
        } else {
            // Get image dimensions
            mWidth = loadedSurface -> w;
            mHeight = loadedSurface -> h;
        } // end if
        // Get rid of old texture
        SDL_FreeSurface(loadedSurface);
    } // end if
    mTexture = newTexture;

    return (mTexture != NULL);
} // end loadFromFile

void LTexture::mFree()
{
    DBG_PRINT_CLASS("mFree of LTexture");

    // Free texture if it exists
    if (mTexture != NULL) {
        SDL_DestroyTexture(mTexture);
        mTexture = NULL;
        mWidth = 0;
        mHeight = 0;
    }
}

void LTexture::render(SDL_Renderer *r, int x, int y) 
{
    DBG_PRINT_CLASS("render of LTexture");

    // Set rendering space and render to screen
    SDL_Rect renderQuad = {x, y, mWidth, mHeight};
    SDL_RenderCopy(r, // SDL Renderer
                    mTexture, // Texture
                    NULL, // How much of texture
                    &renderQuad // Destination structure
                    );
}

// *** Getters ***
int LTexture::getWidth()
{
	return mWidth;
}

int LTexture::getHeight()
{
	return mHeight;
}