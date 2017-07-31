#include <xinu.h>
#include <stdio.h>
#include <stdlib.h>
#include <diningphilosophers.h>

int left(int i)
{
	return i;
}

int right(int i)
{
	return (i + 1) % phil_num;
}

void dining_philosophers(int pid, sid32 *fork, sid32 foot_man, pid32 curid)
{
	int i;
	char msg_buffer[200];

	for(i = cycle_num; i > 0; --i)
	{
		rand_delay(delay);

		sprintf(msg_buffer, "Philosopher %d thinking cycle %d\n", pid, i);
		write(stdout, msg_buffer, strlen(msg_buffer) + 1);

		wait(foot_man);
		wait(fork[right(pid)]);
		wait(fork[left(pid)]);
	
		rand_delay(delay);
		
		sprintf(msg_buffer, "Philosopher %d eating cycle %d\n", pid, i);
		write(stdout, msg_buffer, strlen(msg_buffer) + 1);

		signal(fork[right(pid)]);
		signal(fork[left(pid)]);
		signal(foot_man);
	}

	np = np - 1;

	if (np == 0)
		ready(curid);
}