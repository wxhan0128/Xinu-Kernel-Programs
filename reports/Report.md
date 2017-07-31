How my program work

The core of my program is to find the regularity between ring element and value which is:
1. use the value mod the number of process and get the remainder;
2. if the remainder is 0, then choose the process which ring element is equal to this remainder directly to print the information;
3. if the remainder is not 0, then use the number of process minus the remainder and then choose the matching process;
4. for the processes which ring element is not match, use resched() to put it into the readyqueue, and execute the matching process.

-------------------------------------------------------------------------------------------------------------------------------------
Program output

1. default version
---command line input: xsh $ process_ring

example output:
Number of Processes: 4
Number of Rounds: 5
Ring Element 0 : Round 0 : Value : 20
Ring Element 1 : Round 0 : Value : 19
Ring Element 2 : Round 0 : Value : 18
Ring Element 3 : Round 0 : Value : 17
Ring Element 0 : Round 1 : Value : 16
Ring Element 1 : Round 1 : Value : 15
Ring Element 2 : Round 1 : Value : 14
Ring Element 3 : Round 1 : Value : 13
Ring Element 0 : Round 2 : Value : 12
Ring Element 1 : Round 2 : Value : 11
Ring Element 2 : Round 2 : Value : 10
Ring Element 3 : Round 2 : Value : 9
Ring Element 0 : Round 3 : Value : 8
Ring Element 1 : Round 3 : Value : 7
Ring Element 2 : Round 3 : Value : 6
Ring Element 3 : Round 3 : Value : 5
Ring Element 0 : Round 4 : Value : 4
Ring Element 1 : Round 4 : Value : 3
Ring Element 2 : Round 4 : Value : 2
Ring Element 3 : Round 4 : Value : 1

2. work version
---command line input: xsh $ process_ring -r 6 -p 7 -v work

example output:
Number of Processes: 7
Number of Rounds: 6
Ring Element 0 : Round 0 : Value : 42
Ring Element 1 : Round 0 : Value : 41
Ring Element 2 : Round 0 : Value : 40
Ring Element 3 : Round 0 : Value : 39
Ring Element 4 : Round 0 : Value : 38
Ring Element 5 : Round 0 : Value : 37
Ring Element 6 : Round 0 : Value : 36
Ring Element 0 : Round 1 : Value : 35
Ring Element 1 : Round 1 : Value : 34
Ring Element 2 : Round 1 : Value : 33
Ring Element 3 : Round 1 : Value : 32
Ring Element 4 : Round 1 : Value : 31
Ring Element 5 : Round 1 : Value : 30
Ring Element 6 : Round 1 : Value : 29
Ring Element 0 : Round 2 : Value : 28
Ring Element 1 : Round 2 : Value : 27
Ring Element 2 : Round 2 : Value : 26
Ring Element 3 : Round 2 : Value : 25
Ring Element 4 : Round 2 : Value : 24
Ring Element 5 : Round 2 : Value : 23
Ring Element 6 : Round 2 : Value : 22
Ring Element 0 : Round 3 : Value : 21
Ring Element 1 : Round 3 : Value : 20
Ring Element 2 : Round 3 : Value : 19
Ring Element 3 : Round 3 : Value : 18
Ring Element 4 : Round 3 : Value : 17
Ring Element 5 : Round 3 : Value : 16
Ring Element 6 : Round 3 : Value : 15
Ring Element 0 : Round 4 : Value : 14
Ring Element 1 : Round 4 : Value : 13
Ring Element 2 : Round 4 : Value : 12
Ring Element 3 : Round 4 : Value : 11
Ring Element 4 : Round 4 : Value : 10
Ring Element 5 : Round 4 : Value : 9
Ring Element 6 : Round 4 : Value : 8
Ring Element 0 : Round 5 : Value : 7
Ring Element 1 : Round 5 : Value : 6
Ring Element 2 : Round 5 : Value : 5
Ring Element 3 : Round 5 : Value : 4
Ring Element 4 : Round 5 : Value : 3
Ring Element 5 : Round 5 : Value : 2
Ring Element 6 : Round 5 : Value : 1

3. hang version
---command line input: xsh $ process_ring -v hang

example output:
xsh $ process_ring -v hang
Number of Processes: 4
Number of Rounds: 5
the program exit

4. chaos version
---command line input: xsh $ process_ring -p 6 -r 4 -v chaos

