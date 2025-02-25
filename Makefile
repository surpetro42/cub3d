NAME    = cub3D
CC      = cc

CFLAGS = -Wall -Wextra -Werror -I mlx -g3 -fsanitize=address

SRCS    = cub3d.c \
          get_next_line/get_next_line.c \
          get_next_line/get_next_line_utils.c \
          utils/utils_0.c \
          utils/utils_1.c \
		  utils/initialization_var.c \
		  validation/wall_img.c \
		  validation/rgb_part.c \
		  validation/map.c \
		  validation/validation.c \
		  validation/utils_validation/utils_map_0.c \
		  validation/utils_validation/utils_map_1.c \
		  validation/utils_validation/utils_rgb_part_0.c \
		  validation/utils_validation/utils_rgb_part_1.c \
		  validation/utils_validation/utils_wall_img_0.c \
		  raycasting/start_game.c \
		  raycasting/player_pos.c \
		  raycasting/textures.c \
		  raycasting/image.c \
		  raycasting/texture_color_pixel.c \
		  raycasting/raycasting.c \
		  raycasting/anim.c \
		  raycasting/calculate.c \
		  raycasting/move.c \
		  raycasting/view_and_door.c \
		  raycasting/minimap.c \
		  free_cub3d/destroy_image.c \
		  free_cub3d/free_var.c

OBJ_DIR = obj
OBJS    = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

HEADERS =   get_next_line/get_next_line.h \
			cub3d.h

#MLX = -Lmlx -lmlx -lXext -lX11 -lm -lz
MLX = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(MLX)


$(OBJ_DIR)/%.o : %.c Makefile $(HEADERS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
