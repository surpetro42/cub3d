/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:27:00 by surpetro          #+#    #+#             */
/*   Updated: 2025/02/27 16:55:26 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_elem_line_map(char elem_map)
{
	if (!(elem_map && (elem_map == '1' || elem_map == '0' || elem_map == 'N'
				|| elem_map == 'S' || elem_map == 'W'
				|| elem_map == 'E' || elem_map == 'D')))
		return (0);
	return (1);
}

int	check_map_elem(char *previous, char *next, char *current, int l)
{
	int	res;
	int	len;

	res = 1;
	len = ft_strlen(current);
	if ((l == 0 || l == len) || (((size_t)l >= ft_strlen(previous))
			|| ((size_t)l >= ft_strlen(next))))
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
			if(var->map_part[i][l] == 'D')
			{
				if (check_map_elem_door(var->map_part[i - 1],
					var->map_part[i + 1], var->map_part[i], l) == 0)
				{
					printf("ERROR\nThe doors are positioned incorrectly\n");
					return (0);
				}
			}
			else if (var->map_part[i][l] == '0' || var->map_part[i][l] == 'N'
				|| var->map_part[i][l] == 'S' || var->map_part[i][l] == 'W'
				|| var->map_part[i][l] == 'E')
			{
				if (var->map_part[i + 1] == NULL || i == 0
					|| check_map_elem(var->map_part[i - 1],
						var->map_part[i + 1], var->map_part[i], l) == 0)
				{
					printf("ERROR\nThe map is not properly close\n");
					return (0);
				}
			}
			l++;
		}
		i++;
	}
	return (1);
}

int	inspect_personage(t_var *var, int i)
{
	int	l;
	int	count;

	count = 0;
	while (var->map_part[i])
	{
		l = 0;
		while (var->map_part[i][l])
		{
			if (var->map_part[i][l] == 'S' || var->map_part[i][l] == 'W'
				|| var->map_part[i][l] == 'E' || var->map_part[i][l] == 'N')
				count++;
			l++;
		}
		i++;
	}
	if (count == 1)
		return (1);
	printf("ERROR\nThe character must be alone.\n");
	return (0);
}

int	map_part(t_var *var)
{
	int	line;

	if (valid_newline_map(var) == 0)
	{
		printf("ERROR\nMap division.\n");
		return (0);
	}
	line = search_mape_line(var, 0, 0);
	if (count_separator(var, line) == 0
		|| initialization_map_part(var, line) == 0)
		return (0);
	if ((inspect_personage(var, 0) == 0) || (closed_card(var, 0) == 0))
		return (0);
	return (1);
}
