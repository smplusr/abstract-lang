CC	:= cc
DEBUG	:= -DDEBUG_LANG		\
	   -DDEBUG_DICT		\
	   -DDEBUG_STRING	\
	   -DDEBUG_STREAM	\
	   -DDEBUG_CALL		\

CFLAGS	:= -Wall -Wextra -Werror -ansi -pedantic -O2	#$(DEBUG)


TARGET	:= main.elf



all:	$(TARGET)


run:	$(TARGET)
	./$<

clean:
	$(RM) *.elf



%.elf:	*.c
	$(CC) $(CFLAGS) -o $@ $^
