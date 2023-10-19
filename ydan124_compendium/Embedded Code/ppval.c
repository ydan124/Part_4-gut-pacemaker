//
// Created by dangw on 23/06/2023.
//



/* Include Files */
#include "ppval.h"
#include <math.h>


//typedef struct {
//    double breaks[2];   // Starting and ending points of interval
//    double coefs[4];    // Coefficients for polynomial
//} PolynomialPiece;

void evaluatePolynomial(const PolynomialPiece pp, const double inputPoints[], const int inputSize[2], double outputValues[], int outputSize[2]) {
    double shiftedValue;
    int index;
    int maxIndex;

    outputSize[0] = 1;
    outputSize[1] = inputSize[1];
    maxIndex = inputSize[1] - 1;

    for (index = 0; index <= maxIndex; index++) {
        shiftedValue = inputPoints[index];

        if (isnan(shiftedValue)) {
            shiftedValue = NAN;
        } else {
            shiftedValue -= pp.breaks[0]; // Shift by the start of interval
            // Evaluate polynomial
            shiftedValue = shiftedValue * (shiftedValue * (shiftedValue * pp.coefs[0] + pp.coefs[1]) + pp.coefs[2]) + pp.coefs[3];
        }

        outputValues[index] = shiftedValue;
    }
}

