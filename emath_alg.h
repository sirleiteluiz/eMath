/*
 * emath_alg.h
 *
 *  Created on: 27 de set de 2016
 *      Author: Luiz Leite
 */


#ifndef EMATH_ALG_H_
#define EMATH_ALG_H_

#define NULLPTR 0
#define ZERO 0
#define FALSE 0
#define TRUE !FALSE
#define INITIATED 523

typedef int em_checker;

typedef struct emMatrix{
	unsigned int columns;
	unsigned int rows;
	double** numbers;
	em_checker initiated;
} em_matrix;


#define em_vector em_matrix


void emQuadEq(double a, double b, double c, double* x1, double* x2);

void emInitMatrix(em_matrix* mat, const unsigned int cols, const unsigned int rows);
void emFreeMatrix(em_matrix* mat, const unsigned int rows);
void emShowMatrix(const em_matrix* mat);
void emSetValueMatrix(em_matrix* mat, const unsigned int col, const unsigned int row, const double value);
void emNsMatrix(em_matrix* mat, const double value);
void emMatrixConstSum(em_matrix* mat, const double value);
void emMatrixConstMult(em_matrix* mat, const double value);
void emMatrixUnit(em_matrix* mat);
void emMatrixAddRow(em_matrix* mat);
void emMatrixAddCol(em_matrix* mat);

#endif /* EMATH_ALG_H_ */
