CC	:= cc
CFLAGS	:= -Wall -Wextra -Werror -pedantic -ansi -O2 -v

SRCDIR	:= src/
CFILES	:= $(SRCDIR)*.c
TARGET	:= $(SRCDIR)main.elf
PARAMS	:=



all:	$(TARGET)
#	mv $< /bin/shll


clean:	
	$(RM) $(SRCDIR)/*.elf


run:	$(TARGET)
	./$< $(PARAMS)



%.elf:	$(CFILES)
	$(CC) $(CFLAGS) -o $@ $^
