#include <xinu.h>
#include <stdio.h>
#include <stdlib.h>
#include <readerwriter.h>

void lock(sid32 semaphore)
{
	wait(mutex);
	counter++;

	if (counter == 1)
		wait(semaphore);

	signal(mutex);
}

void unlock(sid32 semaphore)
{
	wait(mutex);
	counter--;

	if (counter == 0)
		signal(semaphore);

	signal(mutex);
}