Section 1
--------------------------------------------------------------------------------------------------------------------------------------------------------------

In my program, I use a shared resource which is mutex (a lock) to solve the problem of babybirds eat worms. As each babybird will obtain the mutex,
and decided whether to eat or wait based on the value of mutex. Then, I use condition variables to solve the problem of parent bird fetch worms. As
the parent bird put the worms into the dish, it will suspend based on the conditional variables, and wait for the babybirds to update the conditional
variables (when there is only one worm in the dish), and wake up to fetch worms.

For the lock mechanism which I used in my program is Test-And-Set.

--------------------------------------------------------------------------------------------------------------------------------------------------------------


Section 2
--------------------------------------------------------------------------------------------------------------------------------------------------------------

Question 1
Starvation is a problem encountered in concurrent computing where a process is perpetually denied necessary resources to process its work.
Starvation may be caused by errors in a scheduling or mutual exclusion algorithm, but can also be caused by resource leaks, 
and can be intentionally caused via a denial-of-service attack.

Question 2
Deadlock is a common problem in multiprocessing where many processes share a specific type of mutually exclusive resource known as a software, 
or soft, lock. Deadlock refers to a specific condition when two or more processes are each waiting for another to release a resource,
or more than two processes are waiting for resources in a circular chain.


In this example, it is not starvation-free and not deadlock-free as well.

For the reasons, first assume that there are two threads.

The statement "int me = ThreadID.get()" obtains the id and does the do-while loop. Since it always do the assignment statement first ("true = me"), 
and then check the while condition, this condition will never satisfied. Therefore, if one thread called lock function, it will always hold it, 
and another thread called unlock will always wait it realse the lock, which calls the dead-lock.

And since in this example, there exists the dead-lock, and there has a variable called "turn" which could decide the priority of the thread. Thus, it 
could also have the situation of starvation.