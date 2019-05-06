/*
*
*
*
*/

#include <stdio.h>
#include <CUnit/Basic.h>
#include "../include/test_logic.h"
#include "../include/test_draw.h"
#include "../include/test_system.h"
#include "../include/test_IA.h"

/* La fonction main() pour le parametrage et le lancement des test
* Retourne CUE_SUCCESS si le lancement du test reussi
* Sinon un code erreur CUnit en cas d'echec
*/
int main()
{
	CU_pSuite pSuite = NULL;

	printf("\nTEST LOGIQUE\n");

	//Initialise le registre de test de CUnit
	if (CUE_SUCCESS != CU_initialize_registry())
	return CU_get_error();

	//Ajoute la suite au registre
	pSuite = CU_add_suite("Layer_0", init_logic_suite0, clean_logic_suite0);
	if (NULL == pSuite) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	// Ajoute les tests de la couche 0 à la suite
	if ( ( CU_add_test(pSuite, "test of initOthello()", test_initOthello) ) == NULL ||
	( CU_add_test(pSuite, "test of printOthello()", test_printOthello) ) == NULL ||
	( CU_add_test(pSuite, "test of isInOthello()", test_isInOthello) ) == NULL ||
	( CU_add_test(pSuite, "test of nextPlayer()", test_nextPlayer)   ) == NULL ) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	//Ajoute la suite au registre
	pSuite = CU_add_suite("Layer_1", init_logic_suite1, clean_logic_suite1);
	if (NULL == pSuite) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	// Ajoute les tests de la couche 1 à la suite
	if ( ( CU_add_test(pSuite, "test of addStone()", test_addStone)         ) == NULL ||
	( CU_add_test(pSuite, "test of delStone()", test_delStone)         ) == NULL ||
	( CU_add_test(pSuite, "test of isValidMove()", test_isValidMove)   ) == NULL ||
	( CU_add_test(pSuite, "test of reverseStone()", test_reverseStone) ) == NULL ) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	//Ajoute la suite au registre
	pSuite = CU_add_suite("Layer_2", init_logic_suite2, clean_logic_suite2);
	if (NULL == pSuite) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	// Ajoute les tests de la couche 2 à la suite
	if ( ( CU_add_test(pSuite, "test of isOver()", test_isOver)       ) == NULL ) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	//Ajoute la suite au registre
	pSuite = CU_add_suite("Layer_3", init_logic_suite3, clean_logic_suite3);
	if (NULL == pSuite) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	// Ajoute les tests de la couche 3 à la suite
	if ( ( CU_add_test(pSuite, "test of playOthello()", test_playOthello)) == NULL ) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	//Lance tout les tests en utilisant l'interface basique de CUnit
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();

	printf("\nTEST IA\n");

	//Initialise le registre de test de CUnit
	if (CUE_SUCCESS != CU_initialize_registry())
	return CU_get_error();

	//Ajoute la suite au registre
	pSuite = CU_add_suite("Layer_0", init_ia_suite0, clean_ia_suite0);
	if (NULL == pSuite) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	// Ajoute les tests de la couche 0 à la suite
	if ( ( CU_add_test(pSuite, "test of nb_stone()", test_nb_stone) ) == NULL ) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	//Ajoute la suite au registre
	pSuite = CU_add_suite("Layer_1", init_ia_suite1, clean_ia_suite1);
	if (NULL == pSuite) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	// Ajoute les tests de la couche 0 à la suite
	if ( ( CU_add_test(pSuite, "test of eval_quant()", test_eval_quant) ) == NULL ||
	( CU_add_test(pSuite, "test of get_nbMove()", test_get_nbMove) ) == NULL ||
	( CU_add_test(pSuite, "test of get_validMove()", test_get_validMove) ) == NULL ) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	//Ajoute la suite au registre
	pSuite = CU_add_suite("Layer_2", init_ia_suite2, clean_ia_suite2);
	if (NULL == pSuite) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	// Ajoute les tests de la couche 0 à la suite
	if ( ( CU_add_test(pSuite, "test of minimax()", test_minimax) ) == NULL ) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	//Lance tout les tests en utilisant l'interface basique de CUnit
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();
	return CU_get_error();
}
