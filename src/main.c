#include "../include/include.h"

int main(){
	//============================================
	//				  DECLARATION
	//============================================
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Rect options[6];
    SDL_Rect title;
    SDL_Rect menu;
    SDL_Point mouse;

	SDL_Surface *texte = NULL;
	TTF_Font *police = NULL;
	SDL_Color c_Noir = {0, 0, 0, 255};

    char choice;

	//============================================
	//				INITIALISATION
	//============================================

	//fprintf(stdout, "DEBUT INITIALISATION\n");

	if( init_System(window, &renderer) ){
		return EXIT_FAILURE;
	}

	police = TTF_OpenFont("font/honor.ttf", 22);
	if(police == NULL){
    	printf("TTF_OpenFont: %s\n", TTF_GetError());
    	return EXIT_FAILURE;
	}

	//fprintf(stdout, "FIN INITIALISATION\n");

	//============================================
	//				DEBUT
	//============================================

	initDrawINTRO(renderer);
    drawINTRO(renderer);

    do{
		initDrawMENU(renderer, &title, &menu, options);
		drawMENU(renderer, title, menu, options);

		texte = TTF_RenderText_Blended(police, "Salut les Zér0s !", c_Noir);

        SDL_Event event;

        //Traitement des la file d'evenements
        while ( SDL_PollEvent(&event) )
        {
            switch (event.type) {
                case SDL_MOUSEMOTION:
                    mouse.x = event.motion.x;
                    mouse.y = event.motion.y;
                break;
                case SDL_MOUSEBUTTONDOWN:
                    if(SDL_PointInRect(&mouse, &options[0]) == SDL_TRUE){
                        fprintf(stdout, "Lancement d'une partie joueur contre joueur\n");   //LOG
                        playOthello('0', renderer);
                    }
                    else if(SDL_PointInRect(&mouse, &options[1]) == SDL_TRUE){
                        fprintf(stdout, "Lancement d'une partie joueur contre IA\n");   //LOG
                        //playOthello('1', renderer, config);
                    }
					else if(SDL_PointInRect(&mouse, &options[2]) == SDL_TRUE){
                        fprintf(stdout, "Lancement des options\n");   //LOG
						drawOPTION(renderer);

                    }
                    else if(SDL_PointInRect(&mouse, &options[3]) == SDL_TRUE){
                        fprintf(stdout, "Affichage des règles du jeu\n");   //LOG
                        drawRULE(renderer);
                    }
                    else if(SDL_PointInRect(&mouse, &options[4]) == SDL_TRUE){
                        fprintf(stdout, "Affichage des commandes du jeu\n");   //LOG
                        drawCOMMAND(renderer);
                    }
                    else if(SDL_PointInRect(&mouse, &options[5]) == SDL_TRUE){
                        fprintf(stdout, "L'application quitte\n");   //LOG
                        choice = 'q';
                    }
                break;
            }
        }
    }
    while(choice != 'q'); // Tant que l'on veut que le jeu fonctionne

	//============================================
	//						FIN
	//============================================

	TTF_CloseFont(police);

	close_System( window, renderer );

    return EXIT_SUCCESS;
}
