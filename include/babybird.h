#include <xinu.h>
#include <mutex_and_cv.h>

void babybird_eat(int, int, int*, struct mutex_t*, struct mutex_t*, struct cond_v_t*, struct cond_v_t*, int*, struct cond_v_t*);
void parentbird_fetch(int, pid32, int*, struct mutex_t*, struct cond_v_t*, struct cond_v_t*, int*);