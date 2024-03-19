TARGET = elf-crackme-level3.0
CC     = gcc-4.4
CFLAGS = -Wall -Wextra -Werror -m32
INCLUDE = -I ../../include ../../include/util.c

.PHONY: all clean

all: $(TARGET)

%: %.c
	$(CC) $(CFLAGS) $(SECFLAGS) $(INCLUDE) -o $@ $<

clean: 
	rm -rf $(TARGET)
