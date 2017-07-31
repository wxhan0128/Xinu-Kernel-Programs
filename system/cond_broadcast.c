/* cond_broadcast.c - cond_broadcast */

#include <xinu.h>
#include <mutex_and_cv.h>

/*------------------------------------------------------------------------
 *  cond_broadcast  -  Broadcast the condition variable.
 *------------------------------------------------------------------------
 */

syscall	cond_broadcast(struct cond_v_t *cv)
{
	int i;
	mutex_lock(cv->mylock);

	for (i = 0; i < 50; i++)
	{
		if (cv->pidtab[i] == -1)
			break;

		resume(cv->pidtab[i]);
	}

	mutex_unlock(cv->mylock);
	return OK;
}