example output:
Number of Processes: 6
Number of Rounds: 4
Ring Element 0 : Round 0 : Value : 24
Ring Element 0 : Round 1 : Value : 23
Ring Element 1 : Round 0 : Value : 22
Ring Element 0 : Round 2 : Value : 21
Ring Element 1 : Round 1 : Value : 20
Ring Element 2 : Round 0 : Value : 19
Ring Element 0 : Round 3 : Value : 18
Ring Element 1 : Round 2 : Value : 17
Ring Element 2 Ring Element 3 : Round 0 : Value : 16
Ring Element 1 : Round 3 : Value : 15
: Round 1 : Value : 16
Ring Element 3 : Round 1 : Value : 13
Ring Element 4 : Round 0 : Value : 12
Ring Element 2 : Round 2 : Value : 11
Ring Element 3 : Round 2 : Value : 10
Ring Element 4 : Round 1 : Value : 9
Ring Element 5 : Round 0 : Value : 8
Ring Element 2 : Round 3 : Value : 7
Ring Element 3 : Round 3 : Value : 6
Ring Element 4 : Round 2 : ValueRing Element 5 : Round 1 : Value : 5
 : 5
Ring Element 5 : Round 2 : Value : 3
Ring Element 4 : Round 3 : Value : 2
Ring Element 5 : Round 3 : Value : 1

5. loop version
---command line input: xsh $ process_ring -v loop

example output:
Ring Element 2 : Round 1586 : Value : -6365
Ring Element 2 : Round 1587 : Value : -6366
Ring Element 2 : Round 1588 : Value : -6367
Ring Element 2 : Round 1589 : Value : -6368
Ring Element 2 : Round 1590 : Value : -6369
Ring Element 2 : Round 1591 : Value : -6370
Ring Element 2 : Round 1592 : Value : -6371
Ring Element 2 : Round 1593 : Value : -6372
Ring Element 2 : Round 1594 : Value : -6373
Ring Element 2 : Round 1595 : Value : -6374
Ring Element 2 : Round 1596 : Value : -6342
Ring Element 3 : Round 1572 : Value : -6376
Ring Element 3 : Round 1573 : Value : -6377
Ring Element 3 : Round 1574 : Value : -6378
Ring Element 3 : Round 1575 : Value : -6379
Ring Element 3 : Round 1576 : Value : -6380
Ring Element 3 : Round 1577 : Value : -6381
Ring Element 3 : Round 1578 : Value : -6382
Ring Element 3 : Round 1579 : Value : -6383
Ring Element 3 : Round 1580 : Value : -6384
Ring Element 3 : Round 1581 : Value : -6385
Ring Element 1 : Round 1658 : Value : -6572
Ring Element 1 : Round 1659 : Value : -6573
Ring Element 1 : Round 1660 : Value : -6574
Ring Element 1 : Round 1661 : Value : -6575
Ring Element 1 : Round 1662 : Value : -6576
Ring Element 1 : Round 1663 : Value : -6577
Ring Element 1 : Round 1664 : Value : -6578
Ring Element 1 : Round 1665 : Value : -6579
Ring Element 1 : Round 1666 : Value : -6580
Ring Element 1 : Round 1667 : Value : -6581
Ring Element 1 : Round 1668 : Value : Element 2 : Round 1640 : Value : -6550
Ring Element 2 : Round 1641 : Value : -6583
Ring Element 2 : Round 1642 : Value : -6584
Ring Element 2 : Round 1643 : Value : -6585
Ring Element 2 : Round 1644 : Value : -6586
Ring Element 2 : Round 1645 : Value : -6587
Ring Element 2 : Round 1646 : Value : -6588
Ring Element 2 : Round 1647 : Value : -6589
Ring Element 2 : Round 1648 : Value : -6590
Ring Element 2 : Round 1649 : Value : -6591

--------------------------------------------------------------------------------------------------------------------------------------------------------
Question

1. When my program calls the "hang" function, we could found that for the first process, it is waiting for other processes to execute. Similarly,
each process is waiting for others, then it could causes the system hang. It is called deadlock.

2. Because I change the condition for the while loop, and assure the program never end this loop.
This is called infinite loop or endless loop.

3. It occurs when two or more processes can access shared data and they try to change it at the same time. Because the process scheduling algorithm 
can swap between processes at any time, we don't know the order in which the processes will attempt to access the shared data. 
This is called race condition.

4. In Xinu, each process is associated with a priority and the highest priority ready process is always chosen for execution. 
Among processes with equal priority scheduling is round-robin. By round-robin we mean that processes are selected one after another 
so that all members of a set have an opportunity to execute before any member has a second chance. And Xinu provides semaphores to synchronize processes.