extern	sid32	mutex;
extern	sid32	items;
extern	sid32	spaces;

extern	int	buffer[];

void	producer(int, int, int, int);
void	consumer(int, int, int, int);
void	rand_delay(int);