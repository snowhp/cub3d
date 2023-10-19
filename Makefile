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
CFLAGS = -Wall -Werror -Wextra -g3
RM = rm -rf

ifdef DEBUG
	CFLAGS += -g -fsanitize=address
endif

OS = $(shell uname)
MLX_LINUX = mlx_linux
MLX_MACOS = mlx_macos

ifeq ($(OS), Darwin)
    MLX = $(MLX_MACOS)
    MLXFLAGS = -L ./$(MLX) -lmlx -framework OpenGL -framework AppKit -lm
else
    MLX = $(MLX_LINUX)
    MLXFLAGS = -L ./$(MLX) -lmlx -lm -lX11 -lXext
endif

NAME = cub3D
LIBFT = ./libft/libft.a
INCLUDES = includes

SRC = 	check_map.c colors.c error_msg.c initialization.c map_reading.c parsing.c position_map.c textures.c utils.c get_player_position.c imag_to_xpm.c projection.c projection_utils.c directions.c projections_textures.c control_keys.c moves.c moves2.c minimap.c

SRC-OBJ = $(SRC:.c=.o)

MINILIBX_PATH = $(MLX)

all: $(NAME)

$(LIBFT):
	@echo "[$(CYAN)Compiling$(RESET)] $(GREEN)libft$(RESET)"
	@$(MAKE) -s -C ./libft

$(MINILIBX_PATH)/libmlx.a:
	@echo "[$(CYAN)Compiling$(RESET)] $(GREEN)MiniLibX$(RESET)"
	@$(MAKE) -s -C $(MINILIBX_PATH)

$(NAME): $(SRC-OBJ) $(LIBFT) $(MINILIBX_PATH)/libmlx.a
	@echo "[$(CYAN)Linking$(RESET)] $(GREEN)all$(RESET)"
	@$(CC) $(CFLAGS) $(SRC-OBJ) main.c $(LIBFT) $(MINILIBX_PATH)/libmlx.a -lm -lX11 -lXext -o $(NAME) -I $(INCLUDES) $(LIBS) $(MLXFLAGS)
	@echo "[$(GREEN)Done$(RESET)]"

%.o: %.c
	@echo "[$(CYAN)Compiling$(RESET)] $(GREEN)$<$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDES)

clean:
	@echo "[$(RED)Cleaned$(RESET)]"
	@make -s clean -C ./libft
	@make -s clean -C ./mlx_macos
	@$(RM) $(SRC-OBJ)
	@$(RM) $(MINILIBX_PATH)/libmlx.dylib

debug: $(SRC-OBJ) $(LIBFT) $(MINILIBX_PATH)/libmlx.a
	$(CC) $(CFLAGS) -g main.c $(SRC) $(LIBFT) $(MINILIBX_PATH)/libmlx.a -lm -lX11 -lXext -o $(NAME)

fclean: clean
	@echo "[$(RED)Cleaned even better$(RESET)] $(GREEN)$(RESET)"
	@make -s fclean -C ./libft
	@$(RM) $(NAME)

re: fclean all

MAP = maps/no_map.cub

# Define o comando do Valgrind
VALGRIND_CMD = valgrind --leak-check=full --show-leak-kinds=all --log-file=output.log

# Alvo para verificar vazamentos de memória
leaks:
	@echo "Checking memory leaks..."
	$(VALGRIND_CMD) ./$(NAME) $(MAP)
