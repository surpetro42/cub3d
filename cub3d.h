#ifndef CUB3D_H
# define CUB3D_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line/get_next_line.h"

typedef struct s_var
{
	char	*line;
	char 	**map;
	char	**wall_img;
	char	**color_format;
	char	**map_part;
}	t_var;

/* --------- *** free_cub3d *** --------- */
void		free_var(t_var *var);

/* --------- *** map_division *** --------- */
int			division_map(t_var *var);
int			wall_img(t_var *var);

/* --------- *** utils *** --------- */
// libft_utils_0
size_t		ft_strlen(const char *s);
int			ft_strcmp(char *s1, char *s2);
char		**ft_split(char const *s, char c);
char		*ft_strdup(const char *s1);
char		*ft_substr(const char *s, unsigned int start, size_t len);

// initialization_var
void	initialization_var(t_var *var);


#endif