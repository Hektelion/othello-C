#ifndef TEST_IA_H
#define TEST_IA_H

int init_ia_suite0(void);
int clean_ia_suite0(void);

int init_ia_suite1(void);
int clean_ia_suite1(void);

int init_ia_suite2(void);
int clean_ia_suite2(void);

//Couche 0
void test_nb_stone();

//Couche 1
void test_eval_quant();
void test_get_nbMove();
void test_get_validMove();

//Couche 2
void test_minimax();

#endif //TEST_IA_H
