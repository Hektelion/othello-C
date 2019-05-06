#include "../include/othello_draw.h"
#include "../include/include.h"
#include <math.h>

static SDL_Point othello_lines[(N-1)*4];
static SDL_Rect othello;
static SDL_Point stone[N][N];
static SDL_Rect pion[N][N];

/* Entrées    : renderer (un moteur de rendu), origin (un point), ray (un entier)
 * Sorties    :
 * Variables  : point (un point), n (un entier)
 * Traitement : Cette fonction dessine un cercle plein à l'écran
 */
void drawCircle(SDL_Renderer *renderer, SDL_Point origin, int ray){
	SDL_Point point;
	int n=100;

	for(int i=0 ; i<n ; i++){
		point.x = origin.x + ray * cos( (i+1) * ((2*M_PI)/n) );
		point.y = origin.y + ray * sin( (i+1) * ((2*M_PI)/n) );
		SDL_RenderDrawLine(renderer, origin.x, origin.y, point.x, point.y);
	}

}

/* Entrées    : renderer (un moteur de rendu)
 * Sorties    : Le code d'erreur de la fonction
 * Variables  : width (un entier), heigth (un entier)
 * Traitement : Cette fonction initialise les elements utilisé dans l'intro
 */
int initDrawINTRO(SDL_Renderer *renderer){
	int width;
    int heigth;

    //Récupération de la taille de l'affichage
    SDL_GetRendererOutputSize(renderer, &width, &heigth);



	return EXIT_SUCCESS;
}

/* Entrées    : renderer (un moteur de rendu)
 * Sorties    :
 * Variables  :
 * Traitement : Dessine à l'écran l'introduction du jeu puis effectue une pause
 */
void drawINTRO(SDL_Renderer *renderer){

	//Background Noir
    SDL_SetRenderDrawColor(renderer, 0,0,0,255);
    SDL_RenderClear(renderer);


}

/* Entrées    : renderer (un moteur de rendu), title (un rectangle),
			 	menu (un rectangle), options (un tableau de rectangle)
 * Sorties    : Le code d'erreur de la fonction
 * Variables  : width (un entier), heigth (un entier)
 * Traitement : Cette fonction initialise les elements utilisé dans le dessin du menu
 */
int initDrawMENU(SDL_Renderer *renderer, SDL_Rect *title, SDL_Rect *menu, SDL_Rect options[]){
	int width;
    int heigth;

    //Récupération de la taille de l'affichage
    SDL_GetRendererOutputSize(renderer, &width, &heigth);

	//Initialisation du titre
    (*title).h = heigth/10;
    (*title).w = width/2;
    (*title).x = width/4;
    (*title).y = heigth/50;

	//Initialisation de la partie menu
    (*menu).h = heigth - ((*title).h + 3*(*title).y);
    (*menu).w = 6*(width/8);
    (*menu).x = width/8;
    (*menu).y = (*title).h + 2*(*title).y;

	//Initialisation des options
    for(int i=0 ; i<NB_OPTION ; i++){
        options[i].h = ((*menu).h - (*title).y)/NB_OPTION - (*title).y;
        options[i].w = (*menu).w - 2*(*title).y;
        options[i].x = (*menu).x + (*title).y;
        options[i].y = (*menu).y + i*(options[i].h + (*title).y) + (*title).y;
    }

	return EXIT_SUCCESS;
}

/* Entrées    : renderer (un moteur de rendu), title (un rectangle),
			 	menu (un rectangle), options (un tableau de rectangle)
 * Sorties    :
 * Variables  :
 * Traitement : Cette fonction dessine les éléments du menu
 */
void drawMENU(SDL_Renderer *renderer, SDL_Rect title, SDL_Rect menu, SDL_Rect options[]){

	//Background Blanc
    SDL_SetRenderDrawColor(renderer, 255,255,255,255);
    SDL_RenderClear(renderer);

	SDL_SetRenderDrawColor(renderer, 0,125,125,125);
    SDL_RenderDrawRect(renderer, &title);
    SDL_SetRenderDrawColor(renderer, 125,0,125,125);
    SDL_RenderDrawRect(renderer, &menu);
    SDL_SetRenderDrawColor(renderer, 125,125,0,125);
    for(int i=0 ; i<NB_OPTION ; i++){
        SDL_RenderDrawRect(renderer, &options[i]);
    }

    SDL_RenderPresent(renderer);
}

/* Entrées    : renderer (un moteur de rendu), carreau (un tableau 2D de rectangles)
 * Sorties    : Le code d'erreur de la fonction
 * Variables  : width (un entier), heigth (un entier), ecart (un entier)
 * Traitement : Cette fonction initialise les elements
 				utilisé dans le dessin du plateau
 */
