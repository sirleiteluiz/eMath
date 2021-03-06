/*
 * tester.c
 *
 *  Created on: 27 de set de 2016
 *      Author: Luiz Leite
 */

#include <stdio.h>
#include <stdlib.h>

#include "emath_mat.h"

int main(void){
	em_matrix mat;

	emShowMatrix(&mat);
	printf("\n");

	emInitMatrix(&mat, 1, 1);

	emShowMatrix(&mat);
	printf("\n");

	emNsMatrix(&mat, 2);

	emShowMatrix(&mat);
	printf("\n");

	emMatrixConstMult(&mat, 3);

	emShowMatrix(&mat);
	printf("\n");

	emMatrixUnit(&mat);

	emShowMatrix(&mat);
	printf("\n");

	emMatrixAddCol(&mat);
	emMatrixAddRow(&mat);

	emShowMatrix(&mat);
	printf("\n");

	emMatrixRemoveCol(&mat);
	emMatrixRemoveRow(&mat);
	emMatrixRemoveRow(&mat);

	emShowMatrix(&mat);
	printf("\n");

	return 0;
}

