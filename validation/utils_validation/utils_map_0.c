/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map_0.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:27:10 by surpetro          #+#    #+#             */
/*   Updated: 2025/02/24 20:39:33 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	first_last_line(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1 && s1[i])
	{
		if (!(s1[i] == '1' || s1[i] == ' ' || s1[i] == '\t'))
			return (0);
		i++;
	}
	i = 0;
	while (s2 && s2[i])
	{
		if (!(s2[i] == '1' || s2[i] == ' ' || s2[i] == '\t'))
			return (0);
		i++;
	}
	return (1);
}

int	len_line_map(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str && str[i])
	{
		if (str[i] == '\t')
			count += 4;
		count++;
		i++;
	}
	return (count);
}

void	replace_tab_with_spaces(char *res, int *buff)
{
	int	cycle_four;

	cycle_four = 0;
	while (cycle_four < 4)
	{
		res[*buff] = ' ';
		(*buff)++;
		cycle_four++;
	}
}

char	*assigns_elem_mappart(char *map_line, int i, int buff)
{
	char	*res;

	res = NULL;
	res = malloc(sizeof(char *) * (len_line_map(map_line) + 1));
	if (!res)
		return (NULL);
	while (map_line && map_line[i])
	{
		if (map_line[i] == '\t')
		{
			i++;
			replace_tab_with_spaces(res, &buff);
		}
		if (map_line[i])
		{
			res[buff] = map_line[i];
			i++;
		}
		buff++;
	}
	res[buff] = '\0';
	return (res);
}

int	initialization_map_part(t_var *var, int i)
{
	int	elem;

	elem = 0;
	while (var->map && var->map[i])
	{
		var->map_part[elem] = assigns_elem_mappart(var->map[i], 0, 0);
		if (!var->map_part[elem])
		{
			var->map_part[elem] = NULL;
			return (0);
		}
		elem++;
		i++;
	}
	var->map_part[elem] = NULL;
	return (1);
}
