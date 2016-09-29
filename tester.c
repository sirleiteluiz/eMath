/*
 * tester.c
 *
 *  Created on: 27 de set de 2016
 *      Author: Luiz Leite
 */

#include <stdio.h>
#include <stdlib.h>
#include "emath_alg.h"

int main(void){
	em_matrix mat;

	emShowMatrix(&mat);
	printf("\n");

	emInitMatrix(&mat, 4, 100);

	emShowMatrix(&mat);
	printf("\n");

	emFreeMatrix(&mat, mat.rows);

	emShowMatrix(&mat);
	printf("\n");

	return 0;
}

