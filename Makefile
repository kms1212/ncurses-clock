# Makefile for ncurses-clock program

# --- Define compiler and compiler options ---
CC = clang
CFLAGS = -std=c99 -g -Wall -O2
INCLUDES = -lncurses -lpthread -lc
BYTECODE = clock
INSTPATH = /usr/bin/clock

# --- List program modules and associated object files ---
MODULES_LIST = \
	main \
	blockString \
	clockWindow \
	dateTimeModel \
	scanAndConfig \
	prgCmdLine \
	font \

OBJECT_FILES = $(MODULES_LIST:%=obj/%.o)


# --- Define the build rules ---
all: $(BYTECODE)
	
$(BYTECODE) : $(OBJECT_FILES)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJECT_FILES) -o bin/$(BYTECODE)

obj/%.o: src/%.c
	$(CC) $(CFLAGS) $< -o $@ -c 

install: all
	cp bin/$(BYTECODE) $(INSTPATH)

uninstall:
	rm -f $(INSTPATH)

clean:
	rm -f bin/$(BYTECODE) $(OBJECT_FILES)
 
run : all
	bin/$(BYTECODE)
	