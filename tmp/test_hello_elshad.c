#define _GNU_SOURCE
#include <unistd.h>
#include <sys/syscall.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	unsigned long majpfaults, minpfaults;
	majpfaults =
		99999999; /*Phony values so we can see if the kernel never overwrote them.*/
	minpfaults =
		99999999; /*Phony values so we can see if the kernel never overwrote them.*/
	int retval = syscall(440, &majpfaults, &minpfaults);
	if (retval < 0) {
		perror("My system call returned with an error code.");
	}
	printf("My syscall's parameters: %p %p\n", &majpfaults, &minpfaults);
	printf("My system call returned %d.\n", retval);
	printf("Current values:  majpfaults=%lu minpfaults=%lu\n", majpfaults,
	       minpfaults);
	return 0;
}