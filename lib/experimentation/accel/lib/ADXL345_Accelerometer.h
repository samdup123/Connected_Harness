/*
 * ADXL345_Accelerometer Header File
 *
 * Description Driver for the ADXL345 accelerometer
 *
 * Written by JamApps
 */

#ifndef ADXL345_Accelerometer
#define ADXL345_Accelerometer

#include "ADXL345.h"

void ResetMembers(void);
void UpdateMemebers(bool activity, bool freeFall);
void init_ADXL345_Accelerometer(void);
bool CheckStatus_ADXL345_Accelerometer(void)
void SetTriggers_ADXL345_Accelerometer(void);
#endif
