#include <xinu.h>
#include <stdio.h>
#include <stdlib.h>
#include <prodcons.h>

void consumer(int dt, int bsize, int bindex, int bys) {
	int event = 0;

	while(bys > 0)
	{
		if (bys < 0)
			break;

		wait(items);
		wait(mutex);

		if (bindex > (bsize - 1))
			bindex = 0;

		event = buffer[bindex];

		signal(mutex);
		signal(spaces);

		rand_delay(dt);
		printf("Consumer: %d\n", event);

		bindex++;
		bys--;
	}

	exit(0);
}