/**
 * ----------------------------------------------
 *                  text.h
 * ----------------------------------------------
 * 
 * File that handles text blitting on screen
 */


#include "text.h"


void blitThinText(SDL_Renderer *_renderer, const char *_text, int _x, int _y, int _size) {
    TTF_Font *font = TTF_OpenFont("fonts/thin.ttf", _size);
    SDL_Color white = {255, 255, 255, 255}, background = {42, 42, 42, 255};
    SDL_Surface *text_surface;
    SDL_Texture *text;
    SDL_Rect render_rect;

    text_surface = TTF_RenderText_Shaded(font, _text, white, background);
    text = SDL_CreateTextureFromSurface(_renderer, text_surface);
    render_rect.x = _x;
    render_rect.y = _y;
    render_rect.w = text_surface->w;
    render_rect.h = text_surface->h;
    SDL_FreeSurface(text_surface);

    SDL_RenderCopy(_renderer, text, NULL, &render_rect);
    TTF_CloseFont(font);
}


void blitText(SDL_Renderer *_renderer, const char *_text, int _x, int _y, int _size) {
    TTF_Font *font = TTF_OpenFont("fonts/normal.ttf", _size);
    SDL_Color white = {255, 255, 255, 255}, background = {42, 42, 42, 255};
    SDL_Surface *text_surface;
    SDL_Texture *text;
    SDL_Rect render_rect;

    text_surface = TTF_RenderText_Shaded(font, _text, white, background);
    text = SDL_CreateTextureFromSurface(_renderer, text_surface);
    render_rect.x = _x;
    render_rect.y = _y;
    render_rect.w = text_surface->w;
    render_rect.h = text_surface->h;
    SDL_FreeSurface(text_surface);

    SDL_RenderCopy(_renderer, text, NULL, &render_rect);
    TTF_CloseFont(font);
}


void blitTimerAndPlayer(SDL_Renderer *_renderer, const char *_text, Bool _team) {
    int screen_width, screen_height;
    int x_offset, y_offset;
    TTF_Font *thin_font = TTF_OpenFont("fonts/thin.ttf", TIMER_SIZE);
    TTF_Font *normal_font = TTF_OpenFont("fonts/normal.ttf", PLAYER_TEXT_SIZE);
    SDL_Color white = {255, 255, 255, 255}, background = {42, 42, 42, 255};
    SDL_Surface *text_surface;
    SDL_Texture *text;
    SDL_Rect render_rect;

    // Get screen size and offset
    SDL_GetRendererOutputSize(_renderer, &screen_width, &screen_height);
    x_offset = (screen_width - SQUARE_SIZE * BOARD_LENGTH) / 2;
    y_offset = (screen_height - SQUARE_SIZE * BOARD_LENGTH) / 2;

    text_surface = TTF_RenderText_Shaded(thin_font, _text, white, background);
    text = SDL_CreateTextureFromSurface(_renderer, text_surface);
    render_rect.x = x_offset + SQUARE_SIZE * BOARD_LENGTH + (x_offset - text_surface->w) / 2;
    render_rect.y = y_offset + (SQUARE_SIZE * BOARD_LENGTH) / 3;
    render_rect.w = text_surface->w;
    render_rect.h = text_surface->h;
    SDL_FreeSurface(text_surface);

    SDL_RenderCopy(_renderer, text, NULL, &render_rect);
    
    if (_team == 0) {
        text_surface = TTF_RenderText_Shaded(normal_font, "A l'ordinateur", white, background);
    } else {
        text_surface = TTF_RenderText_Shaded(normal_font, "Au joueur", white, background);
    }
    text = SDL_CreateTextureFromSurface(_renderer, text_surface);
    render_rect.x = x_offset + SQUARE_SIZE * BOARD_LENGTH + (x_offset - text_surface->w) / 2;
    render_rect.y = y_offset + (SQUARE_SIZE * BOARD_LENGTH) / 3 + 100;
    render_rect.w = text_surface->w;
    render_rect.h = text_surface->h;
    SDL_FreeSurface(text_surface);

    SDL_RenderCopy(_renderer, text, NULL, &render_rect);
    TTF_CloseFont(thin_font);
    TTF_CloseFont(normal_font);
}