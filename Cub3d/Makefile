
# Compiler and flags
CC = gcc
CFLAGS = 
FILE = map.cub
# Source files and object files
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

# Target executable
TARGET = myprogram

# Default target
all: $(TARGET)

# Rule to build the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@
		@echo "If you want to run the program tape x if no tape n"
	@read -p ">> " answer; \
	if [ $$answer = "x" ]; then \
		./$(TARGET) $(FILE); \
	else \
		echo "Goodbye"; \
	fi

re: fclean all

# Rule to build object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -f $(OBJS) $(TARGET)

fclean: clean
	rm -f $(TARGET)