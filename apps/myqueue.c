#include <mutex_and_cv.h>

void myenqueue(pid32 b_pid, struct cond_v_t *cv)
{
	int i;
	mutex_lock(cv->mylock);

	for (i = 0; i < 50; i++)
	{
		if (cv->pidtab[i] == -1)
		{
			cv->pidtab[i] = b_pid;
			break;
		}
	}

	mutex_unlock(cv->mylock);
}

pid32 mydequeue(struct cond_v_t *cv)
{
	int i;
	mutex_lock(cv->mylock);
	pid32 r_pid = cv->pidtab[0];

	for (i = 0; i < 49; i++)
	{
		cv->pidtab[i] = cv->pidtab[i + 1];
	}

	cv->pidtab[49] = -1;
	mutex_unlock(cv->mylock);

	return r_pid;
}

bool myisempty(int* pidtb)
{
	return (pidtb[0] == -1);
}