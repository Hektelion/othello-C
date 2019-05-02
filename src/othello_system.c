#include "../include/othello_system.h"
#include "../include/include.h"

/* Entrées    :
 * Sorties    :
 * Variables  :
 * Traitement :
 */
int init_SDL(){
	//============================================
	//			INITIALISATION DE SDL2
	//============================================

	//LOG
	fprintf(stdout, "Initialisation de la bibliothèque SDL...\n");
	//Initialisation de la SDL
    if( SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) != 0 ){
        fprintf(stderr, "Erreur SDL_Init : %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }
	//LOG
	fprintf(stdout, "Initialisation de la bibliothèque SDL : OK\n");
	return EXIT_SUCCESS;
}

/* Entrées    :
 * Sorties    :
 * Variables  :
 * Traitement :
 */
int init_SDL_TTF(){
	//============================================
	//			INITIALISATION DE SDL_ttf
	//============================================

	//LOG
	fprintf(stdout, "Initialisation de la bibliothèque SDL_ttf...\n");
    //Initialisation de TTF
    if( TTF_Init() != 0 ){
        fprintf(stderr, "Erreur TTF_Init : %s\n", TTF_GetError());
        return EXIT_FAILURE;
    }
	//LOG
	fprintf(stdout, "Initialisation de la bibliothèque SDL_ttf : OK\n");
	return EXIT_SUCCESS;
}

/* Entrées    :
 * Sorties    :
 * Variables  :
 * Traitement :
 */
int create_window(SDL_Window **window){
	//============================================
	//			CREATION DE LA FENETRE
	//============================================

	//LOG
	fprintf(stdout, "Création de la fenetre...\n");
    //Création de la fenetre
    *window = SDL_CreateWindow("OTHELLO",	//Nom de la fenetre
                                       0,	//Origine x
                                       0,	//Origine y
						   WIDTH_OTHELLO,	//Largeur
                          HEIGHT_OTHELLO,	//Hauteur
                   SDL_WINDOW_RESIZABLE);	//Flags
    //Gestion de l'erreur si la fenetre n'a pas été crée
    if(*window == NULL){
        fprintf(stderr, "Erreur SDL_CreateWindow : %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }
    //LOG
    fprintf(stdout, "Création de la fenetre : OK\n");
	return EXIT_SUCCESS;
}

/* Entrées    :
 * Sorties    :
 * Variables  :
 * Traitement :
 */
int create_renderer(SDL_Window *window, SDL_Renderer **renderer){
	//============================================
	//		CREATION DU MOTEUR DE RENDU
	//============================================

	//LOG
	fprintf(stdout, "Création du moteur de rendu...\n");
    //Création du moteur de rendu
    (*renderer) = SDL_CreateRenderer(window,	//Fenetre cible du moteur de rendu
                                      -1,	//Index
                SDL_RENDERER_ACCELERATED);	//Flags
    //Gestion de l'erreur si le moteur de rendu n'a pas été crée
    if( (*renderer) == NULL){
        fprintf(stderr, "Erreur SDL_CreateRenderer : %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }
    //LOG
    fprintf(stdout, "Création du moteur de rendu : OK\n");
	return EXIT_SUCCESS;
}

/* Entrées    :
 * Sorties    :
 * Variables  :
 * Traitement :
 */
int init_System(SDL_Window *window, SDL_Renderer **renderer){
	if( init_SDL() ){
		return EXIT_FAILURE;
	}
	if( init_SDL_TTF() ){
		return EXIT_FAILURE;
	}
	if( create_window(&window) ){
		return EXIT_FAILURE;
	}
	if( create_renderer(window, renderer ) ){
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}

/* Entrées    :
 * Sorties    :
 * Variables  :
 * Traitement :
 */
void close_window(SDL_Window *window){
	//============================================
	//		DESTRUCTION DE LA FENETRE
	//============================================

	//Si la fenetre est initialisée
	if(window != NULL){
        fprintf(stdout, "Destruction de la fenetre\n");
        SDL_DestroyWindow(window);
    }
}

/* Entrées    :
 * Sorties    :
 * Variables  :
 * Traitement :
 */
void close_renderer(SDL_Renderer *renderer){
	//============================================
	//		DESTRUCTION DU MOTEUR DE RENDU
	//============================================

	if(renderer != NULL){
        fprintf(stdout, "Destruction du moteur de rendu\n");
        SDL_DestroyRenderer(renderer);
    }
}

/* Entrées    :
 * Sorties    :
 * Variables  :
 * Traitement :
 */
void close_System(SDL_Window *window, SDL_Renderer *renderer){
	close_window(window);
	close_renderer(renderer);
	fprintf(stdout, "La SDL Quitte\n");
    SDL_Quit();
    //fprintf(stdout, "L'application n'a rencontrer aucun problème\n");
}
