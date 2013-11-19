//
//  drive.h
//  l3
//
//  Created by bucci on 2013-11-07.
//  Copyright (c) 2013 bucci. All rights reserved.
//

#ifndef l3_drive_h
#define l3_drive_h

// IO definitions
#define LIGHT_SENSOR		IN_4	// light sensor
#define TOUCH_SENSOR		IN_2	// touch sensor
#define ULTRA_SENSOR		S1	// Ultrasonic
#define MLEFT_POWER			30		// Number from 0-100
#define MRIGHT_POWER		30		// Number from 0-100
#define MOTOR_LEFT			OUT_C	//
#define MOTOR_RIGHT			OUT_A	//

// Threshold definitions
#define DISTANCE_THRESHOLD	25		//
#define WHITE_THRESHOLD		40		// Number from 0-100
#define BLACK_THRESHOLD		25		// Number from 0-100

// Function declarations

void driveForward(int waitTime);
void driveBackward(int waitTime);
void turnLeft(int waitTime);
void turnRight(int waitTime);
void wideTurnForward(int waitTime, float lRatio, float rRatio);
void wideTurnBackward(int waitTime, float lRatio, float rRatio);

#endif
