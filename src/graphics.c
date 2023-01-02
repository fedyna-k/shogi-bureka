/**
 * ----------------------------------------------
 *                   graphics.c
 * ----------------------------------------------
 * 
 * Graphic functions for shogi gameplay
 */


#include "graphics.h"
#include <stdio.h>


/**
 * Prints system infos on screen, must be used after SDL init.
 */
void printSystemInfo(void) {
    SDL_DisplayMode display_mode;
    SDL_version version;

    SDL_GetDisplayMode(0, 0, &display_mode);
    SDL_VERSION(&version);

    SDL_Log("SDL version : %d.%d.%d \n", version.major, version.minor, version.patch);
    SDL_Log("Display informations : %dx%d at %dHz \n", display_mode.w, display_mode.h, display_mode.refresh_rate);
}


/**
 * Exit program on SDL error
 * @param _error_message The message to blit with error
 */
void exitOnError(const char *_error_message) {
    SDL_Log("ERROR : %s >> %s", _error_message, SDL_GetError());
    SDL_Quit();
    exit(EXIT_FAILURE);
}


/**
 * Initialize SDL and return window pointer
 * @return A pointer to the window
 */
SDL_Window *createMainWindow(void) {
    SDL_DisplayMode display_mode;
    SDL_Window *window;

    // Initialize sdl
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_EVENTS) < 0) {
        // Error message
        exitOnError("Erreur lors du chargement de SDL.");
    }

    printSystemInfo();

    // Get window size (Use only first screen)
    SDL_GetDisplayMode(0, 0, &display_mode);
    
    // Create window
    window = SDL_CreateWindow("Shogi Breaker", 0, 0, display_mode.w, display_mode.h, SDL_WINDOW_FULLSCREEN);
    if (window == NULL) {
        exitOnError("Erreur lors de la creation de fenetre.");
    }

    return window;
}


/**
 * Creates a new renderer associated with the screen
 * @param _window The window to bind the renderer with
 * @return The newly created renderer
 */
SDL_Renderer *createRenderer(SDL_Window *_window) {
    SDL_Renderer *renderer;

    renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == NULL) {
        exitOnError("Erreur lors de la creation de rendu.");
    }

    return renderer;
}


/**
 * Fill a rectangle in renderer
 * @param _renderer The SDL_Renderer used for drawings
 * @param _x The top left corner x coordinate
 * @param _y The top left corner y coordinate
 * @param _width The rectangle width
 * @param _height The rectangle height
 * @param _color The color of the rectangle
 */
void fillRectangle(SDL_Renderer *_renderer, int _x, int _y, int _width, int _height, Color _color) {
    // Create rectangle object
    const SDL_Rect rectangle = {_x, _y, _width, _height};

    // Set render color to desired color
    if (SDL_SetRenderDrawColor(_renderer, _color.r, _color.g, _color.b, SDL_ALPHA_OPAQUE) != 0) {
        exitOnError("Impossible de changer la couleur du rendu.");
    }

    // Render rectangle
    if (SDL_RenderFillRect(_renderer, &rectangle) != 0) {
        exitOnError("Impossible de dessiner le rectangle voulu.");
    }
}


/**
 * Fill background with desired color
 * @param _renderer The SDL_Renderer used for drawings
 */
void fillBackground(SDL_Renderer *_renderer) {
    // Get screen size
    int width, height;
    if (SDL_GetRendererOutputSize(_renderer, &width, &height) != 0) {
        exitOnError("Impossible de recuperer la taille du rendu.");
    }

    // Set render color to desired color
    if (SDL_SetRenderDrawColor(_renderer, BACKGROUND_COLOR.r, BACKGROUND_COLOR.g, BACKGROUND_COLOR.b, SDL_ALPHA_OPAQUE) != 0) {
        exitOnError("Impossible de changer la couleur du rendu.");
    }

    // Fill rect using function made before
    SDL_RenderClear(_renderer);
}


/**
 * Draw the board background on renderer
 * @param _renderer The SDL_Renderer used for drawings
 */
void drawBoardBackground(SDL_Renderer *_renderer) {
    int screen_width, screen_height;
    int x_offset, y_offset;
    int x_index, y_index;
    int x, y;
    Color color;

    // Get screen size and offset
    if (SDL_GetRendererOutputSize(_renderer, &screen_width, &screen_height) != 0) {
        exitOnError("Impossible de recuperer la taille du rendu.");
    }
    x_offset = (screen_width - SQUARE_SIZE * BOARD_LENGTH) / 2;
    y_offset = (screen_height - SQUARE_SIZE * BOARD_LENGTH) / 2;

    // Draw squares
    for (y_index = 0 ; y_index < BOARD_LENGTH ; y_index++) {
        for (x_index = 0 ; x_index < BOARD_LENGTH ; x_index++) {
            x = x_index * SQUARE_SIZE + x_offset;
            y = y_index * SQUARE_SIZE + y_offset;
            color = ((x_index + y_index) % 2) ? DARK_SQUARES : LIGHT_SQUARES;

            fillRectangle(_renderer, x, y, SQUARE_SIZE, SQUARE_SIZE, color);
        }
    }
}