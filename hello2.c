#include <linux/module.h>
#include <linux/printk.h>
#include "hello1.h"

MODULE_AUTHOR("Volodymyr Borodii");
MODULE_DESCRIPTION("Hello1, Lab5");
MODULE_LICENSE("Dual BSD/GPL");

static int count = 1;
module_param(count, int, 0444);
MODULE_PARM_DESC(count, "Number of times to print 'Hello, world!' message");

static int __init hello2_init(void)
{
	BUG_ON(count < 0 || count > 10);
	if (count == 0 || (count >= 5 && count <= 10)) {
		pr_warn("Warning: count is 0 or between 5 and 10.\n");
	}
	print_hello(count);

	return 0;
}

static void __exit hello2_exit(void)
{
	pr_info("Goodbye, world!\n");
}

module_init(hello2_init);
module_exit(hello2_exit);

