/* xsh_producer_consumer.c - xsh_producer_consumer */

#include <xinu.h>
#include <stdio.h>
#include <stdlib.h>
#include <prodcons.h>

sid32 mutex;
sid32 items;
sid32 spaces;

int buffer[];

shellcmd xsh_producer_consumer(int nargs, int *args[])
{
	int delay = 0;
	int bytes = 0;
	int buffersize = 0;
	int buffer_index = 0;

	buffersize = atoi(args[1]);
	bytes = atoi(args[2]);
	delay = atoi(args[3]);

	buffer[buffersize];

	mutex = semcreate(1);
	items = semcreate(0);
	spaces = semcreate(buffersize);

	resume( create(producer, 1024, 20, "prod", 4, delay, buffer_index, buffersize, bytes));
	resume( create(consumer, 1024, 20, "cons", 4, delay, buffer_index, buffersize, bytes));

	return 0;
}