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
SDL_Surface *gBackground = NULL; // Surface object containing the background
SDL_Texture *gTexture = NULL; // Temp
SDL_Renderer *gRenderer = NULL; // Window renderer
LTexture bgTexture; // Texture for background
LTexture object;

// Images
char bgPath[] = "media/background.bmp"; // Background image
char shipImage[] = "media/dot.bmp"; // Image to render ship

int main(int argc, char *argv[])
{
    DBG_PRINT("### Starting program at main() ###");
    //
    // Initialize SDL
    if (!init()) 
    { // If initialization fails
        fprintf(stderr, "Failed to initialize! SDL_Error: %s\n", SDL_GetError());
    } 
    else 
    {
        // Status flag
        bool quit = false; 
        
        // Event handler
        SDL_Event e;

        loadMedia();
        int x = 0;
        int y = 0;
        
        // Main loop
        while (!quit) 
        {
            while (SDL_PollEvent(&e) != 0) // Poll for events
            { 
                if (e.type == SDL_QUIT) 
                {
                    quit = true;
                } // end if
            } // end while

            // Clear screen
            SDL_SetRenderDrawColor(gRenderer, // Renderer
                                0x00, // R
                                0x00, // G
                                0x00, // B
                                0x00 // Alpha
                                );
            SDL_RenderClear(gRenderer);

            // Render objects
            bgTexture.render(gRenderer, 0, 0);
            object.render(gRenderer, x++, y++);

            // Update screen
            SDL_RenderPresent( gRenderer );
        } // end while
    } // end if 
    //
    // Free resources and close
    close();

    DBG_PRINT("### Program done! ###");

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
    if (SDL_Init(SDL_INIT_VIDEO) < 0) 
    {
        fprintf(stderr, "SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        success = false;
    } 
    else 
    {
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			fprintf(stderr, "Warning: Linear texture filtering not enabled!" );
		}
        // Create window
        gWindow = SDL_CreateWindow("Moon lander", // Title of window
                                    SDL_WINDOWPOS_UNDEFINED, // X position
                                    SDL_WINDOWPOS_UNDEFINED, // Y position
                                    SCREEN_WIDTH, // Window width
                                    SCREEN_HEIGHT, // Window height
                                    SDL_WINDOW_SHOWN // Flags
                                    ); // Flags
        if (gWindow == NULL) 
        { // If window was not created
            fprintf(stderr, "SDL window could not be created! SDL_Error: %s\n", SDL_GetError());
            success = false;
        } 
        else 
        {
            // Create renderer for window
            gRenderer = SDL_CreateRenderer(gWindow, // Window to render
                                            -1, // Index flag. -1 first one supporting requested flags
                                            SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC// Render flags
                                            );
            if (gRenderer == NULL) 
            {
                fprintf(stderr, "Window renderer could not be created! SDL Error: %s\n", SDL_GetError());
                success = false;
            } 
            else 
            {
                // Initialize render draw color
                SDL_SetRenderDrawColor(gRenderer, // Renderer
                                    0x00, // R
                                    0x00, // G
                                    0x00, // B
                                    0x00 // Alpha
                                    );

                // Initialize png loading
                int imgFlags = IMG_INIT_PNG;
                if (!(IMG_Init(imgFlags) & imgFlags)) 
                {
                    fprintf(stderr, 
                            "SDL_Image could not initialize! SDL image error: %s\n", 
                            IMG_GetError());
                    success = false;
                }
            } // end if
        } // endif
    } // endif

    return success;

} // end init

SDL_Texture* loadTexture(char *s)
{
    // Create object to blit to
    DBG_PRINT("### Running loadTexture () ###");

    SDL_Texture *newTexture = NULL;

    // Load image
    SDL_Surface *loadedSurface = IMG_Load(s);
    if (loadedSurface == NULL) 
    { // If image loading failed
        fprintf(stderr, "Failed to load image %s! SDL_Error: %s\n", s, SDL_GetError());
    } 
    else 
    {
        // Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface(gRenderer, // Renderer
                loadedSurface // Surface
                );
        if (newTexture == NULL) 
        { // If failed to create optimized surface
            fprintf(stderr, "Unable to create texture from %s! SDL_Error(): %s\n", s, SDL_GetError() );
        }
        // Free the surface
        SDL_FreeSurface(loadedSurface);
    } // end if

    return newTexture;
} // end loadSurface

bool loadMedia()
{
    DBG_PRINT("### Running loadMedia() ###");
    bool success = true; // Success flag

    // Load png texture

    if (!bgTexture.loadFromFile(gRenderer, bgPath))
    {
        fprintf(stderr, "Failed to load texture image!\n");
        success = false;
    }
    if (!object.loadFromFile(gRenderer, shipImage))
    {
        fprintf(stderr, "Failed to load ship image!\n");
        success = false;
    }

    return success;
}

void close() 
{
    /*
     * Frees resources occupied by process
     */
    DBG_PRINT("### Running close() ###");
    // Free surfaces
    SDL_DestroyTexture(gTexture);
    gTexture = NULL;

    // Destroy window
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    gRenderer = NULL;
    gWindow = NULL;

    // Quit subsystems
    IMG_Quit();
    SDL_Quit();


} // end close

