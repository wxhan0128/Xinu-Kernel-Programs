#include <xinu.h>
#include <stdio.h>
#include <string.h>
#include <process_ring.h>

void w_function(int id)
{
	int i = 0;
	int m = 0;

	while(i < NUM_ROUNDS)
	{
		m = inbox % NUM_PROCESSES;
		if (m == 0)
		{
			m = m - 0;
		}
		else
		{
			m = NUM_PROCESSES - m;
		}
		if (id == m)
		{
			printf("Ring Element %d : Round %d : Value : %d \n", id, i, inbox);

			inbox = inbox - 1;
			i = i + 1;
		}
		else
		{
			resched();
		}
	}
}

void h_function(int id)
{
	wait(currpid);
}

void c_function(int id)
{
	int i = 0;

	for (;i < NUM_ROUNDS; i++)
	{
		printf("Ring Element %d : Round %d : Value : %d \n", id, i, inbox);

		inbox = inbox - 1;

		resched();
	}
}

void inf_function(int id)
{
	int i = 0;

	while (TRUE)
	{
		printf("Ring Element %d : Round %d : Value : %d \n", id, i, inbox);

		inbox = inbox - 1;
		i = i + 1;
	}
}