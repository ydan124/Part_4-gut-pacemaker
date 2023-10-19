

/* Include Files */
#include "lowpass_function.h"
#include <math.h>
#include <string.h>
#include <stddef.h>
#include <stdlib.h>
#define FILTER_ORDER 15 //play around using matlab for different siganl
#define B_COEFFS_LENGTH (FILTER_ORDER+1)
#define A_COEFFS_LENGTH (FILTER_ORDER+1)



void lowpass_function(const double buffer[], int threshold,
                      int sampling_f, int size_a , double * locs) {
    // butterworth style filter coefficient calculation play //around using matlab for butter chebyl to get good lowpass for //differnt signal
//fs = sampling_f; % Replace this with your sampling frequency
//[N, Wn] = buttord(2.5/(fs/2), 3/(fs/2), 1, 40); % Again, you// //might want to adjust these parameters
//[b, a] = butter(N, Wn, 'low');
    //static const double b_coeffs[B_COEFFS_LENGTH] = {0.000973102374817448,0.00486551187408724,0.00973102374817448,0.00973102374817448,0.00486551187408724,0.000973102374817448};
    //static const double a_coeffs[A_COEFFS_LENGTH] = {1.0,-3.10106533788328,4.08692447813816,-2.80137195874133,0.990175154899140,-0.143523060418535};
    static const double b_coeffs[B_COEFFS_LENGTH]={0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000001, 0.000001, 0.000001, 0.000001, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000};
    static const double a_coeffs[A_COEFFS_LENGTH]={1.000000, -10.076933, 47.978051, -143.018851, 298.240019, -460.501841, 543.535853, -499.086806, 359.264477, -202.649923, 88.804867, -29.679514, 7.320449, -1.257610, 0.134520, -0.006752};
    double forwardFiltered[size_a+120];
    double backwardFiltered[size_a+120];
    double padded_buffer[size_a+120];
    int j, k;

    // Padding the buffer
    for (k = 0; k < size_a+120; k++) {
        padded_buffer[k] = buffer[0];
    }
    memcpy(&padded_buffer[60], &buffer[0], size_a * sizeof(double));
    for (k = 0; k < 61; k++) {
        padded_buffer[k + size_a] = buffer[size_a];
    }

    // Forward filtering
    memset(&forwardFiltered[0], 0, (size_a+120) * sizeof(double));
    for (k = size_a+119; k >= 0; k--) {
        int naxpy;
        int idx_temp;

        naxpy = (k < B_COEFFS_LENGTH) ? k : B_COEFFS_LENGTH - 1;
        for (j = 0; j <= naxpy; j++) {
            idx_temp = k - j;
            backwardFiltered[idx_temp] += forwardFiltered[k] * b_coeffs[j];
        }

        naxpy = (k < A_COEFFS_LENGTH-1) ? k : A_COEFFS_LENGTH - 2;
        double as = -backwardFiltered[k];
        for (j = 0; j <= naxpy; j++) {
            idx_temp = (k - j) - 1;
            backwardFiltered[idx_temp] += as * a_coeffs[j + 1];
        }
    }


    // Backward filtering
    for (k = size_a+119; k >= 0; k--) {
        int naxpy;
        int idx_temp;

        naxpy = (k < B_COEFFS_LENGTH) ? k : B_COEFFS_LENGTH - 1;
        for (j = 0; j <= naxpy; j++) {
            idx_temp = k - j;
            backwardFiltered[idx_temp] += forwardFiltered[k] * b_coeffs[j];
        }

        naxpy = (k < A_COEFFS_LENGTH-1) ? k : A_COEFFS_LENGTH - 2;
        double as = -backwardFiltered[k];
        for (j = 0; j <= naxpy; j++) {
            idx_temp = (k - j) - 1;
            backwardFiltered[idx_temp] += as * a_coeffs[j + 1];
        }
    }


    // Remove padding
    memcpy(&locs[0], &backwardFiltered[60], size_a * sizeof(double));
}
