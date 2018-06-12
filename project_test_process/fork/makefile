src=$(wildcard ./*.c)
target=$(patsubst ./%.c, ./%, $(src))
obj=$(patsubst ./%.c, ./%.o, $(src))
CC=gcc
$(target):$(obj)
	$(CC) $(obj) -o $(target)
%.o:%.c
	$(CC) -c $< -o $@

.PHONY:clean
clean:
	rm $(target) -f
