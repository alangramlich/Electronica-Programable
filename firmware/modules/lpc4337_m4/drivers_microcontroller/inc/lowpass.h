/*
 * Filter Coefficients (C Source) generated by the Filter Design and Analysis Tool
 * Generated by MATLAB(R) 9.1 and the Signal Processing Toolbox 7.3.
 * Generated on: 14-Oct-2021 09:59:09
 */

/*
 * Discrete-Time IIR Filter (real)
 * -------------------------------
 * Filter Structure    : Direct-Form II
 * Numerator Length    : 5
 * Denominator Length  : 5
 * Stable              : Yes
 * Linear Phase        : No
 */

/* General type conversion for MATLAB generated C-code  */
#include "tmwtypes.h"
/* 
 * Expected path to tmwtypes.h 
 * C:\Program Files\MATLAB\R2016b\extern\include\tmwtypes.h 
 */
//const int NL = 5;
#define NL_LP 5
const real64_T NUM_LP[5] = {
		0.8484752955244,    3.393901182097,    5.090851773146,    3.393901182097,
		     0.8484752955244
};
//const int DL = 5;
#define DL_LP 5
const real64_T DEN_LP[5] = {
		1,    3.671729089162,    5.067998386734,    3.115966925202,
		     0.7199103272919
};
