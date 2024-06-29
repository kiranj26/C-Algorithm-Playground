CC=gcc
CFLAGS=-I.
LDFLAGS=-lm

# Function to do a recursive wildcard search
rwildcard=$(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2)$(filter $(subst *,%,$2),$d))

SRC=$(call rwildcard,.,*.c)
OBJ=$(SRC:.c=.o)
EXEC=$(SRC:.c=)

all: $(EXEC)

%: %.o
	$(CC) -o $@ $< $(LDFLAGS)

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -f $(OBJ) $(EXEC)
