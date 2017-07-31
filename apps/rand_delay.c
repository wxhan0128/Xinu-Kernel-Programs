#include <xinu.h>
#include <stdio.h>
#include <stdlib.h>

void rand_delay (int uS_max) {
	int r = rand() % uS_max;

	sleepms(r / 1000);
}