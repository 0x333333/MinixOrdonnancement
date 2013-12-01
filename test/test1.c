#include <lib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <minix/ipc.h>

int kryptonite(void) {
    message m;
	int r;
	m.m1_i1 = -1;
	r = _syscall(PM_PROC_NR, PM_SUPERMAN, &m);
	return r;
}

int superman(void) {
    message m;
	int r;
	m.m1_i1 = 1;
	r = _syscall(PM_PROC_NR, PM_SUPERMAN, &m);
	return r;
}

int main(void)
{
    int pid, x;
	pid = fork();
    
	if (pid < 0) {
        printf("Error in fork!");
	} else if (pid == 0) {
	    superman();
		printf("This is child thread, I'm superman.\n");
		printf("Do you want to stop me? 1:yes, 0:no.\n"); /* Waiting for input */
		scanf("%d", &x); /* Input */
		if (x == 1) {
		    kryptonite();
		}
	} else {
		printf("This is parent thread.\n");
	}
    
	return 0;
}
