#include "../include/othello_logic.h"
#include "../include/include.h"

/* Entrées    : o (un tableau 2D de caractères)
 * Sorties    : Le code d'erreur de la fonction
 * Variables  :
 * Traitement : Initialise l'othellier dans un premier temps à vide
 				puis de façon reglementaire
 */
int initOthello(char o[][N]){
	//INITIALISATION A VIDE
	//fprintf(stdout, "Initialisation à vide\n");
	for(int i=0 ; i<N ; i++){
		for(int j=0 ; j<N ; j++){
			o[i][j] = BLANK;
		}
	}

	//INITIALISATION REGLEMENTAIRE
	//fprintf(stdout, "Initialisation reglementaire\n");
	o[N/2-1][N/2-1] = WHITE;
	o[N/2-1][N/2] = BLACK;
	o[N/2][N/2-1] = BLACK;
	o[N/2][N/2] = WHITE;

	return 0;
}

/* Entrées    : o (un tableau 2D de caractères)
 * Sorties    : Le code d'erreur de la fonction
 * Variables  :
 * Traitement : Affiche l'othellier dans le terminal
 				(Utiliser en tant que log)
 */
int printOthello(char o[][N]){

	printf("\n");

	for(int i=0 ; i<N ; i++){
		printf("  %c ", i+65);
	}
	printf("\n");
	printf("+");
	for(int i=0 ; i<N ; i++){
		printf("---+");
	}
	printf("\n");
	for(int i=0 ; i<N ; i++){
		printf("|");
		for(int j=0 ; j<N ; j++){
			printf(" %c |", o[i][j]);
		}
		printf(" %d\n", i+1);
		printf("+");
		for(int j=0 ; j<N ; j++){
			printf("---+");
		}
		printf("\n");
	}

	return 0;
}

/* Entrées    : x (un entier), y (un entier)
 * Sorties    : le resultat d'une assertion
 * Variables  :
 * Traitement : en fonction des coordonnées passé en paramètre
 				renvoi 1 si le point est dans l'othellier sinon renvoi 0
 */
int isInOthello(int x, int y){
	return ( (y >= 0) && (y < N) && (x >= 0) && (x < N) );
}

/* Entrées    : player (un entier)
 * Sorties    : le joueur suivant
 * Variables  :
 * Traitement : renvoi le joueur suivant (0 ou 1)
 */
int nextPlayer(int player){
	return( player+1 )%2;
}

/* Entrées    : o (un tableau 2D de caractères), x (un entier), y (un entier),
				player (un entier)
 * Sorties    : Le code d'erreur de la fonction
 * Variables  :
 * Traitement : Ajoute une pierre sur l'othellier
 */
int addStone(char o[][N], int x, int y, int player){
	//ATTRIBUTION DES PIONS ALLY ET ENEMY
	if( isInOthello(x,y) ){
		if(player == 0){
			o[x][y] = WHITE;
		}
		else{
			o[x][y] = BLACK;
		}
		return 0;
	}
	else{
		//fprintf(stderr, "Erreur addStone : le coup (%d,%d) n'est pas dans le plateau\n", x, y);
		return -1;
	}
}

/* Entrées    : o (un tableau 2D de caractères), x (un entier), y (un entier)
 * Sorties    : Le code d'erreur de la fonction
 * Variables  :
 * Traitement : Supprime une pierre de l'othellier
 */
int delStone(char o[][N], int x, int y){
	if( isInOthello(x,y) ){
		o[x][y] = BLANK;
		return 0;
	}
	else{
		//fprintf(stderr, "Erreur delStone : le coup (%d,%d) n'est pas dans le plateau\n", x, y);
		return -1;
	}
}

/* Entrées    : o (un tableau 2D de caractères), line (un entier),
				column (un entier), player (un entier)
 * Sorties    : un entier
 * Variables  : i  (un entier), j  (un entier), exec  (un entier),
 				cAlly (un caractère), cEnemy (un caractère)
 * Traitement : Retourne 1 si le coup est valide sinon renvoi 0
 */
