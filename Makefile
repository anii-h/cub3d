NAME = cub3d

CC = cc
C_FLAGS = -Wall -Wextra -Werror
FSANITIZE_FLAGS = -fsanitize=address -fsanitize=undefined -g3
VALGRIND_FLAGS = -g3

SRC_DIR = src
INC_DIR = include
LIB_DIR = lib
MLX_DIR = $(LIB_DIR)/minilibx-linux
LIBFT_DIR = $(LIB_DIR)/libft

BIN_DIR = bin
BUILD_DIR = build

SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/init/init_mlx.c

OBJS = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRCS))

HEADER = $(INC_DIR)/cub3d.h

INC_FLAGS = -I$(INC_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR)

LIBFT = $(LIBFT_DIR)/libft.a
MLX = $(MLX_DIR)/libmlx.a

LIBFT_FLAGS = -L$(LIBFT_DIR) -lft
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

all: $(BIN_DIR)/$(NAME)

fsanitize: C_FLAGS += $(FSANITIZE_FLAGS)
fsanitize: fclean all

valgrind: C_FLAGS += $(VALGRIND_FLAGS)
valgrind: fclean all

$(BIN_DIR)/$(NAME): $(OBJS) $(LIBFT) $(MLX) | $(BIN_DIR)
	$(CC) $(C_FLAGS) $(OBJS) $(LIBFT_FLAGS) $(MLX_FLAGS) -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER)
	@mkdir -p $(dir $@)
	$(CC) $(C_FLAGS) $(INC_FLAGS) -c $< -o $@

$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) all

$(MLX):
	@$(MAKE) -C $(MLX_DIR)

clean:
	@$(MAKE) -C $(MLX_DIR) clean
	@$(MAKE) -C $(LIBFT_DIR) clean
	@rm -rf $(BUILD_DIR)/*
	@rm -rf $(BIN_DIR)/*

fclean: clean
	@$(MAKE) -C $(MLX_DIR) clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@rm -rf $(BIN_DIR)/
	@rm -rf $(BUILD_DIR)/

re: fclean all

.PHONY: all clean fclean re fsanitize valgrind