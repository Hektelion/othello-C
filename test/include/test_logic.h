#ifndef TEST_LOGIC_H
#define TEST_LOGIC_H

int init_logic_suite0(void);
int clean_logic_suite0(void);

int init_logic_suite1(void);
int clean_logic_suite1(void);

int init_logic_suite2(void);
int clean_logic_suite2(void);

int init_logic_suite3(void);
int clean_logic_suite3(void);

//Couche 0
void test_printOthello();
void test_initOthello();
void test_isInOthello();
void test_nextPlayer();

//Couche 1
void test_addStone();
void test_delStone();
void test_isValidMove();
void test_reverseStone();

//Couche 2
void test_isOver();
void test_chooseMove();

//Couche 3
void test_playOthello();

#endif //TEST_LOGIC_H
