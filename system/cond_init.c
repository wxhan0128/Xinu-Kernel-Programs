/* cond_init.c - cond_init */

#include <xinu.h>
#include <mutex_and_cv.h>

/*------------------------------------------------------------------------
 *  cond_init  -  Initialize a condition variable
 *------------------------------------------------------------------------
 */

syscall	cond_init(struct cond_v_t *cv)
{
	int i;
	mutex_create(cv->mylock);
	mutex_lock(cv->mylock);

	for (i = 0; i < 50; i++)
	{
		cv->pidtab[i] = -1;
	}

	mutex_unlock(cv->mylock);
	return OK;
}