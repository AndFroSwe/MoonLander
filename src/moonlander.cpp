/*********************************
 * File: moonlander.cpp
 * Author: Andreas Fröderberg
 * Description: This is the main file that contains the game.
 *********************************/

#include "moonlander.h"

//*** Define global objects ***
// Screen
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
// SDL window objects
SDL_Window *gWindow = NULL; // Game window
SDL_Surface *gScreenSurface = NULL; // Surface contained by window
SDL_Surface *gBackground = NULL; // Surface object containing the background
// Images
char backgroundImage[] = "media/background.bmp"; // Background image


int main(int argc, char *argv[])
{
    DBG_PRINT("### Starting program at main() ###");
    // Initialize SDL
    if (!init()) { // If initialization fails
        fprintf(stderr, "Failed to initialize! SDL_Error: %s\n", SDL_GetError());
    } else {
        // Load bakground media
        gBackground = loadSurface(backgroundImage);
        if (gBackground == NULL) {
            fprintf(stderr, "Failed to load media!\n");
        } else {
            // Main loop
            // Loop flag
            bool quit = false; 
            // Event handler
            SDL_Event e;

            while (!quit) {
                while (SDL_PollEvent(&e) != 0) { // Poll for events
                    if (e.type == SDL_QUIT) {
                        quit = true;
                    } // end if
                } // end while
                SDL_Rect stretchRect;
                stretchRect.x = 0;
                stretchRect.y = 0;
                stretchRect.w = SCREEN_WIDTH;
                stretchRect.h = SCREEN_HEIGHT;
                SDL_BlitScaled(gBackground, // Surface to blit
                        NULL, // Copy entire surface
                        gScreenSurface, // Destination
                        &stretchRect); // Rectangle to copy into
                // Update the surface
                SDL_UpdateWindowSurface(gWindow);
            } // end while
        } // end if
    } // end if 
    //
    // Free resources and close
    close();

    return 0;
} // end main

// *** Functions ***
bool init()
{
    /* 
     * Initializes SDL and creates a game window
     */
    DBG_PRINT("### Running init() ###")
    bool success = true; // Flag the result of the initialization

    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        success = false;
    } else {
        // Create window
        gWindow = SDL_CreateWindow("Moon lander", // Title of window
                SDL_WINDOWPOS_UNDEFINED, // X position
                SDL_WINDOWPOS_UNDEFINED, // Y position
                SCREEN_WIDTH, // Window width
                SCREEN_HEIGHT, // Window height
                SDL_WINDOW_SHOWN); // Flags
        if (gWindow == NULL) { // If window was not created
            fprintf(stderr, "SDL window could not be created! SDL_Error: %s\n", SDL_GetError());
            success = false;
        } else {
            // Get window surface
            gScreenSurface = SDL_GetWindowSurface(gWindow);
        } // endif
    } // endif
    return success;
} // end init

SDL_Surface* loadSurface(char *s)
{
    /*
     * Loads a BMP image given by path s onto an optimized surface.
     */

    // Create object to blit to
    DBG_PRINT("### Running loadSurface () ###");
    SDL_Surface *optimizedSurface = NULL;
    // Load image
    SDL_Surface *loadedSurface = SDL_LoadBMP(s);
    if (loadedSurface == NULL) { // If image loading failed
        fprintf(stderr, "Failed to load image %s! SDL_Error: %s\n", s, SDL_GetError());
    } else {
        // Convert image to screen format
        optimizedSurface = SDL_ConvertSurface(loadedSurface, // Source
                gScreenSurface -> format, // Format
                0 // Flags (always 0)
                );
        if (optimizedSurface == NULL) { // If failed to create optimized surface
            fprintf(stderr, "Failed to created optimized surface %s! SDL_Error(): %s\n", s, SDL_GetError() );
            SDL_FreeSurface(loadedSurface);
        }
    } // end if
    return optimizedSurface;
} // end loadSurface

void close() 
{
    /*
     * Frees resources occupied by process
     */
    DBG_PRINT("### Running close() ###");
    // Free surfaces
    SDL_FreeSurface(gBackground);
    gBackground = NULL;

    // Destroy window
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;

    SDL_Quit();

} // end close