int isValidMove(char o[][N], int line, int column, int player){
	int i, j, exec;
	char cAlly, cEnemy;

	//ATTRIBUTION DES PIONS ALLY ET ENEMY
	if(player == 0){
		cAlly = WHITE;
		cEnemy = BLACK;
	}
	else{
		cAlly = BLACK;
		cEnemy = WHITE;
	}

	//SI LE COUP N'EST PAS DANS LE PLATEAU OU OCCUPEE
	if( !isInOthello(line,column) || o[line][column] != BLANK) return 0;

	//HAUT
	i = line-1;
	exec = 0;
	while( isInOthello(i, column) && o[i][column] == cEnemy ){
		i--;
		exec = 1;
	}
	if( isInOthello(i, column) && o[i][column] == cAlly && exec == 1 ) return 1;

	//BAS
	i = line+1;
	exec = 0;
	while( isInOthello(i, column) && o[i][column] == cEnemy ){
		i++;
		exec = 1;
	}
	if( isInOthello(i, column) && o[i][column] == cAlly && exec == 1 ) return 1;

	//GAUCHE
	j = column-1;
	exec = 0;
	while( isInOthello(line, j) && o[line][j] == cEnemy ){
		j--;
		exec = 1;
	}
	if( isInOthello(line, j) && o[line][j] == cAlly && exec == 1 ) return 1;

	//DROITE
	j = column+1;
	exec = 0;
	while( isInOthello(line, j) && o[line][j] == cEnemy ){
		j++;
		exec = 1;
	}
	if( isInOthello(line, j) && o[line][j] == cAlly && exec == 1 ) return 1;

	//DIAGONALE HAUT DROIT
	i = line+1;
	j = column+1;
	exec = 0;
	while( isInOthello(i, j) && o[i][j] == cEnemy ){
		i++;
		j++;
		exec = 1;
	}
	if( isInOthello(i, j) && o[i][j] == cAlly && exec == 1 ) return 1;

	//DIAGONALE HAUT GAUCHE
	i = line+1;
	j = column-1;
	exec = 0;
	while( isInOthello(i, j) && o[i][j] == cEnemy ){
		i++;
		j--;
		exec = 1;
	}
	if( isInOthello(i, j) && o[i][j] == cAlly && exec == 1 ) return 1;

	//DIAGONALE BAS DROIT
	i = line-1;
	j = column+1;
	exec = 0;
	while( isInOthello(i, j) && o[i][j] == cEnemy ){
		i--;
		j++;
		exec = 1;
	}
	if( isInOthello(i, j) && o[i][j] == cAlly && exec == 1 ) return 1;

	//DIAGONALE BAS GAUCHE
	i = line-1;
	j = column-1;
	exec = 0;
	while( isInOthello(i, j) && o[i][j] == cEnemy ){
		i--;
		j--;
		exec = 1;
	}
	if( isInOthello(i, j) && o[i][j] == cAlly && exec == 1 ) return 1;

	return 0;
}

/* Entrées    : o (un tableau 2D de caractères), line (un entier),
				column (un entier), player (un entier)
 * Sorties    : Le nombre de pierre retourner
 * Variables  : i  (un entier), j  (un entier), cAlly (un caractère),
 				cEnemy (un caractère), cnt_reverse (un entier)
 * Traitement :	Renverse les pierre sur l'othellier d'apres le coup
 				jouer précedement, et renvoi le nombre de pierre retourner
 */
