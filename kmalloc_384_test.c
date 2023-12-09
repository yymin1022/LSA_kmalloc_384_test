#include <linux/init.h>
#include <linux/module.h>
#include <linux/slab.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("yymin1022@gmail.com");
MODULE_DESCRIPTION("Simple Module for Testing 384 Byte Allocation");

#define TEST_MEM_COUNT 409600
#define TEST_MEM_SIZE 384

static void **test_mem_ptr = NULL;

static int __init test_module_init(void)
{
	int	i;
	size_t	alloc_size;

	printk(KERN_INFO "384 TestModule: Loading\n");
	test_mem_ptr = kmalloc(sizeof(void *) * TEST_MEM_COUNT, GFP_KERNEL);
	if (!test_mem_ptr)
	{
		printk(KERN_ALERT "384 TestModule: Memory allocation failed\n");
		return -ENOMEM;
	}	

	alloc_size = 0;
	for(i = 0; i < TEST_MEM_COUNT; i++)
	{
		test_mem_ptr[i] = kmalloc(TEST_MEM_SIZE, GFP_KERNEL);
		alloc_size += ksize(test_mem_ptr[i]);
		printk(KERN_INFO "384 TestModule: Allocated %zu bytes for %d index\n", alloc_size, i);
	}

	printk(KERN_INFO "384 TestModule: Total Allocation got %zu bytes!\n", alloc_size);
	return 0;
}

static void __exit test_module_exit(void)
{
	int	i;

	printk(KERN_INFO "384 TestModule: Unloading\n");
	if (test_mem_ptr) {
		for(i = 0; i < TEST_MEM_COUNT; i++)
		{
			if (test_mem_ptr[i])
				kfree(test_mem_ptr[i]);
		}
		kfree(test_mem_ptr);
		printk(KERN_INFO "384 TestModule: Memory freed\n");
	}
}

module_init(test_module_init);
module_exit(test_module_exit);
