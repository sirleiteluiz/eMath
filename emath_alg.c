/*
 * emath_alg.c
 *
 *  Created on: 27 de set de 2016
 *      Author: Luiz Leite
 */

#include "emath_alg.h"
#include <math.h>

void emQuadEq(double a, double b, double c, double* x1, double* x2){
	double delta = (pow(b, 2.0)-(4.0*a*c));

	//delta >= 0;
	if(delta>=0){
		*x1 = (-b+sqrt(delta))/(2.0*a);
		*x2 = (-b-sqrt(delta))/(2.0*a);
	}

	return;
}
