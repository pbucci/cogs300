//
//  ultra.c
//  l3
//
//  Created by bucci on 2013-11-18.
//  Copyright (c) 2013 bucci. All rights reserved.
//
#include "ultra.h"
#include "drive.h"
//#include <stdio.h>

int arr[ARRAY_SIZE];
int mins[2];
void arrayInit() {
	int i;
	for (i = 0; i < ARRAY_SIZE; i++) {
		arr[i] = 255;
	}
}

// Sets the max and min of the array
int maxMin() {
	int max = 0;
	int maxloc;
	int min = 255;
	int minloc;
	int i;
	for(i = 0; i < ARRAY_SIZE; i++) {
		if (arr[i] >= max) {
			max = arr[i];
			maxloc = i;
		}
		if (arr[i] <= min) {
			min = arr[i];
			minloc = i;
		}
	}
	NumOut(0,LCD_LINE1,min);
	Wait(5000);
	return min;
}

void findmins() {
	int i;
	int mincount = 0;
	int prevSlope;
	for (i = 1; i < ARRAY_SIZE; i++) {
		int first = arr[i];
		int second = arr[i-1];
		int slope = first - second;
		if (slope < 0) {
			prevSlope = -1;
		}
		if (slope > 0) {
			prevSlope = 1;
		}
		if (slope != prevSlope && mincount < 2) {
			mins[mincount] = i;
			mincount++;
		}
	}
	NumOut(0,LCD_LINE1,arr[mins[0]]);
	NumOut(0,LCD_LINE2,arr[mins[1]]);
	Wait(5000);
}

// Scans through the room, recording ultrasonic values
int scanAndRecord() {
	int i;
	for (i = 0; i < ARRAY_SIZE; i++) {
		turnLeft(50);
		Wait(50);
		arr[i] = SensorUS(ULTRA_SENSOR);
	}
}

// Returns 1 (true) if number is within range of target
bool fuzzy(int num, int target, int range) {
	return (num > (target - range) && num < target + range) ? true : false;
}