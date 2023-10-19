#ifndef PPVAL_H
#define PPVAL_H

/* Include Files */

#include <stddef.h>
#include <stdlib.h>


typedef struct {
    double breaks[2];   // Starting and ending points of interval
    double coefs[4];    // Coefficients for polynomial
} PolynomialPiece;

void evaluatePolynomial(const PolynomialPiece pp, const double inputPoints[], const int inputSize[2], double outputValues[], int outputSize[2]);


#endif
