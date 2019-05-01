#ifndef TEST_LOGIC_H
#define TEST_LOGIC_H

//#include "../../include/othello_logic.h"

int init_suite0(void);
int clean_suite0(void);

int init_suite1(void);
int clean_suite1(void);

int init_suite2(void);
int clean_suite2(void);

int init_suite3(void);
int clean_suite3(void);

//Couche 0
void test_initOthello();
void test_isInOthello();
void test_nextPlayer();
void test_addStone();
void test_delStone();

//Couche 1
void test_isValidMove();
void test_reverseStone();

//Couche 2
void test_isOver();
void test_chooseMove();

//Couche 3
void test_playOthello();

#endif //TEST_LOGIC_H
