#include <babybird.h>

void babybird_eat(int babyID, int num_of_worms_to_eat, int* total_birds,
			struct	mutex_t *room_lock, struct mutex_t *someone_eating, struct cond_v_t *plate_empty, struct cond_v_t *plate_full,
			int *dish, struct cond_v_t *my_turn)
{
	int i = 0;
	char message[200];

	while (i < num_of_worms_to_eat)
	{
		mutex_lock(room_lock);

		while(*dish == 0){
			cond_signal(plate_empty);
			cond_wait(plate_full, room_lock);
		}

		*dish = *dish - 1;
		i = i + 1;

		sprintf(message, "Baby bird %d ate a worm! (%d total)\n", babyID, i);
		write(stdout, message, strlen(message) + 1);

		cond_signal(my_turn);

		if (*total_birds != 1 && i < num_of_worms_to_eat) 
			cond_wait(my_turn, room_lock);

		mutex_unlock(room_lock);
	}

	*total_birds = *total_birds - 1;

	if (*total_birds == 0 || *dish == 0)
		cond_signal(plate_empty);
}

void parentbird_fetch(int num_of_worms_mother_fetches, pid32 main_pid, int* total_birds,
			struct mutex_t *room_lock, struct cond_v_t *plate_empty, struct cond_v_t *plate_full, int *dish)
{
	char message[200];

	sprintf(message, "Parent bird filled the dish with %d worms!\n", num_of_worms_mother_fetches);
	write(stdout, message, strlen(message) + 1);

	while (*total_birds > 0)
	{
		mutex_lock(room_lock);
		cond_wait(plate_empty, room_lock);
		if (*total_birds == 0) break;
		*dish = *dish + num_of_worms_mother_fetches;
		sprintf(message, "Parent bird filled the dish with %d worms!\n", num_of_worms_mother_fetches);
		write(stdout, message, strlen(message) + 1);
		cond_broadcast(plate_full);
		mutex_unlock(room_lock);
	}

	ready(main_pid);
}