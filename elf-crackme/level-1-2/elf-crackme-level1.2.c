#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"util.h"

void init()
{
	setvbuf(stdin,0,2,0);
	setvbuf(stdout,0,2,0);
	setvbuf(stderr,0,2,0);
}


int main(){
	init();
	print_desc();
	puts("Please fix me, and after fixing, execute the Python script to obtain the flag.\n");		
	print_exit();

	return 0;
}
