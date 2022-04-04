/*
 * the toyota char module
 */

#include <linux/module.h>

#include <linux/kernel.h> /* printk() */
#include <linux/slab.h> /* for kmalloc() */
#include <linux/version.h> /* for kmalloc() */
#include <linux/fs.h>     /* everything... */
#include <linux/file.h>     /* everything... */
#include <linux/errno.h>  /* error codes */
#include <linux/types.h>  /* size_t */
#include <linux/fcntl.h>        /* O_ACCMODE */
#include <linux/kmod.h>        /* for request_module */
#include <linux/init.h>
#if LINUX_VERSION_CODE >= KERNEL_VERSION(4,11,12)
#include <linux/sched/signal.h>
#else
#include <linux/signal.h>
#endif
#include <linux/sched.h>
#include <linux/uaccess.h>

#include "toyota.h"        /* local definitions */

#define TOYOTA_DEBUG 1

MODULE_AUTHOR("Jidong Xiao"); /* change this line to your name */
MODULE_LICENSE("GPL");

static int toyota_major = TOYOTA_MAJOR;
static int toyota_nr_devs = TOYOTA_NR_DEVS;    /* number of bare toyota devices */

static int toyota_open (struct inode *inode, struct file *filp);
static int toyota_release (struct inode *inode, struct file *filp);
static ssize_t toyota_read (struct file *filp, char *buf, size_t count, loff_t *f_pos);
static ssize_t toyota_write (struct file *filp, const char *buf, size_t count, loff_t *f_pos);

/*  The different file operations */
static struct file_operations toyota_fops = {
    .owner =      THIS_MODULE,
    .read =       toyota_read,
    .write =      toyota_write,
    .open =       toyota_open,
    .release =    toyota_release,
};

/*
 * open
 */

static int toyota_open (struct inode *inode, struct file *filp){
    return 0;          /* success */
}

/*
 * close
 */

static int toyota_release (struct inode *inode, struct file *filp){
    return 0;
}

/* write the string to toyota_device->data for minor number 0;
 * pretends to ignore writes (like /dev/null) for minor numbers 1,2;
 * kill the calling process for minor number 3;
 * we assume applications will access our device sequentially, i.e., they do not access multiple devices concurrently.
 */
static ssize_t toyota_write (struct file *filp, const char *buf, size_t count, loff_t *f_pos){
	return count;
}

/* when read, we do not care the device minor number,
 * we process whatever is in toyota_device->data, and return the processed string (maybe multiple times) to user.
 * we assume applications will access our device sequentially, i.e., they do not access multiple devices concurrently.
 */
static ssize_t toyota_read (struct file *filp, char *buf, size_t count, loff_t *f_pos){
    return count;
}

/*
 * module initialization
 */

static int __init toyota_init(void){
	return 0;
}

/*
 * module exit
 */

static void __exit toyota_exit(void){
}

module_init(toyota_init);
module_exit(toyota_exit);

/* vim: set ts=4: */
