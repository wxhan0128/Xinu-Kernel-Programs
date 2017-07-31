/* xsh_dining_philosophers.c - xsh_dining_philosophers */

#include <xinu.h>
#include <stdio.h>
#include <stdlib.h>
#include <diningphilosophers.h>

int phil_num;
int cycle_num;
int delay;

int np;

shellcmd xsh_dining_philosophers(int nargs, char *args[])
{
	phil_num = atoi(args[1]);
	cycle_num = atoi(args[2]);	
	delay = atoi(args[3]);

	np = phil_num;
	sid32 fork[phil_num];

	int i;
	for(i = 0; i < phil_num; i++)
	{
		fork[i] = semcreate(1);
	}

	int foot = phil_num - 1;
	sid32 fm = semcreate(foot);
	
	for(i = 0; i < phil_num; i++)
	{
		resume( create(dining_philosophers, 1024, 20, "dining_philosophers", 4 , i, fork, fm, currpid));
	}

	suspend(currpid);

	return 0;
}