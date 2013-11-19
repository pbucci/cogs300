//
//  arrayTest.c
//  l3
//
//  Created by bucci on 2013-11-18.
//  Copyright (c) 2013 bucci. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int arr[99] = {};
void populate() {
	int i;
	for (i = 0; i < 34; i++) {
		arr[i] = 99 - i;
		arr[66-i] = 99 - i;
		arr[66+i/2] = 99 - i/2;
		arr[99-i/2] = 99 - i/2;
	}
}
void print() {
	int i;
	for (i = 0; i < 99; i++) {
		printf("%d\n",arr[i]);
	}
}

void noisy() {
	int i;
	srand(time(NULL));
	for (i = 0; i < 99; i++) {
		arr[i] += rand() % 10;
	}
}


void slopes() {
	int i;
	for (i = 1; i < 99; i++) {
		if (arr[i] < arr[i - 1]) {
			arr[i - 1] = -1;
		}
		else if(arr[i] == arr[i - 1]) {
			arr[i - 1] = 0;
		}
		else {
			arr[i - 1] = 1;
		}
	}
}
void printgraph() {
	int i;
	int j;
	for (i = 0; i < 99; i++) {
		printf("%d\t|%d\t", i,arr[i]);
		for (j = 0; j < arr[i]; j++) {
			printf("|");
		}
		printf("\n");

	}
}
void smooth() {
	int i;
	for (i = 0; i < 96; i++) {
		arr[i+1] = (arr[i] + arr[i+2])/2;
	}
}

void findMins() {
	int i = 1;
	int j;
	int a[99] = {};
	int count = 0;
	int currentMin = arr[0];
	while (i < 99) {
		int min = nextMin(i);
		a[count] = min;
		count++;
		i = nextMax(min);
	}
	printf("Mins : \n");
	for (j = 0; j < count; j++) {
		printf("%d\n",a[j]);
	}
}
int nextMin(int i) {
	while(arr[i-1] >= arr[i] && i < 99) {
		i++;
	}
	return i;
}
int nextMax(int i) {
	while(arr[i-1] <= arr[i] && i < 99) {
		i++;
	}
	return i;
}


void mean() {
	int i;
	int sum = 0;
	for (i = 0; i < 99; i++) {
		sum = sum + arr[i];
	}
	sum = sum/99;
	printf("The mean is : %d\n",sum);
}

int main() {
	populate();
	printf("nums : \n");
	mean();
	printgraph();

	noisy();
	printf("noisy : \n");
	mean();
	printgraph();

	smooth();
	smooth();

	printf("smooth : \n");
	mean();
	printgraph();
	findMins();

//	smooth();
//	printf("smooth2 : \n");
//	mean();
//	printgraph();
//
//	slopes();
//	printf("slopes : \n");
//	print();

}