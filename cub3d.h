/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:36:13 by surpetro          #+#    #+#             */
/*   Updated: 2025/03/02 14:21:02 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include <string.h>
# include <math.h>
# include "get_next_line/get_next_line.h"
# include "mlx/mlx.h"

# define ESC 53
# define M 46
# define E 14
# define W 13
# define A 0
# define S 1
# define D 2
# define LARROW 123
# define RARROW 124

# define AROTATE 0.07
# define MROTATE 0.03
# define WSPEED 0.15
# define SSPEED 0.1
# define ADSPEED 0.12

# define MAP_WIDTH 36
# define MAP_HEIGHT 11
# define TILE_SIZE 10

typedef struct s_img
{
	int		wd;
	int		ht;
	int		endian;
	int		line_length;
	int		bits_per_pixel;
	char	*addr;
	void	*img;
}	t_img;

typedef struct s_raycasting
{
	int		hit;
	int		side;
	double	ray_x;
	double	ray_y;
	double	camera_x;
	double	sdist_x;
	double	sdist_y;
	double	deltadist_x;
	double	deltadist_y;
	double	perp_wall_dist;
}	t_raycasting;

typedef struct s_draw
{
	int		tex_x;
	int		tex_y;
	int		draw_end;
	int		draw_start;
	int		line_height;
	double	step;
	double	tex_pos;
}	t_draw;

typedef struct s_user
{
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_user;

typedef struct s_xpm
{
	void	*ptr;
	void	*win;
}	t_xpm;

typedef struct s_color
{
	int		c_0;
	int		c_1;
	int		c_2;
	int		f_0;
	int		f_1;
	int		f_2;
}	t_color;

typedef struct s_var
{
	int				f_color;
	int				c_color;
	int				map_wd;
	int				map_ht;
	int				hide_map;
	char			*line;
	char			**map;
	char			**wall_img;
	char			**rgb_format;
	char			**map_part;
	t_xpm			mlx;
	t_user			user;
	t_img			img;
	t_img			closedoor;
	t_img			opendoor;
	t_img			sprite[8];
	t_img			*wall;
	t_color			number;
	t_raycasting	ray;
}	t_var;

/* --------- *** free_cub3d *** --------- */
void			free_call(t_var *var, int flag);
void			free_var(t_var *var);
void			free_double_pointer(char **var);

/* --------- *** destroy_image *** --------- */
void			destroy_all_img(t_var *var, int flag);

/* --------- *** utils *** --------- */
size_t			ft_strlen(const char *s);
int				ft_strcmp(char *s1, char *s2);
char			**ft_split(char const *s, char c);
char			*ft_strdup(const char *s1);
char			*ft_substr(const char *s, unsigned int start, size_t len);
int				ft_atoi(const char *str);
char			*ft_strtrim(const char *s1, const char *set);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strtrim_free(char *s1, const char *set);

/* --------- *** validation *** --------- */
int				validation(t_var *var);
int				wall_img(t_var *var);
int				rgb_part(t_var *var, int i, int rgb, int ngc);
int				map_part(t_var *var);
/* --------- validation_utils --------- */
int				quantity_comma(char *line);
void			assings(t_var *var, int i, int buff);
int				number_given_colors(t_var *var);
int				valid_string(char **str);
int				quality_element(char *line, int i);
int				initialization_map_part(t_var *var, int i);
int				count_separator(t_var *var, int i);
int				valid_newline_map(t_var *var);
int				len_map(char **map);
int				first_last_line(char *s1, char *s2);
int				search_mape_line(t_var *var, int i, int l);
int				search_mape_line_elem(t_var *var, int i);
int				initialization_number(char **str, t_var *var, char c);
int				cf_number(char *line, t_var *var, char c);
int				error_valid_string(t_var *var);
int				validation_rgb(t_var *var, int i);
int				cf(char *line, int i, int count);
void			end_result(char **wall_img);
int				line_validation_error(t_var *var, int i);
int				check_map_elements(t_var *var, int i, int l);
int				check_doors(t_var *var, int i, int l);
int				checking_rgb_line(char *str, int i);
int				check_map_elem(char *previous,
					char *next, char *current, int l);
int				check_map_elem_door(char *previous,
					char *next, char *current, int l);
int				error_valid_string(t_var *var);

// initialization_var
void			initialization_var(t_var *var);

/* --------- *** RAYCASTING *** --------- */

//start_game
void			init_img_var(t_var *var);
void			game_start(t_var var);

//player_pos
void			got_player_pos(t_var *vars);

//textures
void			get_door(t_img *door, t_var *var, char *path);
void			set_sprite_textures(t_var *var);
void			get_sprite_textures(t_var *var);
void			set_wall_textures(t_var *var);
void			get_wall__textures(t_var *var);

//image
void			create_image(t_var *var);

//texture_color_pixel
int				create_trgb(int t, int r, int g, int b);
unsigned int	my_mlx_color_taker(t_img *data, int j, int i);
void			my_mlx_pixel_put(t_img *img, int x, int y, int color);
t_img			*choose_texture(t_var *var);
void			draw_texture(t_var *var, int x, int tex_x);

//raycasting
void			raycasting(t_var *var);

//anim
void			sprite_anim(t_var *var);

//calculate
void			dda_algorithm(t_var *var);
void			ray_pos(t_var *var, int w);
void			calc_draw_ends(t_var *var, t_draw *tex);
int				calc_texture_x(t_var *var);
void			step_dir(t_var *var);

//move
int				key_press(int key, t_var *var);
void			move_s(t_var *var, double move);
void			move_w(t_var *var, double move);
void			move_right_left(t_var *var, int key, double move);
int				mouse_move(int x, int y, t_var *var);

//view_and_door
int				press(t_var *var);
void			open_close_door(t_var *var);
void			get_dir(t_var *var);
void			rotate_view(t_var *var, double prevdir_x,
					double prevplane_x, double rotate);
void			change_view(t_var *var, int side, double rotate);

//minimap
int				draw_minimap(t_var *var);

#endif