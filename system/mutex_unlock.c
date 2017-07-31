/* mutex_unlock.c - mutex_unlock */

#include <xinu.h>
#include <mutex_and_cv.h>

/*------------------------------------------------------------------------
 *  mutex_unlock  -  Release a mutex.
 *------------------------------------------------------------------------
 */

syscall	mutex_unlock(struct mutex_t *mutex)
{
	mutex->flag = 0; // let go of lock; no one wants it

	return OK;
}