int initDrawGAME(SDL_Renderer *renderer, SDL_Rect carreau[][N]){
	int width;
    int heigth;

	int ecart=50;

    //Récupération de la taille de l'affichage
    SDL_GetRendererOutputSize(renderer, &width, &heigth);

	//Initialise les carreau de l'othellier
	for(int i=0 ; i<N ; i++){
        for(int j=0 ; j<N ; j++){
            carreau[i][j].h = (heigth-(2*ecart))/N;
            carreau[i][j].w = (heigth-(2*ecart))/N;
            carreau[i][j].x = ecart + j*(heigth-(2*ecart))/N;
            carreau[i][j].y = ecart + i*(heigth-(2*ecart))/N;
        }
    }

	//Initialise la hauteur et la lageur des pions
	for(int i=0 ; i<N ; i++){
        for(int j=0 ; j<N ; j++){
			pion[i][j].h = ((heigth-(2*ecart))/N)/2;
		    pion[i][j].w = ((width-(2*ecart))/N)/2;
        }
    }

	//Initialise les dimension du plateau
    othello.x = ecart;
    othello.y = ecart;
    othello.h = heigth-2*ecart;
    othello.w = width-2*ecart;

	//Initialise les coordonnées des lignes vertical du plateau
    for(int i=0 ; i<(N-1)*2 ; i=i+2){
        othello_lines[i].x = ecart;
        othello_lines[i].y = ecart + (1 + (i/2))*( (heigth-(2*ecart))/N );
        othello_lines[i+1].x = width-ecart;
        othello_lines[i+1].y = ecart + (1 + (i/2))*( (heigth-(2*ecart))/N );
        //printf("%d\n", i);
    }

	//Initialise les coordonnées des ligne horizontal du plateau
    for(int i=(N-1)*2 ; i<(N-1)*4 ; i=i+2){
        othello_lines[i].x = ecart + (1 + ((i - (N-1)*2 )/2))*( (width-(2*ecart))/N );
        othello_lines[i].y = ecart;
        othello_lines[i+1].x = ecart + (1 + ((i - (N-1)*2 )/2))*( (width-(2*ecart))/N );
        othello_lines[i+1].y = heigth - ecart;
        //printf("%d\n", i);
    }

	//Initialise l'origine des pierres sur le plateau
    for(int i=0 ; i<N ; i++){
        for(int j=0 ; j<N ; j++){
            stone[i][j].x = ecart + ((width-(2*ecart))/N)/2 + j * (width-(2*ecart))/N;
            stone[i][j].y = ecart + ((heigth-(2*ecart))/N)/2 + i * (heigth-(2*ecart))/N;
        }
    }

	//Initialise les coordonnées des pierre sur le plateau
    for(int i=0 ; i<N ; i++){
        for(int j=0 ; j<N ; j++){
            pion[i][j].x = stone[i][j].x - ((width-(2*ecart))/N)/4;
            pion[i][j].y = stone[i][j].y - ((heigth-(2*ecart))/N)/4;
        }
    }

	return EXIT_SUCCESS;
}

/* Entrées    : renderer (un moteur de rendu), o (un tableau 2D de caractères),
				player (un entier)
 * Sorties    :
 * Variables  : nbMove (un entier), c_possible (un tableau de coup)
 * Traitement : Cette fonction dessine les éléments du jeu
 */
void drawGAME(SDL_Renderer *renderer, char o[][N], int player){
	int nbMove = get_nbMove(o, player);
	coup c_possible[nbMove];

	get_validMove(o, c_possible, player);

	//Background Orange
	SDL_SetRenderDrawColor(renderer, 211, 84, 0, 255);
	SDL_RenderClear(renderer);

	//Dessine le fond du plateau
	SDL_SetRenderDrawColor(renderer, 39, 174, 96, 255);
    SDL_RenderFillRect(renderer, &othello);

	//Dessine les lignes du plateau
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    for(int i=0 ; i<(N-1)*4 ; i=i+2){
        SDL_RenderDrawLine(renderer, othello_lines[i].x, othello_lines[i].y, othello_lines[i+1].x, othello_lines[i+1].y);
    }

	//Dessin des pierre sur l'othellier
    for(int i=0 ; i<N ; i++){
        for(int j=0 ; j<N ; j++){
            if(o[i][j] == WHITE){
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
                SDL_RenderFillRect(renderer, &pion[i][j]);
            }
            else if(o[i][j] == BLACK){
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                SDL_RenderFillRect(renderer, &pion[i][j]);
            }
        }
    }

	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	for(int i=0 ; i<nbMove ; i++){
		drawCircle(renderer, stone[c_possible[i].x][c_possible[i].y], 5);
	}

    SDL_RenderPresent(renderer);
}
