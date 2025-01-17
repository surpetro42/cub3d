#ifndef CUB3D_H
# define CUB3D_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line/get_next_line.h"

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
	char	*line;
	char 	**map;
	char	**wall_img;
	char	**rgb_format;
	char	**map_part;
	t_color	number;
}	t_var;

/* --------- *** free_cub3d *** --------- */
void		free_var(t_var *var);
void		free_double_pointer(char **var);

/* --------- *** utils *** --------- */
size_t		ft_strlen(const char *s);
int			ft_strcmp(char *s1, char *s2);
char		**ft_split(char const *s, char c);
char		*ft_strdup(const char *s1);
char		*ft_substr(const char *s, unsigned int start, size_t len);
int			ft_atoi(const char *str);
char		*ft_strtrim(const char *s1, const char *set);

/* --------- *** validation *** --------- */
int			validation(t_var *var);
int			wall_img(t_var *var);
int			rgb_part(t_var *var);
int			map_part(t_var *var);
/* --------- validation_utils --------- */
int			quantity_comma(char *line);
void		assings(t_var *var, int i, int buff);
int			number_given_colors(t_var *var);
int			valid_string(char **str);
int			quality_element(char *line, int i);
int			initialization_map_part(t_var *var, int i);
int			count_separator(t_var *var, int i);
int			valid_newline_map(t_var *var);
int			len_map(char **map);
int			first_last_line(char *s1, char *s2);

// initialization_var
void		initialization_var(t_var *var);


#endif