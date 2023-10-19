//
// Created by dangw on 15/09/2023.
//

#ifndef UNTITLED1_HIGHPASS_FUNCTION_H
#define UNTITLED1_HIGHPASS_FUNCTION_H

/* Include Files */

#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void highpass_function(const double input_signal[1001],  double * output_signal , double * artifact_removed);

#ifdef __cplusplus
}
#endif
#endif //UNTITLED1_HIGHPASS_FUNCTION_H

