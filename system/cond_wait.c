/* cond_wait.c - cond_wait */

#include <xinu.h>
#include <mutex_and_cv.h>

/*------------------------------------------------------------------------
 *  cond_wait  -  Wait on the condition variable.
 *------------------------------------------------------------------------
 */

syscall	cond_wait(struct cond_v_t *cv, struct mutex_t *mutex)
{
	myenqueue(currpid, cv);
	mutex_unlock(mutex);
	suspend(currpid);
	mutex_lock(mutex);

	return OK;
}