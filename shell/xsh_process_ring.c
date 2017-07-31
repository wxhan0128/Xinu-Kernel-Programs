/* xsh_process_ring.c - xsh_process_ring */

#include <xinu.h>
#include <string.h>
#include <stdio.h>
#include <process_ring.h>

#define DEFAULT_NUM_PROCESSES 4
#define DEFAULT_NUM_ROUNDS 5

int inbox;
int NUM_ROUNDS;
int NUM_PROCESSES;

shellcmd xsh_process_ring(int nargs, int *args[])
{
	int id = 0;

	int findp = 0;
	int findr = 0;
	int findv = 0;
	int i = 0;

	if (strncmp(args[1], "--help", 7) == 0)
	{
		printf("Usage: %s\n\n", args[0]);
		printf("Description:\n");
		printf("\tDisplays the process rounds\n");
		printf("\t--processes\tset the number of processes\n");
		printf("\t--rounds\tset the number of rounds\n");
		printf("\t--version\tchoose one version to run\n");
		printf("\t--help\tuseful help text\n");

		return 0;
	}

	for (i = 0; i < nargs; i++)
	{
		if ((strcmp(args[i], "-p") == 0) || (strcmp(args[i], "--processes") == 0))
		{
			NUM_PROCESSES = atoi(args[i + 1]);
			findp = 1;
			continue;
		}
		else if (findp == 0 && i == nargs - 1)
		{	
			NUM_PROCESSES = DEFAULT_NUM_PROCESSES;
		}
		if ((strcmp(args[i], "-r") == 0) || (strcmp(args[i], "--round") == 0))
		{
			NUM_ROUNDS = atoi(args[i + 1]);
			findr = 1;
			continue;
		}
		else if (findr == 0 && i == nargs - 1)
		{
			NUM_ROUNDS = DEFAULT_NUM_ROUNDS;
		}
		else if ((strcmp(args[i], "-v") == 0) || (strcmp(args[i], "--version") == 0))
		{
			if (strcmp(args[i + 1], "work") == 0)
			{
				findv = 1;
			}
			else if (strcmp(args[i + 1], "hang") == 0)
			{
				findv = 2;
			}
			else if (strcmp(args[i + 1], "loop") == 0)
			{
				findv = 3;
			}
			else if (strcmp(args[i + 1], "chaos") == 0)
			{
				findv = 4;
			}
			else
			{
				fprintf(stderr, "%s: arguments invalid\n", args[0]);
				return 1;
			}
		}
		else if (findv == 0 && i == nargs - 1)
		{
			
		}
	}

	if (findv == 1 || findv == 0)
	{
		inbox = NUM_PROCESSES * NUM_ROUNDS;
		printf("Number of Processes: %d\n", NUM_PROCESSES);
		printf("Number of Rounds: %d\n", NUM_ROUNDS);

		for(id = 0; id < NUM_PROCESSES; id++)
		{
			resume( create(w_function, 1024, 20, "correct_order", 1, id));
		}

		return 0;
	}
	else if (findv == 2)
	{
		inbox = NUM_PROCESSES * NUM_ROUNDS;
		printf("Number of Processes: %d\n", NUM_PROCESSES);
		printf("Number of Rounds: %d\n", NUM_ROUNDS);

		for(id = 0; id < NUM_PROCESSES; id++)
		{
			resume( create(h_function, 1024, 20, "hang_prog", 1, id));
		}

		return 0;
	}
	else if (findv == 3)
	{
		inbox = NUM_PROCESSES * NUM_ROUNDS;
		printf("Number of Processes: %d\n", NUM_PROCESSES);
		printf("Number of Rounds: %d\n", NUM_ROUNDS);

		for(id = 0; id < NUM_PROCESSES; id++)
		{
			resume( create(inf_function, 1024, 20, "infinit_loop", 1, id));
		}

		return 0;
	}
	else if (findv == 4)
	{
		inbox = NUM_PROCESSES * NUM_ROUNDS;
		printf("Number of Processes: %d\n", NUM_PROCESSES);
		printf("Number of Rounds: %d\n", NUM_ROUNDS);

		for(id = 0; id < NUM_PROCESSES; id++)
		{
			resume( create(c_function, 1024, 20, "chaos_order", 1, id));
		}

		return 0;
	}

	inbox = DEFAULT_NUM_PROCESSES * DEFAULT_NUM_ROUNDS;
	printf("Number of Processes: %d\n", DEFAULT_NUM_PROCESSES);
	printf("Number of Rounds: %d\n", DEFAULT_NUM_ROUNDS);

	for(id = 0; id < DEFAULT_NUM_PROCESSES; id++)
	{
		resume( create(w_function, 1024, 20, "correct_order", 1, id));
	}

	return 0;
}