#ifndef OTHELLO_DRAW_H
#define OTHELLO_DRAW_H

#include "include.h"

int initDrawINTRO(SDL_Renderer *renderer);
void drawINTRO(SDL_Renderer *renderer);

int initDrawMENU(SDL_Renderer *renderer, SDL_Rect *title, SDL_Rect *menu, SDL_Rect options[]);
void drawMENU(SDL_Renderer *renderer, SDL_Rect title, SDL_Rect menu, SDL_Rect options[]);

int initDrawGAME(SDL_Renderer *renderer);
void drawGAME(SDL_Renderer *renderer, char o[][N], int size);

void drawOPTION(SDL_Renderer *renderer);
void drawRULE(SDL_Renderer *renderer);
void drawCOMMAND(SDL_Renderer *renderer);

#endif // OTHELLO_DRAW_H
