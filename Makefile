NAME = fdf

GREEN = \033[32m
RED = \033[31m
RESET = \033[0m

LIBFT = libft/libft.a
MLX_FOLDER = minilibx-linux
MLX = $(MLX_FOLDER)/libmlx.a
INC = -I./$(MLX_FOLDER) -I./libft -I./
LIB = -L./$(MLX_FOLDER) -L/usr/lib -lmlx -lXext -lX11 -lm -lz -L./libft/ -lft

FLAGS = -Wall -Wextra -Werror -g

SOURCES = \
        main.c \
		points.c \
		map_parser.c \
		event_hooks.c \
		mlx_img_utils.c

OBJDIR = obj
OBJS = $(addprefix $(OBJDIR)/, $(SOURCES:.c=.o))
$(NAME): $(LIBFT) $(MLX) $(OBJS)
	@echo "$(GREEN)Compiling $(NAME)...$(RESET)"
	@cc $(FLAGS) $(OBJS) -o $(NAME) $(INC) $(LIB)
	@echo "$(GREEN)Compilation finished successfully!$(RESET)"

all: $(NAME)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: src/%.c | $(OBJDIR)
	@echo "$(GREEN)Compiling $<...$(RESET)"
	@cc $(FLAGS) $(INC) -c $< -o $@

$(LIBFT):
	@echo "$(GREEN)Building Libft...$(RESET)"
	@make -s -C libft all

$(MLX):
	@echo "$(GREEN)Building minilibx...$(RESET)"
	@make -s -C $(MLX_FOLDER) all

clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@rm -rf $(OBJDIR)

fclean: clean
	@echo "$(RED)Cleaning all...$(RESET)"
	@rm -f $(NAME)
	@make -s -C $(MLX_FOLDER) clean
	@make -s -C libft fclean

re: fclean all

norm:
	norminette $(SOURCES) libft so_long.h

.PHONY: all clean fclean re
