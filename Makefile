	# Compiler
CC = gcc

# Compiler flags 
CFLAGS = -Wall -Wextra -std=c11 

# Target executable name
TARGET = inventory

# Source files 
SRCS = ItemManagementMain.c ItemFileIO.c ItemManagement.c

# Object files
OBJS = $(SRCS:.c=.o)

# Default rule
all: $(TARGET)

# Link the program
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compile .c → .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean compiled files
clean:
	rm -f $(TARGET) $(OBJS)

# Convenience run
run: $(TARGET)
	./$(TARGET)
