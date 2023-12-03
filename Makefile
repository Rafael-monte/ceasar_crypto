PROJ_NAME=ceasar_crypto
#C FILES
CPP_SOURCES=$(wildcard *.c)
#Header files
H_SOURCES=$(wildcard *.h)
#Object files
OBJ_FILES=$(CPP_SOURCES:.c=.o)
#Compiler
CC=gcc
#Compiler flags
CC_FLAGS=-c -Wall -Wpedantic


#Compilation and linking
all: $(PROJ_NAME)

$(PROJ_NAME): $(OBJ_FILES)
	$(CC) -o $@ $^

%.o: %.cpp %.h
	$(CC) -o $@ $< $(CC_FLAGS)

main.o: main.c $(H_SOURCES)
	$(CC) -o $@ $< $(CC_FLAGS)

clean:
	rm -rf *.o $(PROJ_NAME) *~
