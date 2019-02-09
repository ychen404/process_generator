#define _GNU_SOURCE

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sched.h>


#define CURR_THREAD 0
#define MY_PRIORITY 98


/*

Loop starts in parent, i == 0

Parent fork()s, creating child 1.

You now have two processes. Both print i=0.

Loop restarts in both processes, now i == 1.

Parent and child 1 fork(), creating children 2 and 3.

You now have four processes. All four print i=1.

Loop restarts in all four processes, now i == 2.

Parent and children 1 through 3 all fork(), creating children 4 through 7.

You now have eight processes. All eight print i=2.

Loop restarts in all eight processes, now i == 3.

Loop terminates in all eight processes, as i < 3 is no longer true.

All eight processes print hi.

All eight processes terminate.

So you get 0 printed two times, 1 printed four times, 2 printed 8 times, and hi printed 8 times.

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
	param.sched_priority = MY_PRIORITY;


	for (int i = 0; i < 3; i++) {
	int ret;

	if (i == 0) {
		// fifo
		ret = sched_getparam(CURR_THREAD, &param);
	 	param.sched_priority = 98;

		if (sched_setscheduler(CURR_THREAD, SCHED_FIFO, &param) == -1) {
				fprintf(stderr, "error setting scheduler, make sure you are root.\n");
				exit(1);}
		//printSchedulingPolicy();
	}

	if (i == 1) {
		// rr
		ret = sched_getparam(CURR_THREAD, &param);
		param.sched_priority = 97;

		if (sched_setscheduler(CURR_THREAD, SCHED_RR, &param) == -1) {
				fprintf(stderr, "error setting scheduler, make sure you are root.\n");
				exit(1);}
		//printSchedulingPolicy();

	}

	if (i == 2) {
		// batch
		ret = sched_getparam(CURR_THREAD, &param);
		param.sched_priority = 0;

		if (sched_setscheduler(CURR_THREAD, SCHED_BATCH, &param) == -1) {
				fprintf(stderr, "error setting scheduler, make sure you are root.\n");
				exit(1);}
		//printSchedulingPolicy();

	} 

	fork();
	printf("[%d] [%d] i=%d\n", getppid(), getpid(), i);

	}
	//printf("hello\n");
	//printf("Hello [%d] [%d]\n", getppid(), getpid());


}


void siren()
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

	siren();
	while(1){}
	return 0;
}







