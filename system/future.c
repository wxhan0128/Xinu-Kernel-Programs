#include <xinu.h>
#include <future.h>

void ftenqueue(pid32 b_pid, int *q){
	int i;
	for (i = 0; i < 20; i++){
		if (q[i] == -1){
			q[i] = b_pid;
			break;
		}
	}
}

pid32 ftdequeue(int *q){
	int i;
	pid32 r_pid = q[0];
	for (i = 0; i < 19; i++){
		q[i] = q[i + 1];
	}
	q[19] = -1;
	return r_pid;
}

bool ftisempty(int* pidtb){
	return (pidtb[0] == -1);
}

int ftqueuelength(int* q){
	int len = 0, i;
	for (i = 0; i < 20; i++){
		if (q[i] == -1) break;
		len++;
	}
	return len;
}

future_t* future_alloc(future_mode_t mode){
	char* add_alloc = getmem(sizeof(future_t));
	if (add_alloc == (char *)SYSERR) return NULL;
	
	future_t* ft;
	ft = (future_t*)add_alloc;
	
	ft->state = FUTURE_EMPTY;
	ft->mode = mode;
	ft->value = NULL;
	ft->pid = NULL;
	
	int i;
	for (i = 0; i < 20; i++){
		ft->set_queue[i] = -1;
		ft->get_queue[i] = -1;
	}
	
	return ft;
}

syscall future_free(future_t* f){
	pid32 pid;
	while((pid = ftdequeue(f->get_queue)) != -1) kill(pid);
	while((pid = ftdequeue(f->set_queue)) != -1) kill(pid);
	return freemem((char*)f, sizeof(future_t));
}

syscall future_get(future_t* f, int* value){
	if (f->mode == FUTURE_EXCLUSIVE){
		if (f->state == FUTURE_WAITING) return SYSERR;
		while (f->state != FUTURE_READY){
			//if (f->state == FUTURE_WAITING) return SYSERR;
			f->state = FUTURE_WAITING;
			f->pid = currpid;
			//ftenqueue(currpid, f->get_queue);
			suspend(currpid);
		}
		*value = f->value;
		f->state = FUTURE_EMPTY;
		f->pid = NULL;
		//return OK;
	}
	else if (f->mode == FUTURE_SHARED){
		if (f->state != FUTURE_READY){
			//if (f->state == FUTURE_WAITING) return SYSERR;
			f->state = FUTURE_WAITING;
			f->pid = currpid;
			ftenqueue(currpid, f->get_queue);
			suspend(currpid);
		}
		*value = f->value;
		f->state = FUTURE_EMPTY;
		f->pid = NULL;
		//return OK;
	}
	else {
		//if (ftqueuelength(f->set_queue) == 0){
		if (ftisempty(f->set_queue)){
			//if (f->state == FUTURE_WAITING) return SYSERR;
			f->state = FUTURE_WAITING;
			f->pid = currpid;
			ftenqueue(currpid, f->get_queue);
			suspend(currpid);
		}
		else {
			f->state = FUTURE_WAITING;
			f->pid = currpid;
			ftenqueue(currpid, f->get_queue);
			signal(ftdequeue(f->set_queue));
			suspend(currpid);//sleep(1);
		}
		*value = f->value;
		f->state = FUTURE_EMPTY;
		f->pid = NULL;
		//return OK;
	}
	return OK;
}

syscall future_set(future_t* f, int value){
	if (f->mode == FUTURE_EXCLUSIVE){
		if (f->state == FUTURE_READY) return SYSERR;
		f->value = value;
		f->state = FUTURE_READY;
		ready(f->pid);
	}
	else if (f->mode == FUTURE_SHARED){
		if (f->state == FUTURE_READY) return SYSERR;
		f->value = value;
		f->state = FUTURE_READY;
		pid32 pid;
		while((pid = ftdequeue(f->get_queue)) != -1) ready(pid);
	}
	else {
		//if (ftqueuelength(f->get_queue) == 0){
		if (ftisempty(f->get_queue)){
			ftenqueue(currpid, f->set_queue);
			suspend(currpid);
			//f->value = value;
			//f->state = FUTURE_READY;
			//pid32 pid;
			//if((pid = ftdequeue(f->get_queue)) != -1) ready(pid);
		}
		//else{
		f->value = value;
		f->state = FUTURE_READY;
		pid32 pid;
		if((pid = ftdequeue(f->get_queue)) != -1) ready(pid);
			//printf("here\n");
		
		//}

	}
	return OK;
}

