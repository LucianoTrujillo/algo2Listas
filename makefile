CFLAGS=-Wall -Werror -Wconversion -std=c99 -g -O0
VFLAGS=--leak-check=full --track-origins=yes --show-reachable=yes
OUTPUT=lista_se
DEPENDENCIES=lista.c
ENTRY=pruebas.c

all: $(OUTPUT) mem_test

$(OUTPUT): $(DEPENDENCIES) $(ENTRY)
	gcc *.c $(CFLAGS) -o $(OUTPUT)

mem_test: $(OUTPUT)
	valgrind $(VFLAGS) ./$(OUTPUT)

debug: $(OUTPUT)
	gdb -tui $(OUTPUT)

clean:
	rm -f *.o $(OUTPUT)