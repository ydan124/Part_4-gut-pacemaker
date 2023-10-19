//
// Created by dangwal yoge on 14/05/2023.
//

#include "artifact_detect.h"
#include "stdbool.h"
#include <math.h>

/* Function Definitions */

/*
 * The function `artifact_detect` takes a window of signal and a threshold value as input.
 * It returns the location of an artifact (if present) in the signal.
 * An artifact is identified as a peak value that is greater than the provided threshold.
 * If no artifact is detected, the function returns NaN.
 */

double artifact_detect(const double signal_window[101], double threshold)
{
    double absolute_signal_window[101];
    double max_value;
    double location;
    int index;
    int iterator;

    // Calculating the absolute values of the signal window
    for (iterator = 0; iterator < 101; iterator++) {
        absolute_signal_window[iterator] = fabs(signal_window[iterator]);
    }

    // Checking if the first value is NaN
    if (!isnan(absolute_signal_window[0])) {
        index = 1;
    } else {
        bool exit_condition;
        index = 0;
        iterator = 2;
        exit_condition = false;

        // Searching for the first non-NaN value
        while ((!exit_condition) && (iterator < 102)) {
            if (!isnan(absolute_signal_window[iterator - 1])) {
                index = iterator;
                exit_condition = true;
            } else {
                iterator++;
            }
        }
    }

    // Finding the maximum value in the absolute signal window and its index
    if (index == 0) {
        max_value = absolute_signal_window[0];
        index = 1;
    } else {
        int i;
        max_value = absolute_signal_window[index - 1];
        i = index + 1;
        for (iterator = i; iterator < 102; iterator++) {
            double current_value;
            current_value = absolute_signal_window[iterator - 1];
            if (max_value < current_value) {
                max_value = current_value;
                index = iterator;
            }
        }
    }

    // Checking if the maximum value is greater than the threshold
    if (max_value > threshold) {
        location = index;
    } else {
        location = NAN; // If no artifact is detected, assign NaN to location
    }

    return location;
}
