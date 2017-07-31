#include <xinu.h>
#include <stdio.h>
#include <stdlib.h>
#include <readerwriter.h>

void writers(int writer_number, int cycle_number, int dt)
{
	int i = 0;
	int j = 0;

	while(i < cycle_number)
	{
		wait(turnstile);
		wait(roomEmpty);
		
		rand_delay(dt);

		while (j < writer_number)
		{
			printf("Writer writer number %d cycle %d\n", j, i);
			j++;
			// wid++;
		}

		signal(turnstile);
		signal(roomEmpty);

		j = 0;
		i++;
	}
}