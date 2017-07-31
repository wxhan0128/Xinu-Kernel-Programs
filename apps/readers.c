#include <xinu.h>
#include <stdio.h>
#include <stdlib.h>
#include <readerwriter.h>

void readers(int reader_number, int cycle_number, int dt)
{
	int i = 0;
	int j = 0;

	while(i < cycle_number)
	{
		wait(turnstile);
		signal(turnstile);
		lock(roomEmpty);

		rand_delay(dt);

		while (j < reader_number)
		{
			printf("Reader reader number %d cycle %d\n", j, i);
			j++;
		}

		j = 0;
		i++;

		unlock(roomEmpty);
	}
}