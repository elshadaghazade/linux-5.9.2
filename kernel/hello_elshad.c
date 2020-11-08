#include <linux/syscalls.h>
#include <linux/printk.h>

SYSCALL_DEFINE2(hello_elshad, long unsigned __user *, pmajreport,
		long unsigned __user *, pminreport)
{
	printk(KERN_WARNING
	       "Hello from the hello_elshad system call written by ... \n");
	printk(KERN_WARNING "Param values: %p %p\n", pmajreport, pminreport);
	return 0;
}