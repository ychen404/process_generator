#define _GNU_SOURCE

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sched.h>


#define CURR_THREAD 0
#define MY_PRIORITY 98

/*

Loop starts in parent

Parent fork()s, creating child 1.

You now have two processes. We change the scheduling policy of the child 1 to FIFO scheduling policy.


Parent and child 1 fork(), creating children 2.

You now have four processes. Children 2 are changed to Round Robin scheduling policy


Finally, we fork() again. You now have eight processes. And we change the newly fork() children scheduling policy to Batch.


So you get 1 default policy (TS), 1 FIFO (FF), 2 Round Robin (RR), and 4 Batch (B).

*/


void printSchedulingPolicy(void)
{
	int which;
	which = sched_getscheduler(0);
	switch (which) {
	case SCHED_OTHER: 
			printf("default scheduling is being used\n");		
		  	break;
	case SCHED_FIFO:
			printf("fifo scheduling is being used\n");		
		  	break;
	case SCHED_RR:		
			printf("round robin scheduling is being used\n");	
			break;	
	case SCHED_BATCH:		
			printf("batch scheduling is being used\n");
		  	break;

	}		

}


void forkProcesses()
{

	int ret;
	struct sched_param param;
	ret = sched_getparam(CURR_THREAD, &param);

	int fork1 = fork();
	if (fork1 == 0)
	{
		printf("Child 1\n");
	 	param.sched_priority = 98;
		if (sched_setscheduler(CURR_THREAD, SCHED_FIFO, &param) == -1) {
			fprintf(stderr, "error setting scheduler, maker sure you are root\n");
		}
	}

	int fork2 = fork();
	if (fork2 == 0)
	{
		printf("Child 2\n");
		param.sched_priority = 97;
		if (sched_setscheduler(CURR_THREAD, SCHED_RR, &param) == -1) {
		fprintf(stderr, "error setting scheduler, maker sure you are root\n");
		}
	
	}

	int fork3 = fork();
	if (fork3 == 0)
	{
		printf("Child 3\n");
		param.sched_priority = 0;
		if (sched_setscheduler(CURR_THREAD, SCHED_BATCH, &param) == -1) {
		fprintf(stderr, "error setting scheduler, maker sure you are root\n");
		}
	}

}


int main(void)
{

	forkProcesses();
	while(1){}
	return 0;
}







