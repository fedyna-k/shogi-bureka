/**
 * ----------------------------------------------
 *                   graphics.h
 * ----------------------------------------------
 * 
 * Graphic functions for shogi gameplay
 */


#ifndef __GRAPHICS_H__
#define __GRAPHICS_H__


// ----- Dependancy -----


#include <SDL.h>
#include <SDL_image.h>
#include <stdlib.h>
#include "constants.h"
#include "bool.h"
#include "string.h"
#include "piece.h"
#include "board.h"


// ----- Constants and structs -----


struct __s_Color {
    unsigned char r;
    unsigned char g;
    unsigned char b;
};

typedef struct __s_Color Color;

#define LIGHT_SQUARES (Color){(char)220u, (char)190u, (char)130u}
#define DARK_SQUARES (Color){(char)163u, (char)137u, (char)80u}
#define BACKGROUND_COLOR (Color){(char)42u, (char)42u, (char)42u}


// ----- Functions -----


void printSystemInfo(void);
void exitOnError(const char *_error_message);
SDL_Window *createMainWindow(void);
SDL_Renderer *createRenderer(SDL_Window *_window);

void fillRectangle(SDL_Renderer *_renderer, int _x, int _y, int _width, int _height, Color _color);
void fillBackground(SDL_Renderer *_renderer);
void drawBoardBackground(SDL_Renderer *_renderer);

SDL_Texture *loadImage(SDL_Renderer *_renderer, const char *_path);
SDL_Texture **generatePiecesTextures(SDL_Renderer *_renderer, Bool _is_chess_like);
void freePiecesTextures(SDL_Texture **_texture_array);
void drawPiece(SDL_Renderer *_renderer, Piece _piece);
void drawBoard(SDL_Renderer *_renderer, Board _board);


#endif