int reverseStone(char o[][N], int line, int column, int player){
	int i,j;
	char cAlly, cEnemy;
	int cnt_reverse = 0;

	//ATTRIBUTION DES PIONS ALLY ET ENEMY
	if(player == 0){
		cAlly = WHITE;
		cEnemy = BLACK;
	}
	else{
		cAlly = BLACK;
		cEnemy = WHITE;
	}

	//SI LE COUP N'EST PAS DANS LE PLATEAU
	if( !isInOthello(line,column) ) return 0;

	//HAUT
	i = line-1;
	while( isInOthello(i, column) && o[i][column] == cEnemy ) i--;
	if( isInOthello(i, column) && o[i][column] == cAlly){
		i = line-1;
		while( o[i][column] == cEnemy ){
			o[i][column] = cAlly;
			i--;
			cnt_reverse++;
		}
	}

	//BAS
	i = line+1;
	while( isInOthello(i, column) && o[i][column] == cEnemy ) i++;
	if( isInOthello(i, column) && o[i][column] == cAlly ){
		i = line+1;
		while( o[i][column] == cEnemy ){
			o[i][column] = cAlly;
			i++;
			cnt_reverse++;
		}
	}

	//GAUCHE
	j = column-1;
	while( isInOthello(line, j) && o[line][j] == cEnemy ) j--;
	if( isInOthello(line, j) && o[line][j] == cAlly ){
		j = column-1;
		while( o[line][j] == cEnemy ){
			o[line][j] = cAlly;
			j--;
			cnt_reverse++;
		}
	}

	//DROITE
	j = column+1;
	while( isInOthello(line, j) && o[line][j] == cEnemy ) j++;
	if( isInOthello(line, j) && o[line][j] == cAlly ){
		j = column+1;
		while( o[line][j] == cEnemy ){
			o[line][j] = cAlly;
			j++;
			cnt_reverse++;
		}
	}

	//DIAGONALE HAUT DROIT
	i = line+1;
	j = column+1;
	while( isInOthello(i, j) && o[i][j] == cEnemy ){
		i++;
		j++;
	}
	if( isInOthello(i, j) && o[i][j] == cAlly ){
		i = line+1;
		j = column+1;
		while( o[i][j] == cEnemy ){
			o[i][j] = cAlly;
			i++;
			j++;
			cnt_reverse++;
		}
	}

	//DIAGONALE HAUT GAUCHE
	i = line+1;
	j = column-1;
	while( isInOthello(i, j) && o[i][j] == cEnemy ){
		i++;
		j--;
	}
	if( isInOthello(i, j) && o[i][j] == cAlly ){
		i = line+1;
		j = column-1;
		while( o[i][j] == cEnemy ){
			o[i][j] = cAlly;
			i++;
			j--;
			cnt_reverse++;
		}
	}

	//DIAGONALE BAS DROIT
	i = line-1;
	j = column+1;
	while( isInOthello(i, j) && o[i][j] == cEnemy ){
		i--;
		j++;
	}
	if( isInOthello(i, j) && o[i][j] == cAlly ){
		i = line-1;
		j = column+1;
		while( o[i][j] == cEnemy ){
			o[i][j] = cAlly;
			i--;
			j++;
			cnt_reverse++;
		}
	}

	//DIAGONALE BAS GAUCHE
	i = line-1;
	j = column-1;
	while( isInOthello(i, j) && o[i][j] == cEnemy ){
		i--;
		j--;
	}
	if( isInOthello(i, j) && o[i][j] == cAlly ){
		i = line-1;
		j = column-1;
		while( o[i][j] == cEnemy ){
			o[i][j] = cAlly;
			i--;
			j--;
			cnt_reverse++;
		}
	}

	//fprintf(stdout, "cnt_reverse = %d\n", cnt_reverse);

	return cnt_reverse;
}

/* Entrées    : o (un tableau 2D de caractères), player (un entier)
 * Sorties    : un entier
 * Variables  : cnt (un entier)
 * Traitement : Renvoi 1 si il reste des coups à jouer sinon renvoi 0
 */
