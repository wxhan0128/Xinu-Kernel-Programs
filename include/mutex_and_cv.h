#include <xinu.h>

struct mutex_t {
    int flag;
    
};

struct cond_v_t {
    struct  mutex_t *mylock;
    pid32 pidtab[50];
    //qid16 condq;
};

syscall	mutex_create(struct mutex_t*);

syscall	mutex_lock(struct mutex_t*);

syscall	mutex_unlock(struct mutex_t*);

syscall	cond_init(struct cond_v_t*);

syscall	cond_wait(struct cond_v_t*, struct mutex_t*);

syscall	cond_signal(struct cond_v_t*);

syscall	cond_broadcast(struct   cond_v_t*);

void myenqueue(pid32, struct	cond_v_t*);

pid32 mydequeue(struct	cond_v_t*);

bool myisempty(int*);