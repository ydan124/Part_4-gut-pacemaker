//
// Created by dangwal yoge on 13/04/2023.
//

#include <string.h>
#include "moving_average_1s_window.h"


/* Function Definitions */
/*
 * MOVING_AVERAGE_1S_WINDOW applies a moving average filter to the input signal, using a window of width 1 second.
  input_signal, the input signal as a 1xN row vector ,sample_rate, the sample rate of the input signal in Hz
output_signal, the filtered signal as a 1xN row vector
 */
void moving_average_1s_window(const double input_signal[1050],int N, double sample_rate, double *output)   //double output[N] and Nis length of input signal 1050 in our case
{
    int time = 1; // second
    int M = sample_rate * time; // size of window as number of points

    // Check if M is larger than or equal to N, in which case return
    if (M >= N) {
        for (int i = 0; i < N; i++) {
            output[i] = 0;  // or some other default value
        }
        return;
    }
    // Calculate moving average
//    for (int i = 0; i <=(1050 - M); i++) {
//        double sum = 0.0;
//        for (int j = 0; j < M; j++) {
//                sum = sum + input_signal[i + j];
//        }
//         output[i]= sum / M;
//       // printf("value =%f\r\n",output);    //debugger print
//    }
    for (int i = 0; i < N - M; i++) {
        double sum = 0;
        for (int j = 0; j < M; j++) {
            sum += input_signal[i + j+1];
        }
        output[i] = sum / M;
    }

    // Fill the rest of the output array with zeros
    for (int i = N - M; i < N; i++) {
        output[i] = 0;  // or some other default value
    }
}


