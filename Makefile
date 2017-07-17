
all:bmp.o

%.o:%.c
	$(CC) $< -o $@
	
.PHONY:clean
clean:
	rm -f *.o
	rm -f *.bmp

