# Need to change that weird make hack
# Should have configurable compilation (similar to linux ARCH=x86)
# For now:	MODULES=LANG_ALL compiles every modules available
# 		MODULES=<anything else> compiles only core modules
# Default:	LANG_ALL

#MODULES	:= -DLANG_ALL




CC	:= cc
CFLAGS	:= -Wall -Wextra -Werror -static -ansi -pedantic -O2 -D_DEFAULT_SOURCE -DLANG_ALL
SOURCE	:= src
TARGET	:= $(SOURCE)/main.elf



all:	$(TARGET)


run:	$(TARGET)
	./$<

clean:
	$(RM) $(SOURCE)/*.elf



%.elf:	$(SOURCE)/*.c
	$(CC) $(CFLAGS) -o $@ $^
