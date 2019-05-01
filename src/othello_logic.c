#include "../include/othello_logic.h"
#include "../include/include.h"

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
int isInOthello(int x, int y){
	return ( (y >= 0) && (y < N) && (x >= 0) && (x < N) );
}
int nextPlayer(int player){
	return( player+1 )%2;
}

int addStone(char o[][N], int player, int x, int y){
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
		return -1;
	}
}
int delStone(char o[][N], int x, int y){
	if( isInOthello(x,y) ){
		o[x][y] = BLANK;
		return 0;
	}
	else{
		return -1;
	}
}
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

	//SI IL N'Y A EU AUCUN RETOURNEMENT
	if( cnt_reverse == 0 ) return 0;

	return 1;
}
int chooseMove(){

}
int isOver(char o[][N], int player){
	int cnt=0;

	for(int i=0 ; i<N ; i++){
		for(int j=0 ; j<N ; j++){
			if( o[i][j] == BLANK )
			if( isValidMove(o, i, j, player) == 1)
			cnt++;
		}
	}
	if( cnt != 0 )
	return 1;

	return 0;
}

int playOthello(){

}
