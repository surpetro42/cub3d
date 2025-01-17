/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 12:38:17 by kali              #+#    #+#             */
/*   Updated: 2025/01/17 11:21:47 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_elem_line_map(char elem_map)
{
	if (!(elem_map && (elem_map == '1' || elem_map == '0' || elem_map == 'N'
		|| elem_map == 'S' || elem_map == 'W' || elem_map == 'E' || elem_map == 'D')))
		return (0);
	return (1);
}

int	check_map_elem_zero(char *previous, char *next, char *current, int l)
{
	int	res;
	int	len;

	res = 1;
	len = ft_strlen(current);
	if ((l == 0 || l == len) ||
		(((size_t)l > ft_strlen(previous)) || ((size_t)l > ft_strlen(next))))
		return (0);
	if (previous[l] && check_elem_line_map(previous[l]) == 0)
		res = 0;
	if (check_elem_line_map(next[l]) == 0)
		res = 0;
	if (check_elem_line_map(current[l - 1]) == 0)
		res = 0;
	if (check_elem_line_map(current[l + 1]) == 0)
		res = 0;
	return (res);
}


int	closed_card(t_var *var, int i)
{
	int	l;

	while (var->map_part[i])
	{
		l = 0;
		while (var->map_part[i][l])
		{
			if (var->map_part[i][l] == '0')
			{
				if (var->map_part[i + 1] == NULL || i == 0 || check_map_elem_zero(var->map_part[i - 1],
					var->map_part[i + 1], var->map_part[i], l) == 0)
				{
					printf("The map is not properly close\n");
					return (0);
				}
			}
			l++;
		}
		i++;
	}
	return (1);
}

int	map_part(t_var *var)
{
	if (valid_newline_map(var) == 0)
	{
		printf("Map division.\n");
		return (0);
	}
	if (count_separator(var, 6) == 0 || initialization_map_part(var, 6) == 0)
		return (0);
	if (closed_card(var, 0) == 0)
		return (0);	
	return (1);
}