#include "../include/othello_draw.h"
#include "../include/include.h"

/* Entrées    : renderer (un moteur de rendu)
 * Sorties    : Le code d'erreur de la fonction
 * Variables  : width (un entier), heigth (un entier)
 * Traitement : Cette fonction initialise les elements
 				utilisé dans l'intro
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
 * Traitement : Dessine à l'écran l'introduction du jeu
 				puis effectue une pause
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
 * Traitement : Cette fonction initialise les elements
 				utilisé dans le dessin du menu
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

/* Entrées    : renderer (un moteur de rendu)
 * Sorties    : Le code d'erreur de la fonction
 * Variables  : width (un entier), heigth (un entier)
 * Traitement : Cette fonction initialise les elements
 				utilisé dans le dessin du plateau
 */
int initDrawGAME(SDL_Renderer *renderer){
	int width;
    int heigth;

    //Récupération de la taille de l'affichage
    SDL_GetRendererOutputSize(renderer, &width, &heigth);



	return EXIT_SUCCESS;
}

/* Entrées    : renderer (un moteur de rendu), o (un tableau 2D de caractères)
 * Sorties    :
 * Variables  : font (un rectangle), othello (un rectangle)
 				othello_lines (un tableau 2D de point)
				ecart (un entier), stone (un tableau 2D de point),
				pion (un entier)
 * Traitement : Cette fonction dessine les éléments du jeu
 */
void drawGAME(SDL_Renderer *renderer, char o[][N]){
	SDL_Rect font;
    SDL_Rect othello;
    SDL_Point othello_lines[(N-1)*4];
    int ecart=50;
    SDL_Point stone[N][N];
    SDL_Rect pion;

	//Background Blanc
	SDL_SetRenderDrawColor(renderer, 255,255,255,255);
	SDL_RenderClear(renderer);

    pion.h = ((HEIGHT_OTHELLO-(2*ecart))/N)/2;
    pion.w = ((WIDTH_OTHELLO-(2*ecart))/N)/2;

    font.x = 0;
    font.y = 0;
    font.h = HEIGHT_OTHELLO;
    font.w = WIDTH_OTHELLO;

    SDL_SetRenderDrawColor(renderer, 211, 84, 0, 255);
    SDL_RenderFillRect(renderer, &font);

    othello.x = ecart;
    othello.y = ecart;
    othello.h = HEIGHT_OTHELLO-2*ecart;
    othello.w = WIDTH_OTHELLO-2*ecart;

    SDL_SetRenderDrawColor(renderer, 39, 174, 96, 255);
    SDL_RenderFillRect(renderer, &othello);

    for(int i=0 ; i<(N-1)*2 ; i=i+2){
        othello_lines[i].x = ecart;
        othello_lines[i].y = ecart + (1 + (i/2))*( (HEIGHT_OTHELLO-(2*ecart))/N );
        othello_lines[i+1].x = WIDTH_OTHELLO-ecart;
        othello_lines[i+1].y = ecart + (1 + (i/2))*( (HEIGHT_OTHELLO-(2*ecart))/N );
        //printf("%d\n", i);
    }

    for(int i=(N-1)*2 ; i<(N-1)*4 ; i=i+2){
        othello_lines[i].x = ecart + (1 + ((i - (N-1)*2 )/2))*( (WIDTH_OTHELLO-(2*ecart))/N );
        othello_lines[i].y = ecart;
        othello_lines[i+1].x = ecart + (1 + ((i - (N-1)*2 )/2))*( (WIDTH_OTHELLO-(2*ecart))/N );
        othello_lines[i+1].y = HEIGHT_OTHELLO - ecart;
        //printf("%d\n", i);
    }

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    for(int i=0 ; i<(N-1)*4 ; i=i+2){
        SDL_RenderDrawLine(renderer, othello_lines[i].x, othello_lines[i].y, othello_lines[i+1].x, othello_lines[i+1].y);
    }

    for(int i=0 ; i<N ; i++){
        for(int j=0 ; j<N ; j++){
            stone[i][j].x = ecart + ((WIDTH_OTHELLO-(2*ecart))/N)/2 + j * (WIDTH_OTHELLO-(2*ecart))/N;
            stone[i][j].y = ecart + ((HEIGHT_OTHELLO-(2*ecart))/N)/2 + i * (HEIGHT_OTHELLO-(2*ecart))/N;
        }
    }

    for(int i=0 ; i<N ; i++){
        for(int j=0 ; j<N ; j++){
            if(o[i][j] == WHITE){
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
                pion.x = stone[i][j].x - ((WIDTH_OTHELLO-(2*ecart))/N)/4;
                pion.y = stone[i][j].y - ((HEIGHT_OTHELLO-(2*ecart))/N)/4;
                SDL_RenderFillRect(renderer, &pion);
            }
            else if(o[i][j] == BLACK){
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                pion.x = stone[i][j].x - ((WIDTH_OTHELLO-(2*ecart))/N)/4;
                pion.y = stone[i][j].y - ((HEIGHT_OTHELLO-(2*ecart))/N)/4;
                SDL_RenderFillRect(renderer, &pion);
            }
            else{

            }
        }
    }

    SDL_RenderPresent(renderer);
}
