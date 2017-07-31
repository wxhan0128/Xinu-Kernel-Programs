#include <xinu.h>
#include <stdio.h>
#include <stdlib.h>
#include <prodcons.h>

void producer(int dt, int bsize, int bindex, int bys) {
	int count = 0;

	while(bys > 0){
		if (bys < 0)
			break;

		rand_delay(dt);

		if (bindex > (bsize - 1))
			bindex = 0;

		if (count > 255)
			count = 0;

		wait(spaces);
		wait(mutex);

		buffer[bindex] = count;
		printf("Producer: %d\n", count);
		count++;

		signal(mutex);
		signal(items);

		bindex++;
		bys--;
	}

	exit(0);
}