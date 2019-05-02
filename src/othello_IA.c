#include "../include/othello_IA.h"
#include "../include/include.h"

/* Entrées    : a (un réel), b (un réel)
 * Sorties    : Le plus grand element
 * Variables  :
 * Traitement : Calcul le plus grand élément en effectuant une comparaison
 */
float max(float a,float b)
{
	if (a > b)
		return a;
	else
		return b;
}

/* Entrées    : a (un réel), b (un réel)
 * Sorties    : Le plus petit element
 * Variables  :
 * Traitement : Calcul le plus petit élément en effectuant une comparaison
 */
float min(float a,float b)
{
	if (a < b)
		return a;
	else
		return b;
}

/* Entrées    : o (un tableau 2D de caractères), copy_o (un tableau 2D de caractères)
 * Sorties    :
 * Variables  :
 * Traitement :	copy le tableau o (source) dans le tableau copy_o (cible)
 */
void copy_othello(char o[][N], char copy_o[][N]){
	for(int i=0 ; i<N ; i++){
		for(int j=0 ; j<N ; j++){
			copy_o[i][j] = o[i][j];
		}
	}
}

/* Entrées    : o (un tableau 2D de caractères), black_stone (un entier),
				white_stone (un entier)
 * Sorties    :
 * Variables  :
 * Traitement : Calcul le nombre de pierre blanche et noir
 */
void nb_stone(char o[][N], int *black_stone, int *white_stone){
	black_stone = 0;
	white_stone = 0;

	for(int i=0 ; i<N ; i++){
		for(int j=0 ; j<N ; j++){
			if(o[i][j] == BLACK)
				black_stone++;
			else if(o[i][j] == WHITE)
				white_stone++;
		}
	}
}

/* Entrées    : o (un tableau 2D de caractères)
 * Sorties    : un entier
 * Variables  :	black_stone (un entier), white_stone (un entier)
 * Traitement : Calcul la difference entre black_stone et white_stone
 				à un signe près et la retourne
 */
int eval_quant(char o[][N]){
	int black_stone;
	int white_stone;

	nb_stone(o, &black_stone, &white_stone);

	return (black_stone - white_stone);
}

/* Entrées    : o (un tableau 2D de caractères), player (un entier)
 * Sorties    : cnt_move (un entier)
 * Variables  : cnt_move (un entier)
 * Traitement : Détermine le nombre de coup possible pour un joueur donné
 				et renvoi le resultat
 */
int get_nbMove(char o[][N], int player){
	int cnt_move = 0;

	for(int i=0 ; i<N ; i++){
		for(int j=0 ; j<N ; j++){
			if( (o[i][j] == BLANK) && isValidMove(o, i, j, player) )
				cnt_move++;
		}
	}

	return cnt_move;
}

/* Entrées    : o (un tableau 2D de caractères), c_possible (un tableau de coup)
				player (un entier)
 * Sorties    :
 * Variables  : id (un entier)
 * Traitement : Rempli un tableau de coup avec les coup possible pour un joueur
 				donné
 */
void get_validMove(char o[][N], coup c_possible[], int player){
	int id=0;

	for(int i=0 ; i<N ; i++){
		for(int j=0 ; j<N ; j++){
			if( (o[i][j] == BLANK) && (isValidMove(o, i, j, player)) ){
				c_possible[id].x = i;
				c_possible[id].y = j;
				id++;
			}
		}
	}
}

/* Entrées    : o (un tableau 2D de caractères), depth (un entier),
				player (un entier)
 * Sorties    : la valeur évalué
 * Variables  : copy_o (un tableau 2D de caractères), value (un entier),
 				nbMove (un entier), c_possible (un tableau de coup)
 * Traitement : Determine à une profondeur donné et à l'aide d'appel recursif
 				le meileur coup (d'après la fonction d'évaluation utilisé)
 */
float minimax(char o[][N], int depth, int player){
	char copy_o[N][N];
	float value;
	int nbMove;
	coup *c_possible;

	//Cas terminal
	if( depth <= 0 || !isOver(o, player) ){
		return (float)eval_quant(o);
	}

	nbMove = get_nbMove(o, player);
	c_possible = malloc(nbMove * sizeof(coup));
	get_validMove(o, c_possible, player);

	if(player){	//MAXIMUM
		value = -VAL_INF;
		for(int i=0 ; i<nbMove ; i++){
			//Fait une copie temporaire de l'othellier passer en parametre
			copy_othello(o, copy_o);

			//Ajoute et effectue le Retournement sur l'othelier
			addStone(copy_o, c_possible[i].x, c_possible[i].y, player);
			reverseStone(copy_o, c_possible[i].x, c_possible[i].y, player);

			//Determine le max entre value et le retour de minimax()
			value = max(value, minimax(copy_o, depth-1, nextPlayer(player)));
		}
	}
	else{	//MINIMUM
		value = VAL_INF;
		for(int i=0 ; i<nbMove ; i++){
			//Fait une copie temporaire de l'othellier passer en parametre
			copy_othello(o, copy_o);

			//Ajoute et effectue le Retournement sur l'othelier
			addStone(copy_o, c_possible[i].x, c_possible[i].y, player);
			reverseStone(copy_o, c_possible[i].x, c_possible[i].y, player);

			//Determine le min entre value et le retour de minimax()
			value = min(value, minimax(copy_o, depth-1, nextPlayer(player)));
		}
	}

	//Libère la mémoire allouée
	free(c_possible);

	return value;

}
