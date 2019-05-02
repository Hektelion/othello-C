#ifndef OTHELLO_IA_H
#define OTHELLO_IA_H

#include "include.h"

float max(float a,float b);
float min(float a,float b);

void copy_othello(char o[][N], char copy_o[][N]);
void nb_stone(char o[][N], int *black_stone, int *white_stone);
int eval_quant(char o[][N]);

int get_nbMove(char o[][N], int player);
void get_validMove(char o[][N], coup c_possible[], int player);

float minimax(char o[][N], int depth, int player);

#endif // OTHELLO_IA_H
