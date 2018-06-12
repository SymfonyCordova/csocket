#obj=main.o add.o sub.o mul.o

target=app
#makefile中自己维护的变量一般是大写
#makefile中的函数的使用
src=$(wildcard ./*.c)
obj=$(patsubst ./%.c, ./%.o, $(src))
CC = gcc
CPPFLAGS = -I
$(target):$(obj)
	$(CC) $(obj) -o $(target)
%.o:%.c
	$(CC) -c $< -o $@

#声明未伪目标
.PHONY:clean
clean:
	-rm
	rm $(obj) $(target) -f

hello:
	echo "hello makefile"
