/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map_0.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 07:09:56 by kali              #+#    #+#             */
/*   Updated: 2025/02/07 15:12:51 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	first_last_line(char *s1, char *s2)
{
	int	i;

	i = 0;
	while(s1 && s1[i])
	{
		if (!(s1[i] == '1' || s1[i] == ' ' || s1[i] == '\t'))
			return (0);
		i++;
	}
	i = 0;
	while(s2 && s2[i])
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
		if(str[i] == '\t')
			count += 4;
		count++;
		i++;
	}
	return count;
}

char	*assigns_elem_mappart(char *map_line)
{
	char	*res;
	int		i;
	int		buff;
	int		cycle_to_four;
	
	res = NULL;
	i = 0;
	buff = 0;
	res = malloc(sizeof(char *) * (len_line_map(map_line) + 1));
	if (!res)
		return (NULL);
	while (map_line && map_line[i])
	{
		if (map_line[i] == '\t')
		{
			i++;
			cycle_to_four = 0;
			while (cycle_to_four < 4)
			{
				res[buff] = ' ';
				buff++;
				cycle_to_four++;
			}
		}
		if(map_line[i])
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
	int elem;

	elem = 0;
	while (var->map && var->map[i])
 	{
		var->map_part[elem] = assigns_elem_mappart(var->map[i]);
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

int	count_separator(t_var *var, int i)
{
	int	count;

	count = 0;
	while (var->map && var->map[i])
	{
		count++;
		i++;
	}
	var->map_part = (char **)malloc(sizeof(char *) * (count + 1));
	if (!var->map_part)
		return (0);
	return (1);
}

int	valid_newline_map(t_var *var)
{
	int	i;

	i = 0;
	while (var->line && var->line[i])
		i++;
	while (var->line[i] != ',' && i >= 0)
		i--;
	while (var->line[i] != '\n')
		i++;
	while (var->line[i] != '1')
		i++;
	while (var->line[i])
	{
		if (var->line[i] == '\n' && var->line[i + 1] == '\n')
			return (0);
		i++;
	}
	return (1);
}