NAME      = get_next_line

CC        = gcc
CFLAGS    = -Wall -Wextra -Werror
AR        = ar
ARFLAGS   = rcs
RM        = rm -rf

SRCS      = get_next_line.c \
			get_next_line_utils.c

OBJ_DIR   = obj
OBJS      = $(SRCS:%.c=$(OBJ_DIR)/%.o)

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)
	rm -f program

re: fclean all

main: $(NAME) main.c $(OBJS)
	$(CC) $(CFLAGS) main.c $(OBJS) -o program

run: 	fclean main
		./program

val: 	fclean main
		valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes ./program
		
.PHONY: all clean fclean re
