.PHONY : all
all :
	cd libc; make
	cd kernel; make

.PHONY : clean
clean :
	cd libc; make clean
	cd kernel; make clean
