# process_generator


Program starts in creating a parent process.

Parent fork()s, creating child 1.

You now have two processes. We change the scheduling policy of the child 1 to FIFO scheduling policy.


Parent and child 1 fork(), creating children 2.

You now have four processes. Children 2 are changed to Round Robin scheduling policy.


Finally, we fork() again. You now have eight processes. And we change the newly fork() children scheduling policy to Batch.


So you get 1 default policy (TS), 1 FIFO (FF), 2 Round Robin (RR), and 4 Batch (B).



# Expected output
26972 process_generat  19 TS\
26973 process_generat 138 FF\
26974 process_generat 137 RR\
26975 process_generat  19 B\
26976 process_generat 137 RR\
26977 process_generat  19 B\
26978 process_generat  19 B\
26979 process_generat  19 B

