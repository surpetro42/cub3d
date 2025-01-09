NAME    = cub3d
CC      = cc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

SRCS    = cub3d.c \
          get_next_line/get_next_line.c \
          get_next_line/get_next_line_utils.c \
          utils/libft_utils_0.c \
		  utils/initialization_var.c \
		  validation/valid_wall.c \
		  validation/color_part.c \
		  validation/validation.c \
		  validation/validation_utils/color_part_utils.c \
		  free_cub3d/free_var.c

OBJ_DIR = obj
OBJS    = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

# MLX = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX) -o $(NAME)


$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
