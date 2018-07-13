NAME = corewar

CC = gcc

FLAGS = #-Wall -Wextra -Werror 

RM = rm -f

SRC = src/main.c src/parsing/manage_arguments.c src/parsing/parsing.c src/manage_bot_list.c src/parsing/parse_bot.c src/parsing/parse_bot_id.c src/display_map.c src/parsing/get_bot_info.c

LIB_DIR = ../libft/

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIB_DIR) all
	$(CC) $(FLAGS) $(OBJ) -o $@ -L$(LIB_DIR) -lft -lncurses
	@echo "corewar done."

%.o: %.c
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	@make clean -C $(LIB_DIR)
	$(RM) $(OBJ)

fclean: clean
	@make fclean -C $(LIB_DIR)
	$(RM) $(NAME)

re: fclean all
