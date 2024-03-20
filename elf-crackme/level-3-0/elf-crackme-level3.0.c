#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include"util.h"

void read_flag() {
	char *command = "cat";
    	char *args[] = {"cat", "/flag", NULL};  
        puts("What address does plt jump to for the first time?"); 
        if (execve(command, args, NULL) == -1) {
	perror("execve");
        exit(EXIT_FAILURE);  
    }
}

int main() {
    print_desc();
    read_flag();
    print_exit();
    return 0;
}
