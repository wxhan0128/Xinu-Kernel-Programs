/* mutex_lock.c - mutex_lock */

#include <xinu.h>
#include <mutex_and_cv.h>

/*------------------------------------------------------------------------
 *  mutex_lock  -  Obtain a mutex. If it is currently held by another process, this process will sleep and wait until it is released
 *------------------------------------------------------------------------
 */

syscall	mutex_lock(struct mutex_t *mutex)
{
	while (TestAndSet(&mutex->flag, 1) == 1)
		yield();

	return OK;
}

int TestAndSet(int *old_ptr, int new)
{
	intmask	mask = disable();

	int old = *old_ptr; // fetch old value at old_ptr
	*old_ptr = new; // store 'new' into old_ptr

	restore(mask);
	return old; // return the old value
}