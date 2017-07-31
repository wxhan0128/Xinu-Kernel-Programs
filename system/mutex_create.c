/* mutex_create.c - mutex_create */

#include <xinu.h>
#include <mutex_and_cv.h>

/*------------------------------------------------------------------------
 *  mutex_create  -  Initialize a mutex
 *------------------------------------------------------------------------
 */

syscall	mutex_create(struct mutex_t *mutex)
{
	mutex->flag = 0;
	return OK;
}