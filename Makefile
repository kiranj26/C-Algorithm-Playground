# Define the compiler
CC=gcc

# Define compiler flags
CFLAGS=-Iinclude -Wall -Wextra -std=c99

# Define linker flags
LDFLAGS=-lm

# Function to do a recursive wildcard search, excluding jump-search-simple.c
rwildcard=$(foreach d,$(wildcard $1*),$(if $(filter-out searching/jump-search-simple.c,$d),$(call rwildcard,$d/,$2),)$(filter $(subst *,%,$2),$d))

# Find all .c files, excluding jump-search-simple.c
SRC=$(call rwildcard,src/,*.c)
# Convert .c filenames to .o filenames
OBJ=$(SRC:.c=.o)
# Convert .c filenames to executable names
EXEC=$(SRC:.c=)

# Default target to build all executables
all: $(EXEC)

# Rule to link object files into executables
# $(LDFLAGS) is placed at the end to ensure the math library is linked correctly
%: %.o
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

# Rule to compile .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean target to remove all object files and executables
clean:
	rm -f $(OBJ) $(EXEC)
