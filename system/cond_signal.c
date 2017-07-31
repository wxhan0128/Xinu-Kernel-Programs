/* cond_signal.c - cond_signal */

#include <xinu.h>
#include <mutex_and_cv.h>

/*------------------------------------------------------------------------
 *  cond_signal  -  Signal the condition variable.
 *------------------------------------------------------------------------
 */

syscall	cond_signal(struct cond_v_t *cv)
{
	pid32 go_pid = mydequeue(cv);

	if (go_pid != -1)
		resume(go_pid);

	return OK;
}