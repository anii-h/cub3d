NAME = cub3d

CC = cc
C_FLAGS = -Wall -Wextra -Werror -I./$(INC_DIR) -fsanitize=address -g3

SRC_DIR = src
INC_DIR = include
LIB_DIR = lib
MLX_DIR = $(LIB_DIR)/minilibx-linux
LIBFT_DIR = $(LIB_DIR)/libft

BIN_DIR = bin
BUILD_DIR = build

SRCS = $(SRC_DIR)/main.c

OBJS = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRCS))

HEADER = $(INC_DIR)/cub3d.h

INC_FLAGS = -I$(INC_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR)

LIBFT = $(LIBFT_DIR)/libft.a
MLX = $(MLX_DIR)/libmlx.a

LIBFT_FLAGS = -L$(LIBFT_DIR) -lft
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11

all: $(BIN_DIR)/$(NAME)

$(BIN_DIR)/$(NAME): $(OBJS) $(LIBFT) $(MLX) | $(BIN_DIR)
	$(CC) $(C_FLAGS) $(OBJS) $(LIBFT_FLAGS) $(MLX_FLAGS) $(INC_FLAGS) -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER) | $(BUILD_DIR)
	$(CC) $(C_FLAGS) $(INC_FLAGS) -c $< -o $@

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) all

$(FT_PRINTF):
	@$(MAKE) -C $(FT_PRINTF_DIR) all

$(GNL):
	@$(MAKE) -C $(GET_NEXT_LINE_DIR) all

$(MLX):
	@$(MAKE) -C $(MLX_DIR)

clean:
	@$(MAKE) -C $(MLX_DIR) clean || true
	@$(MAKE) -C $(LIBFT_DIR) clean || true
	rm -rf $(BUILD_DIR)

fclean: clean
	@$(MAKE) -C $(MLX_DIR) clean || true
	@$(MAKE) -C $(LIBFT_DIR) fclean || true
	rm -f $(BIN_DIR)/$(NAME)

re: fclean all

.PHONY: all clean fclean re