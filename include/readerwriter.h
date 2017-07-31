extern	int	counter;
extern	sid32	mutex;

extern	sid32	readSwitch;
extern	sid32	roomEmpty;
extern	sid32	turnstile;

void	readers(int, int, int);
void	writers(int, int, int);
void	lock(sid32);
void	unlock(sid32);
void	rand_delay(int);