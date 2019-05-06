/*
 *
 *
 *
 */

#include <stdio.h>
#include <CUnit/Basic.h>
#include "./../../include/othello_logic.h"
#include "./../include/test_logic.h"

static char o[N][N];

/* Fonction d'initialisation de la suite 0
 * retourne 0 en cas de succes, sinon -1
 */
int init_logic_suite0(void)
{
	return 0;
}

/* Fonction de nettoyage de la suite 0
 * retourne 0 en cas de succes, sinon -1
 */
int clean_logic_suite0(void)
{
	return 0;
}

/* Fonction d'initialisation de la suite 1
 * retourne 0 en cas de succes, sinon -1
 */
int init_logic_suite1(void)
{
	return 0;
}

/* Fonction de nettoyage de la suite 1
 * retourne 0 en cas de succes, sinon -1
 */
int clean_logic_suite1(void)
{
	return 0;
}

/* Fonction d'initialisation de la suite 2
 * retourne 0 en cas de succes, sinon -1
 */
int init_logic_suite2(void)
{
	return 0;
}

/* Fonction de nettoyage de la suite 2
 * retourne 0 en cas de succes, sinon -1
 */
int clean_logic_suite2(void)
{
	return 0;
}

/* Fonction d'initialisation de la suite 3
 * retourne 0 en cas de succes, sinon -1
 */
int init_logic_suite3(void)
{
	return 0;
}

/* Fonction de nettoyage de la suite 3
 * retourne 0 en cas de succes, sinon -1
 */
int clean_logic_suite3(void)
{
	return 0;
}

//TEST UNITAIRE

//Test couche 0

/*
 *
 *
 */
void test_printOthello()
{
	CU_ASSERT( printOthello(o) == 0 );
}

/*
 *
 *
 */
void test_initOthello()
{
	CU_ASSERT( initOthello(o) == 0 );
}

/*
 *
 *
 */
void test_isInOthello()
{
	CU_ASSERT(isInOthello(5, 3) == 1);
	CU_ASSERT(isInOthello(2, 1) == 1);
	CU_ASSERT(isInOthello(-1, 3) == 0);
	CU_ASSERT(isInOthello(1, 20) == 0);
}

/*
 *
 *
 */
void test_nextPlayer()
{
	int player = 0;

	CU_ASSERT( (player = nextPlayer(player)) == 1 );
	CU_ASSERT( (player = nextPlayer(player)) == 0 );
	CU_ASSERT( (player = nextPlayer(player)) == 1 );
	CU_ASSERT( (player = nextPlayer(player)) == 0 );
}

//TEST INTEGRATION

//Test couche 1

/*
 *
 *
 */
void test_addStone()
{

	int player = 0;
	int x, y;

	initOthello(o);

	x = 4;
	y = 5;
	CU_ASSERT( addStone(o, x, y, player) == 0);

	player = nextPlayer(player);

	x = 6;
	y = 7;
	CU_ASSERT( addStone(o, x, y, player) == 0);

	player = nextPlayer(player);

	x = 7;
	y = 9;
	CU_ASSERT( addStone(o, x, y, player) == -1);

	player = nextPlayer(player);

	x = 10;
	y = 7;
	CU_ASSERT( addStone(o, x, y, player) == -1);

}

/*
 *
 *
 */
void test_delStone()
{
	int x, y;

	initOthello(o);

	x = 4;
	y = 5;
	CU_ASSERT( delStone(o, x, y) == 0);

	x = 6;
	y = 7;
	CU_ASSERT( delStone(o, x, y) == 0);

	x = 7;
	y = 9;
	CU_ASSERT( delStone(o, x, y) == -1);

	x = 10;
	y = 7;
	CU_ASSERT( delStone(o, x, y) == -1);
}

/*
 *
 *
 */
void test_isValidMove()
{
	int player = 0;
	int x, y;

	initOthello(o);

	x = 4;
	y = 2;
	CU_ASSERT( isValidMove(o, x, y, player) == 1);

	player = nextPlayer(player);

	x = 3;
	y = 2;
	CU_ASSERT( isValidMove(o, x, y, player) == 1);

	player = nextPlayer(player);

	x = 7;
	y = 9;
	CU_ASSERT( isValidMove(o, x, y, player) == 0);

	player = nextPlayer(player);

	x = 6;
	y = 6;
	CU_ASSERT( isValidMove(o, x, y, player) == 0);
}

/*
 *
 *
 */
void test_reverseStone()
{
	int player = 0;
	int x, y;

	initOthello(o);

	x = 4;
	y = 2;
	addStone(o, player, x, y);
	CU_ASSERT( reverseStone(o, x, y, player) > 0);

	player = nextPlayer(player);

	x = 6;
	y = 6;
	addStone(o, player, x, y);
	CU_ASSERT( reverseStone(o, x, y, player) == 0);

	player = nextPlayer(player);

	x = 7;
	y = 9;
	addStone(o, player, x, y);
	CU_ASSERT( reverseStone(o, x, y, player) == 0);
}

//Test couche 2

/*
 *
 *
 */
void test_isOver()
{
	int player = 0;

	initOthello(o);

	CU_ASSERT( isOver(o,player) == 1);

	player = nextPlayer(player);

	CU_ASSERT( isOver(o,player) == 1);

	for(int i=0 ; i<N ; i++){
       for(int j=0 ; j<N ; j++){
		   o[i][j] = BLANK;
	   }
	}

	CU_ASSERT( isOver(o,player) == 0);

	player = nextPlayer(player);

	for(int i=0 ; i<N ; i++){
       for(int j=0 ; j<N ; j++){
		   o[i][j] = BLACK;
	   }
	}

	CU_ASSERT( isOver(o,player) == 0);

	player = nextPlayer(player);

	CU_ASSERT( isOver(o,player) == 0);
}

//TEST VALIDATION

//Test couche 3

/*
 *
 *
 */
void test_playOthello()
{

}
