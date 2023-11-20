#include <linux/init.h>
#include <linux/module.h>
#include <linux/slab.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("yymin1022@gmail.com");
MODULE_DESCRIPTION("Simple Module for Testing 384 Byte Allocation");

#define TEST_MEM_SIZE 384

static void *test_mem_ptr = NULL;

static int __init test_module_init(void)
{
    printk(KERN_INFO "384 TestModule: Loading\n");
    printk(KERN_INFO "384 TestModule: KMALLOC_MIN_SIZE is %d\n", KMALLOC_MIN_SIZE);
    printk(KERN_INFO "384 TestModule: KMALLOC_SHIFT_HIGH is %d\n", KMALLOC_SHIFT_HIGH);
    printk(KERN_INFO "384 TestModule: KMALLOC_SHIFT_LOW is %d\n", KMALLOC_SHIFT_LOW);

    test_mem_ptr = kmalloc(TEST_MEM_SIZE, GFP_KERNEL);

    if (!test_mem_ptr) {
        printk(KERN_ALERT "384 TestModule: Memory allocation failed\n");
        return -ENOMEM;
    }

    printk(KERN_INFO "384 TestModule: Memory allocated at %p\n", test_mem_ptr);
    return 0;
}

static void __exit test_module_exit(void)
{
    printk(KERN_INFO "384 TestModule: Unloading\n");

    if (test_mem_ptr) {
        kfree(test_mem_ptr);
        printk(KERN_INFO "384 TestModule: Memory freed\n");
    }
}

module_init(test_module_init);
module_exit(test_module_exit);

