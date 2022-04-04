
KERNEL_SOURCE=/lib/modules/`uname -r`/build

all: toyota test-toyota

toyota:
	 make -C ${KERNEL_SOURCE} M=`pwd` modules

obj-m += toyota.o

test-toyota: test-toyota.o
	$(CC) $(CFLAGS) -o $@ $^
	

clean:
	/bin/rm -f test-toyota test-toyota.o
	/bin/rm -f .toyota* toyota.o toyota.mod.c toyota.mod.o toyota.ko Module.* modules.*
	/bin/rm -rf .tmp_versions/



