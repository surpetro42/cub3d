#ifndef CUB3D_H
# define CUB3D_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line/get_next_line.h"

// 			utils
size_t	ft_strlen(const char *s);
int		ft_strcmp(char *s1, char *s2);
int		inspect_line_pillar(char **map);
char	**ft_split(char const *s, char c);
#endif