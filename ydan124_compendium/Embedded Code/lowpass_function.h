

#ifndef LOWPASS_FUNCTION_H
#define LOWPASS_FUNCTION_H

/* Include Files */

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
//extern void lowpass_function(const double buffer[1001], double threshold,
//                               double sampling_f, double * locs);   //locs and buffer 1001
extern void lowpass_function(const double buffer[], int threshold,
                      int sampling_f, int size , double * locs);
#ifdef __cplusplus
}
#endif

#endif
