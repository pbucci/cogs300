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

int maxMin() {
	int max = 0;
	int maxloc;
	int min = 0;
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
	return max;
}

int scanAndRecord() {
	int i;
	for (i = 0; i < ARRAY_SIZE; i++) {
		turnLeft(10);
		Wait(1000);
		arr[i] = SensorUS(ULTRA_SENSOR);
		Wait(1000);
	}
}

int fuzzy(int num, int target, int range) {
	return (num > target - range || num < target + range) ? 1 : 0;
}