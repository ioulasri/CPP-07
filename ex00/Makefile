# Compiler
CC = c++

# Compiler flags
CFLAGS = -Wall -Wextra -Werror -std=c++98

# Source files
SRC = main.cpp

# Object files
OBJ = $(SRC:.cpp=.o)

# Executable name
NAME = templates

# Default target: compile and link
all: $(NAME)

# Linking the object files to create the executable
$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

# Compiling the .cpp files into .o object files
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files
clean:
	rm -f $(OBJ)

# Clean up object files and executable
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re