int isOver(char o[][N], int player){
	int cnt=0;

	for(int i=0 ; i<N ; i++){
		for(int j=0 ; j<N ; j++){
			if( (o[i][j] == BLANK) && isValidMove(o, i, j, player) )
				cnt++;
		}
	}
	/*
	for(int i=0 ; i<N ; i++){
		for(int j=0 ; j<N ; j++){
			if( (o[i][j] == BLACK) && isValidMove(o, i, j, nextPlayer(player)) )
				cnt++;
		}
	}
	*/

	if( cnt != 0 )
		return 1;

	return 0;
}

/* Entrées    : choice (un caractère), renderer (un moteur de rendu)
 * Sorties    : Le code d'erreur de la fonction
 * Variables  : o (un tableau 2D de caractères), player (un entier),
 				cnt (un entier), x (un entier), y (un entier),
				carreau (un tableau 2D de rectangle), point (un point)
 * Traitement : Lancement d'une partie d'othello, le type de partie differe
 				en fonction de la valeur de choice.
				 - '0' : Partie joueur contre joueur
				 - '1' : Partie joueur contre IA
				Elle affiche à l'écran la partie il suffit de cliquer sur l'écran
				pour jouer.
 */
int playOthello(char choice, SDL_Renderer *renderer){
	char o[N][N];
    int player = 0;
    int cnt = 0;
    int x,y;
    SDL_Rect carreau[N][N];
    SDL_Point point;

	int nbMove;

    initOthello(o);

    do{
		initDrawGAME(renderer, carreau);
        drawGAME(renderer, o, player);
		//printOthello(o);
        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);

        for(int i=0 ; i<N ; i++){
            for(int j=0 ; j<N ; j++){
                SDL_RenderFillRect(renderer, &carreau[i][j]);
            }
        }

        if( player == 0 || choice == '0' ){
            do{
                SDL_Event ev;

                //Mise a jour des événement
                while ( SDL_PollEvent(&ev) ) // Nous traitons les événements de la queue
                {
                    switch (ev.type) {
	                    case SDL_MOUSEMOTION:
	                        point.x = ev.motion.x;
	                        point.y = ev.motion.y;
	                        break;
	                    case SDL_MOUSEBUTTONDOWN:
	                        for(int i=0 ; i<N ; i++){
	                            for(int j=0 ; j<N ; j++){
	                                if(SDL_PointInRect(&point, &carreau[i][j])){
	                                    x = i;
	                                    y = j;
	                                }
	                            }
	                        }
	                        break;
						case SDL_KEYDOWN:
							switch (ev.key.keysym.scancode) {
								case SDL_SCANCODE_ESCAPE:
									return 0;
									break;
								default:
									break;
							}
							break;
						default:
							break;
                    }
                }
            }
            while(!isValidMove(o, x, y, player));
            addStone(o, x, y, player);
            reverseStone(o, x, y, player);
            player = nextPlayer(player);
        }
        else{
			nbMove = get_nbMove(o, player);
			coup c_possible[nbMove];
			float eval[nbMove];
			int max = -VAL_INF;

			get_validMove(o, c_possible, player);

			for(int id_move=0 ; id_move < nbMove ; id_move++){
				eval[id_move] = minimax(o, 4, player);
			}

			for(int id_move=0 ; id_move < nbMove ; id_move++){
				if(eval[id_move] > max){
					max = eval[id_move];
					x = c_possible[id_move].x;
					y = c_possible[id_move].y;
				}
			}

			addStone(o, x, y, player);
			reverseStone(o, x, y, player);

            player = nextPlayer(player);

        }
    }
    while(isOver(o, player));

    for(int i=0 ; i<N ; i++){
        for(int j=0 ; j<N ; j++){
            if( o[i][j] == WHITE )
                cnt++;
            else if( o[i][j] == BLACK )
                cnt--;
        }
    }

    if( cnt > 0 ){
		printf("le joueur 1 gagne\n");
	}
    else if( cnt < 0){
		printf("le joueur 2 gagne\n");
	}
    else{
		printf("match nul\n");
	}

	return 0;

}
