#ifndef INCLUDE_H
#define INCLUDE_H

//============================================
//			BIBLIOTHEQUES STANDARD
//============================================

#include <stdio.h> //gestion entrée/sortie
#include <stdlib.h> //gestion memoire et systeme
#include <string.h> //gestion des chaines de caractères

//============================================
//			BIBLIOTHEQUES GRAPHIQUE
//============================================

#include "../lib/SDL2/include/SDL.h"
#include "../lib/SDL2/include/SDL_ttf.h"
#include "../lib/freetype/include/ft2build.h"

//============================================
//			BIBLIOTHEQUES AUTRES
//============================================

#include "../lib/CUnit/Headers/Basic.h"

//============================================
//				STRUCTURE
//============================================

typedef struct{
	int x;
	int y;
}coup;

//============================================
//				CONSTANTES
//============================================

//Constante logique
#define N 8
#define BLANK ' '
#define WHITE 'o'
#define BLACK 'x'

//Constante graphique
#define WIDTH_OTHELLO 800
#define HEIGHT_OTHELLO 800
#define NB_OPTION 3

//Constante IA
#define VAL_INF 100000

//============================================
//			BIBLIOTHEQUES PERSONNEL
//============================================

#include "othello_logic.h"
#include "othello_IA.h"
#include "othello_draw.h"
#include "othello_system.h"

#endif // INCLUDE_H
