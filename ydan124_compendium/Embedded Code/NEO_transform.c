//
// Created by dangwal yoge  on 10/08/2023.
//

#include "NEO_transform.h"
/* Function Definitions
 * NEO (Non-linear Energy Operator) transformation, as used by Bull et al.
 *  INPUT: Downscaled and filtered time series signal.
 *  OUTPUT: Signal with NEO transformation applied.
 */
void NEO_transform(const double input[1051] , double * output )//double* output[1050]
{
    int i;
    for (i = 0; i < 1050; i++) {
        output[i] = 1.0;
    }
    for (i = 0; i <1050; i++) {
        double output_tmp;
        output_tmp = input[i + 1];
        output[i + 1] = output_tmp * output_tmp - input[i] * input[i + 2];
         //printf("value =%f\r\n",output[i]);    //debugger print
    }
}
