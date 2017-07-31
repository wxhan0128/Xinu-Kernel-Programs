/* xsh_readers_writers.c - xsh_readers_writers */

#include <xinu.h>
#include <stdio.h>
#include <stdlib.h>
#include <readerwriter.h>

int counter;
sid32 mutex;

sid32 readSwitch;
sid32 roomEmpty;
sid32 turnstile;

shellcmd xsh_readers_writers(int nargs, int *args[])
{
	int w_num, r_num, w_cycles, r_cycles, delay;

	w_num = atoi(args[1]);
	r_num = atoi(args[2]);
	w_cycles = atoi(args[3]);
	r_cycles = atoi(args[4]);
	delay = atoi(args[5]);

	
	roomEmpty = semcreate(1);
	turnstile = semcreate(1);
	mutex = semcreate(1);

	counter = 0;

	resume( create(writers, 1024, 20, "writer", 3, w_num, w_cycles, delay));
	resume( create(readers, 1024, 20, "reader", 3, r_num, r_cycles, delay));

	return 0;
}