#ifndef OTHELLO_LOGIC_H
#define OTHELLO_LOGIC_H

#include "include.h"

int initOthello(char o[][N]);
int printOthello(char o[][N]);
int isInOthello(int x, int y);
int nextPlayer(int player);
int addStone(char o[][N], int x, int y, int player);
int delStone(char o[][N], int x, int y);

int isValidMove(char o[][N], int line, int column, int player);
int reverseStone(char o[][N], int line, int column, int player);

int isOver(char o[][N], int player);

int playOthello(char choice, SDL_Renderer *renderer);

#endif
