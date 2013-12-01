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
		
		/* Creat a new child from superman */
		pid = fork();
		if (pid < 0)
		    printf("Error in fork!");
		else if (pid == 0) {
	 	    /* The second superman should be superman too. */
			printf("This is child of superman, I'm superman too.\n");
		}

		/* Both the two supermans will return to normal. */
	    kryptonite();
	} else {
		printf("This is parent thread.\n");
	}
    
	return 0;
}
