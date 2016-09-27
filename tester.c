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
	double x[2];

	emQuadEq(4, -4, 1, &x[0], &x[1]);

	printf("x1=%0.4lf; x2=%0.4lf", x[0], x[1]);
	return 0;
}

