/* xsh_babybird.c - xsh_babybird */

#include <xinu.h>
#include <babybird.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


shellcmd xsh_babybird(int nargs, char *args[]) {

	if (nargs == 2 && (strncmp(args[1], "--help", 7) == 0 || strncmp(args[1], "-h", 3) == 0)) {
		printf("Usage: %s <Set three arguments here. Details are described below. They can be in any order.>\n\n", args[0]);
		printf("Description:\n");
		printf("\tThis program simulates the babybird problem.\n");
		printf("Options:\n");
		printf("\t--help or -h\tdisplay this help and exit\n");
		printf("Three necessary arguments (they can be put in any order):");
		printf("\t--babies <an non-negative integer> or -b <an integer>\tset the number of baby birds\n");
		printf("\t--fetch <an non-negative integer> or -f <non-negative integer>\tset the number of worms the mother fetches\n");
		printf("\t--eat <an non-negative integer> or -e <an non-negative integer>\tset the number of worms each baby needs to eat\n");
		return 0;
	}

	/* check argument amount */

	if (nargs > 7) {
		fprintf(stderr, "%s: too many arguments\n", args[0]);
		fprintf(stderr, "Try '%s --help' for more information\n",
			args[0]);

		return 1;
	}
	
	if (nargs < 7) {
		fprintf(stderr, "%s: too few arguments\n", args[0]);
		fprintf(stderr, "Try '%s --help' for more information\n",
			args[0]);

		return 1;
	}

	unsigned int num_of_babies = -1, num_of_worms_to_eat = -1, num_of_worms_mother_fetches = -1;

	if (strncmp(args[1], "--babies", 9) == 0 || strncmp(args[1], "-b", 3) == 0)
		num_of_babies = atoi(args[2]);

	else if (strncmp(args[1], "--fetch", 8) == 0 || strncmp(args[1], "-f", 3) == 0)
		num_of_worms_mother_fetches = atoi(args[2]);

	else if (strncmp(args[1], "--eat", 6) == 0 || strncmp(args[1], "-e", 3) == 0)
		num_of_worms_to_eat = atoi(args[2]);

	else
	{
		fprintf(stderr, "Error occurs.\n");
		fprintf(stderr, "Try '%s --help' for more information\n",
			args[0]);

		return 1;
	}
	
	if (strncmp(args[3], "--babies", 9) == 0 || strncmp(args[3], "-b", 3) == 0)
		num_of_babies = atoi(args[4]);

	else if (strncmp(args[3], "--fetch", 8) == 0 || strncmp(args[3], "-f", 3) == 0)
		num_of_worms_mother_fetches = atoi(args[4]);

	else if (strncmp(args[3], "--eat", 6) == 0 || strncmp(args[3], "-e", 3) == 0)
		num_of_worms_to_eat = atoi(args[4]);

	else
	{
		fprintf(stderr, "Error occurs.\n");
		fprintf(stderr, "Try '%s --help' for more information\n",
			args[0]);

		return 1;
	}

	if (strncmp(args[5], "--babies", 9) == 0 || strncmp(args[5], "-b", 3) == 0)
		num_of_babies = atoi(args[6]);

	else if (strncmp(args[5], "--fetch", 8) == 0 || strncmp(args[5], "-f", 3) == 0)
		num_of_worms_mother_fetches = atoi(args[6]);

	else if (strncmp(args[5], "--eat", 6) == 0 || strncmp(args[5], "-e", 3) == 0)
		num_of_worms_to_eat = atoi(args[6]);

	else
	{
		fprintf(stderr, "Error occurs.\n");
		fprintf(stderr, "Try '%s --help' for more information\n",
			args[0]);

		return 1;
	}
	
	if (num_of_babies < 0)
	{
		fprintf(stderr, "The number of baby birds is not properly defined.\n");
		fprintf(stderr, "Try '%s --help' for more information\n",
			args[0]);

		return 1;
	}
	
	if (num_of_worms_mother_fetches < 0)
	{
		fprintf(stderr, "The number of worms the mother fetches is not properly defined.\n");
		fprintf(stderr, "Try '%s --help' for more information\n",
			args[0]);

		return 1;
	}
	
	if (num_of_worms_to_eat < 0)
	{
		fprintf(stderr, "The number of worms each baby needs to eat is not properly defined.\n");
		fprintf(stderr, "Try '%s --help' for more information\n",
			args[0]);

		return 1;
	}

	int i, dish_worms = num_of_worms_mother_fetches;
	int total_birds;
	total_birds = num_of_babies;

	struct mutex_t room_lock, someone_eating;
	struct cond_v_t plate_full, plate_empty, my_turn;

	mutex_create(&room_lock);
	mutex_create(&someone_eating);
	cond_init(&plate_full);
	cond_init(&plate_empty);
	cond_init(&my_turn);

	ready( create(parentbird_fetch, 1024, 20, "parent", 7, num_of_worms_mother_fetches, currpid, &total_birds, &room_lock, &plate_empty, &plate_full, &dish_worms));

	for (i = 0; i < num_of_babies; i++)
	{
		ready( create(babybird_eat, 1024, 20, "baby", 9, i, num_of_worms_to_eat, &total_birds, &room_lock, &someone_eating, &plate_empty, &plate_full, &dish_worms, &my_turn));
	}

	suspend(currpid);
	printf("\nThere are %d worms left in the dish.\n", dish_worms);
	return 0;
}
