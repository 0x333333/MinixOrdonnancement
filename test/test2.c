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
		printf("This is child thread.\n");
	} else {
	    superman();
		printf("This is parent thread.\n");
		printf("I'm superman.\n");
	    kryptonite();
	}
    
	return 0;
}
