#ifndef __TOYOTA_H 
#define __TOYOTA_H

/*
 * toyota.h -- definitions for the char module
 */

#ifndef TOYOTA_MAJOR
#define TOYOTA_MAJOR 0   /* dynamic major by default */
#endif

#ifndef TOYOTA_NR_DEVS
#define TOYOTA_NR_DEVS 4    /* toyota0 through toyota3 */
#endif

/*
 * Split minors in two parts
 */
#define TYPE(dev)   (MINOR(dev) >> 4)  /* high nibble */
#define NUM(dev)    (MINOR(dev) & 0xf) /* low nibble */

#endif /* __TOYOTA_H */
