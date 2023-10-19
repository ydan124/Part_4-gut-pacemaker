//
// Created by dangwal yoge on 23/03/2023.
//

#ifndef UNTITLED1_ARTIFACT_REMOVE_H
#define UNTITLED1_ARTIFACT_REMOVE_H
//void artifact_remove(const double inputSignal[101], double artifactStartIdx,
//                     double artifactEndIdx, double * outputSignal); // artifact_removed[101]
void artifact_remove(const double window[101], double x1, double x2,
                     double * output);
#endif //UNTITLED1_ARTIFACT_REMOVE_H
