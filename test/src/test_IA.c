/*
 *
 *
 *
 */

#include <stdio.h>
#include <CUnit/Basic.h>
#include "./../../include/othello_logic.h"
#include "./../../include/othello_IA.h"
#include "./../include/test_logic.h"
#include "./../include/test_IA.h"

static char o[N][N];

int init_ia_suite0(void){
	return 0;
}
int clean_ia_suite0(void){
	return 0;
}

int init_ia_suite1(void){
	return 0;
}
int clean_ia_suite1(void){
	return 0;
}

int init_ia_suite2(void){
	return 0;
}
int clean_ia_suite2(void){
	return 0;
}

//Couche 0
void test_nb_stone(){
	int nb_blanc;
	int nb_noir;

	initOthello(o);

	nb_stone(o, &nb_noir, &nb_blanc);
	CU_ASSERT(nb_noir == 2);
	CU_ASSERT(nb_blanc == 2);

	addStone(o, 6, 6, 0);

	nb_stone(o, &nb_noir, &nb_blanc);
	CU_ASSERT(nb_noir == 2);
	CU_ASSERT(nb_blanc == 3);

}

//Couche 1
void test_eval_quant(){
	initOthello(o);

	CU_ASSERT(eval_quant(o) == 0);

	addStone(o, 6, 6, 0);

	CU_ASSERT(eval_quant(o) == -1);

	delStone(o, 6, 6);
	addStone(o, 6, 6, 1);
	addStone(o, 6, 7, 1);

	CU_ASSERT(eval_quant(o) == 2);
}
void test_get_nbMove(){
	initOthello(o);

	CU_ASSERT(get_nbMove(o, 0) == 4);

	addStone(o, 3, 5, 0);

	CU_ASSERT(get_nbMove(o, 0) == 3);
}
void test_get_validMove(){
	int nbMove;

	initOthello(o);

	nbMove = get_nbMove(o, 0);
	coup c_possible[nbMove];
	get_validMove(o, c_possible, 0);

	CU_ASSERT(c_possible[0].x == 2);
	CU_ASSERT(c_possible[0].y == 4);

	CU_ASSERT(c_possible[1].x == 3);
	CU_ASSERT(c_possible[1].y == 5);

	CU_ASSERT(c_possible[2].x == 4);
	CU_ASSERT(c_possible[2].y == 2);

	CU_ASSERT(c_possible[3].x == 5);
	CU_ASSERT(c_possible[3].y == 3);

}

//Couche 2
void test_minimax(){
	initOthello(o);

	int player = 0;
	int nbMove = get_nbMove(o, player);
	coup c_possible[nbMove];

	get_validMove(o, c_possible, player);

	for(int id_move=0 ; id_move < nbMove ; id_move++){
		CU_ASSERT(minimax(o, 4, player) == 2.0);
	}
}
