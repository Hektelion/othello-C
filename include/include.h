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
//				CONSTANTES
//============================================

//Constante logique
#define N 8
#define BLANK ' '
#define WHITE 'o'
#define BLACK 'x'

//Constante graphique
#define WIDTH_OTHELLO 800
#define HEIGHT_OTHELLO 600
#define NB_OPTION 6

//============================================
//			BIBLIOTHEQUES PERSONNEL
//============================================

#include "othello_logic.h"
#include "othello_IA.h"
#include "othello_draw.h"
#include "othello_system.h"

#endif // INCLUDE_H
