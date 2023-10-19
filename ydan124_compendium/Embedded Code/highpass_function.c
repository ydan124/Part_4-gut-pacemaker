//
// Created by dangw on 15/09/2023.
//

#include "highpass_function.h"

/* Include Files */
#include "highpass_function.h"
#include <string.h>

void highpass_function(const double  input_signal[1001], double * output_signal , double * artifact_removed) {  //output_signal and input_signal 1001 and  1001
    static const double filter_cofficients[51] = {
            -0.0078873991649782114, -0.0088374894538831624, -0.009825399571889399,
            -0.010845874310498974, -0.011893143176389873, -0.012960967715976924,
            -0.014042695472615987, -0.015131320003959045, -0.016219546297298826,
            -0.017299860839371135, -0.018364605525267575, -0.019406054529973144,
            -0.020416493216557325, -0.021388298118020163, -0.022314017005855193,
            -0.023186448047976, -0.02399871706200225, -0.024744351887050552,
            -0.025417352927956868, -0.026012258969899789, -0.026524207418127457,
            -0.0269489881861568, -0.027283090535472156, -0.027523742259296751,
            -0.027668940701191743, 0.97228252479533084, -0.027668940701191743,
            -0.027523742259296751, -0.027283090535472149, -0.0269489881861568,
            -0.026524207418127457, -0.026012258969899789, -0.025417352927956868,
            -0.024744351887050538, -0.023998717062002246, -0.023186448047976004,
            -0.022314017005855193, -0.021388298118020163, -0.020416493216557325,
            -0.019406054529973144, -0.018364605525267572, -0.017299860839371135,
            -0.016219546297298826, -0.015131320003959045, -0.014042695472615987,
            -0.012960967715976924, -0.011893143176389873, -0.010845874310498976,
            -0.0098253995718894, -0.0088374894538831624, -0.0078873991649782114};
    double highpass_signal[1151];
    double padded_lowpass[1101];
    /*  ------------------------- High Pass Filter ---------------------------- %
     */
    /* Load highpass kernel */
    /*  Create new variables in the returned structure from those fields. */
    /* highpassData = importfile('fir_51.mat');  % Use importfile function to load
     * data */
    /*  Extract the field from the structure */
    /*  Filter info: w = 0.32Hz, windowed sinc FIR */
    for (int k = 0; k < 1101; k++) {
        padded_lowpass[k] = input_signal[0];
    }
    memcpy(&padded_lowpass[50], &input_signal[0], 1001U * sizeof(double));
    for (int k = 0; k < 51; k++) {
        padded_lowpass[k + 1050] = input_signal[1000];
    }
    /*  padded signal */
    memset(&highpass_signal[0], 0, 1151U * sizeof(double));
    for (int k = 0; k < 51; k++) {
        for (int b_k = 0; b_k < 1101; b_k++) {
            int highpass_signal_tmp;
            highpass_signal_tmp = k + b_k;
            highpass_signal[highpass_signal_tmp] +=filter_cofficients[k] * padded_lowpass[b_k];
        }
    }
    /*  filtering */
    memcpy(&output_signal[0], &highpass_signal[50], 1051U * sizeof(double)); // remove padding
    memcpy(& artifact_removed[0], &highpass_signal[50], 1051U * sizeof(double)); // remove padding
}