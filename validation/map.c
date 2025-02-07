/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 12:38:17 by kali              #+#    #+#             */
/*   Updated: 2025/02/07 02:45:05 by kali             ###   ########.fr       */
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
		(((size_t)l >= ft_strlen(previous)) || ((size_t)l >= ft_strlen(next))))
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
			if (var->map_part[i][l] == '0' || var->map_part[i][l] == 'N'
		|| var->map_part[i][l] == 'S' || var->map_part[i][l] == 'W' || var->map_part[i][l] == 'E')
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

int	search_mape_line(t_var *var)
{
	int	i;
	int	l;

	i = 0;
	while (var->map[i])
	{
		if (ft_strcmp(var->map[i], var->rgb_format[1]) == 0)
		{
			i++;
			break;
		}
		i++;
	}
	while (var->map && var->map[i])
	{
		if (ft_strlen(var->map[i]) != 0)
		{
			l = 0;
			while (var->map[i][l])
			{
				if (var->map[i][l] == '1')
				
					return (i);
				l++;
			}
			if (l > 0)
				return (0);
		}
		i++;
	}
	return (0);
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
	printf("The character must be alone.\n");
	return (0);
}

int	map_part(t_var *var)
{
	int	line;

	if (valid_newline_map(var) == 0)
	{
		printf("Map division.\n");
		return (0);
	}
	line = search_mape_line(var);
	if (count_separator(var, line) == 0 || initialization_map_part(var, line) == 0)
		return (0);
	if ((inspect_personage(var, 0) == 0) || (closed_card(var, 0) == 0))
		return (0);
	return (1);
}