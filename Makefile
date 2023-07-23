
RESET	= \033[0m
BLACK 	= \033[1;30m
RED 	= \033[1;31m
GREEN 	= \033[1;32m
YELLOW 	= \033[1;33m
BLUE	= \033[1;34m
PURPLE 	= \033[1;35m
CYAN 	= \033[1;36m
WHITE 	= \033[1;37m

CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf

ifdef DEBUG
	CFLAGS += -g -fsanitize=address
endif

NAME = cub3D
LIBFT = ./libft/libft.a
INCLUDES = includes
LIBS = -ltermcap -lreadline -lncurses

SRC = 	check_map.c colors.c error_msg.c initialization.c map_reading.c parsing.c position_map.c textures.c utils.c

SRC-OBJ = $(SRC:.c=.o)

all: $(NAME)

$(LIBFT):
	@echo "[$(CYAN)Compiling$(RESET)] $(GREEN)libft$(RESET)"
	@$(MAKE) -s -C ./libft

$(NAME): $(SRC-OBJ) $(LIBFT)
	@echo "[$(CYAN)Linking$(RESET)] $(GREEN)all$(RESET)"
	@$(CC) $(CFLAGS) $(SRC-OBJ) main.c $(LIBFT) -o $(NAME) -I $(INCLUDES) $(LIBS)
	
	@echo "[$(GREEN)Done$(RESET)]"
	
%.o: %.c
	@echo "[$(CYAN)Compiling$(RESET)] $(GREEN)$<$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDES)

clean:
	@echo "[$(RED)Cleaned$(RESET)]"
	@make -s clean -C ./libft
	@$(RM) $(SRC-OBJ)

fclean: clean
	@echo "[$(RED)Cleaned even better$(RESET)] $(GREEN)$(RESET)"
	@make -s fclean -C ./libft
	@$(RM) $(NAME)

re: fclean all

run: re
	@clear
	@echo "[$(RED)running$(RESET)] $(GREEN)$(RESET)"
	@./minishell

valgrind: re
	@clear
	@echo "[$(RED)looking for valgrind leaks$(RESET)] $(GREEN)$(RESET)"
	@sleep 1
	@valgrind -s --leak-check=full --show-leak-kinds=all --log-file=output.log ./minishell