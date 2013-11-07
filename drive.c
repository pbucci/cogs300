//
//  drive.c
//  l3
//
//  Created by bucci on 2013-11-07.
//  Copyright (c) 2013 bucci. All rights reserved.
//

#include "drive.h"
// Driving functions for convenience
void driveForward(int waitTime) {
	OnFwd(MOTOR_LEFT, MLEFT_POWER);
	OnFwd(MOTOR_RIGHT, MRIGHT_POWER);
	Wait(waitTime);
}
void driveBackward(int waitTime) {
	OnFwd(MOTOR_LEFT, MLEFT_POWER);
	OnFwd(MOTOR_RIGHT, MRIGHT_POWER);
	Wait(waitTime);
}
void turnLeft(int waitTime) {
	OnFwd(MOTOR_RIGHT, MRIGHT_POWER);
	OnRev(MOTOR_LEFT, MLEFT_POWER);
	Wait(waitTime);
}
void turnRight(int waitTime) {
	OnFwd(MOTOR_LEFT, MLEFT_POWER);
	OnRev(MOTOR_RIGHT, MRIGHT_POWER);
	Wait(waitTime);
}

// Turns wide
void wideTurnForward(int waitTime, float lRatio, float rRatio) {
	int motorLeft  = MLEFT_POWER*lRatio;
	int motorRight = MRIGHT_POWER*rRatio;
	OnFwd(MOTOR_LEFT, motorLeft);
	OnFwd(MOTOR_RIGHT, motorRight);
	Wait(waitTime);
}
void wideTurnBackward(int waitTime, float lRatio, float rRatio) {
	int motorLeft  = MLEFT_POWER*lRatio;
	int motorRight = MRIGHT_POWER*rRatio;
	OnRev(MOTOR_LEFT, motorLeft);
	OnRev(MOTOR_RIGHT, motorRight);
	Wait(waitTime);
}
