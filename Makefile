CC	:= gcc
CFLAGS	:= -Wall -Wextra -Werror -pedantic -ansi -Os -v

SRCDIR	:= src/
CFILES	:= $(SRCDIR)*.c
TARGET	:= $(SRCDIR)main.elf



all:	$(TARGET)


clean:	
	$(RM) $(SRCDIR)/*.elf


run:	$(TARGET)
	clear
	./$<



%.elf:	$(CFILES)
	$(CC) $(CFLAGS) -o $@ $^
