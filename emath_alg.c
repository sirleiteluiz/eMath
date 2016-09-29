/*
 * emath_alg.c
 *
 *  Created on: 27 de set de 2016
 *      Author: Luiz Leite
 */

#include "emath_alg.h"
#include <math.h>
#include <malloc.h>

void emQuadEq(double a, double b, double c, double* x1, double* x2){
	double delta = (pow(b, 2.0)-(4.0*a*c));

	//delta >= 0;
	if(delta>=0){
		*x1 = (-b+sqrt(delta))/(2.0*a);
		*x2 = (-b-sqrt(delta))/(2.0*a);
	}

	//delta < 0;

	return;
}

void emInitMatrix(em_matrix* mat, const unsigned int cols, const unsigned int rows){
	int i;

	if(mat->initiated == INITIATED){
		emFreeMatrix(mat, mat->rows);
	}

	if(cols == ZERO || rows == ZERO){
		//INVALID SIZE
		mat->initiated = !INITIATED;
		return;
	}

	mat->numbers = calloc(rows, sizeof(mat->numbers[0]));

	if(mat->numbers){
		for(i=0; i<rows; i++){
			mat->numbers[i] = calloc(cols, sizeof(mat->numbers[0][0]));
			if(!mat->numbers[i]){
				//FAILED TO ALLOCATE MEMORY
				emFreeMatrix(mat, i);
				return;
			}
		}
		mat->columns = cols;
		mat->rows = rows;
		mat->initiated = INITIATED;
	}

	else{
		mat->columns = 0;
		mat->rows = 0;
		mat->initiated = !INITIATED;
		//FAILED TO ALLOCATE MEMORY
	}

	return;
}

void emFreeMatrix(em_matrix* mat, const unsigned int rows){
	int i;

	if(mat->initiated == INITIATED){
		for(i=0; i<rows; i++){
			free(mat->numbers[i]);
		}
		free(mat->numbers);
		mat->columns = 0;
		mat->rows = 0;
		mat->initiated = !INITIATED;
	}

	return;
}


void emShowMatrix(em_matrix* mat){
	int i, j;
	if(mat->initiated == INITIATED){
		for(i=0; i<mat->rows; i++){
			printf("| ");
			for(j=0; j<mat->columns; j++){
				printf("%lf ", mat->numbers[i][j]);
			}
			printf("|\n");
		}
	}
	else{
		printf("Matrix not initiated\n");
	}
}
