/*
 * emath_alg.c
 *
 *  Created on: 27 de set de 2016
 *      Author: Luiz Leite
 */

#include <math.h>
#include <malloc.h>
#include "emath_mat.h"


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


void emShowMatrix(const em_matrix* mat){
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

void emSetValueMatrix(em_matrix* mat, const unsigned int col, const unsigned int row, const double value){
	if(mat->initiated == INITIATED){
		if(mat->columns > col && mat->rows > row){
			mat->numbers[row][col] = value;
		}
	}
	return;
}

void emNsMatrix(em_matrix* mat, const double value){
	int i, j;

	if(mat->initiated == INITIATED){
		for(i=0; i<mat->rows; i++){
			for(j=0; j<mat->columns; j++){
				mat->numbers[i][j] = value;
			}
		}
	}

	return;
}

void emMatrixConstSum (em_matrix* mat, const double value){
	int i, j;

	if(mat->initiated == INITIATED){
		for(i=0; i<mat->rows; i++){
			for(j=0; j<mat->columns; j++){
				mat->numbers[i][j] += value;
			}
		}
	}

	return;
}

void emMatrixConstMult (em_matrix* mat, const double value){
	int i, j;

	if(mat->initiated == INITIATED){
		for(i=0; i<mat->rows; i++){
			for(j=0; j<mat->columns; j++){
				mat->numbers[i][j] *= value;
			}
		}
	}

	return;
}

void emMatrixUnit (em_matrix* mat){
	int i, j;
	if(mat->initiated == INITIATED){
		for(i=0; i<mat->rows; i++){
			for(j=0; j<mat->columns; j++){
				if(mat->numbers[i][j]>ZERO){
					mat->numbers[i][j] = 1.0;
				}
				else{
					if(mat->numbers[i][j]<ZERO){
						mat->numbers[i][j]=-1.0;
					}
					else {
						mat->numbers[i][j]=0.0;
					}
				}
			}
		}
	}
}

void emMatrixAddRow(em_matrix* mat){

	if(mat->initiated == INITIATED){
		mat->numbers = realloc(mat->numbers, (mat->rows + 1)*sizeof(mat->numbers[0]));
		if(mat->numbers){

			mat->numbers[mat->rows] = calloc(mat->columns, sizeof(mat->numbers[0][0]));
			if(!mat->numbers[mat->rows]){
				//FAILED TO ALLOCATE MEMORY
				emFreeMatrix(mat, mat->rows);
				return;
			}
			mat->rows++;
		}
		else{
			emFreeMatrix(mat, mat->rows);
		}
	}
}

void emMatrixAddCol(em_matrix* mat){
	int i;
	if(mat->initiated == INITIATED){
		mat->columns++;
		for(i=0;i<mat->rows;i++){
			mat->numbers[i] = realloc(mat->numbers[i], (mat->columns)*sizeof(mat->numbers[0][0]));
			if(!mat->numbers[i]){
				emFreeMatrix(mat, mat->rows);
				return;
			}
		}
	}
}

void emMatrixRemoveRow(em_matrix* mat){
	if(mat->initiated == INITIATED){
		if(mat->rows == 1){
			emFreeMatrix(mat, mat->rows);
			return;
		}
		else{
			free(mat->numbers[mat->rows]);
			mat->rows--;
			mat->numbers = realloc(mat->numbers, (mat->rows)*sizeof(mat->numbers[0]));
		}
	}
}

void emMatrixRemoveCol(em_matrix* mat){
	int i;
	if(mat->initiated == INITIATED){
		if(mat->columns == 1){
			emFreeMatrix(mat, mat->rows);
			return;
		}
		else{
			mat->columns--;
			for(i=0; i<mat->rows; i++){
				mat->numbers[i] = realloc(mat->numbers[i], (mat->columns)*sizeof(mat->numbers[0][0]));
			}
		}
	}
}
