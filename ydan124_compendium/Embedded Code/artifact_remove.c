//
// Created by dangwal yoge on 23/05/2023.
//

#include "artifact_remove.h"
#include <stdio.h>
#include <math.h>
#include <stddef.h>
#include <string.h>



void artifact_remove(const double window[101], double x1, double x2,
                     double * output)
{
    double replace_data[101];
    double xx_data[101];
    double divdifij;
    double dzdxdx;
    double dzzdx;
    double pp1_coefs_idx_0;
    double y_idx_0;
    double y_idx_0_tmp;
    int dxj;
    int i;
    int i1;
    int loop_ub;
    int xx_size_idx_1;
    /*  compute start and end slopes */
    /*  calculate spline with sample rate at 32 Hz */
    y_idx_0_tmp = window[(int)x1 - 1];
    y_idx_0 = y_idx_0_tmp - window[(int)x1 - 2];
    dxj = (signed char)x2 - (signed char)x1;
    dzdxdx = window[(int)x2 - 1];
    divdifij = (dzdxdx - y_idx_0_tmp) / (double)dxj;
    dzzdx = (divdifij - y_idx_0) / (double)dxj;
    dzdxdx = ((dzdxdx - window[(int)x2 - 2]) - divdifij) / (double)dxj;
    pp1_coefs_idx_0 = (dzdxdx - dzzdx) / (double)dxj;
    divdifij = 2.0 * dzzdx - dzdxdx;
    /*  cubic spline */
    /* xx = x1:1/32:x2; */
    if (x2 < x1) {
        xx_size_idx_1 = 0;
    } else {
        loop_ub = (int)(x2 - x1);
        xx_size_idx_1 = loop_ub + 1;
        for (i = 0; i <= loop_ub; i++) {
            xx_data[i] = x1 + (double)i;
        }
    }
    for (dxj = 0; dxj < xx_size_idx_1; dxj++) {
        dzdxdx = xx_data[dxj] - (double)(signed char)x1;
        replace_data[dxj] =
                dzdxdx * (dzdxdx * (dzdxdx * pp1_coefs_idx_0 + divdifij) + y_idx_0) +
                y_idx_0_tmp;
    }
    /*  output result */
    memset(&output[0], 0, 101U * sizeof(double));
    if (x1 - 1.0 < 1.0) {
        loop_ub = 1;
    } else {
        loop_ub = (int)x1;
    }
    if (loop_ub - 2 >= 0) {
        memcpy(&output[0], &window[0],
               (unsigned int)(loop_ub - 1) * sizeof(double));
    }
    if (x1 > x2) {
        i = 1;
    } else {
        i = (int)x1;
    }
    for (i1 = 0; i1 < xx_size_idx_1; i1++) {
        output[(i + i1) - 1] = replace_data[i1];
    }
    if (x2 + 1.0 > 101.0) {
        i = 0;
        i1 = -1;
        dxj = 0;
    } else {
        i = (int)x2;
        i1 = 100;
        dxj = (int)x2;
    }
    loop_ub = i1 - i;
    for (i1 = 0; i1 <= loop_ub; i1++) {
        output[dxj + i1] = window[i + i1];
    }
}



