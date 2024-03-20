#include<stdio.h>
#include"util.h"

int main(){
	print_desc();
	puts("==================");
	puts("Can you crack the hash of my program.text segment?");
	__asm__ __volatile__(
                "nop;"
		"nop;"
        );
	print_exit();
	return 0;
}
