/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:53:03 by surpetro          #+#    #+#             */
/*   Updated: 2025/03/02 12:51:46 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	check_doors(t_var *var, int i, int l)
{
	if (var->map_part[i][l] == 'D')
	{
		if (check_map_elem_door(var->map_part[i - 1],
				var->map_part[i + 1], var->map_part[i], l) == 0)
		{
			printf("ERROR\nThe doors are positioned incorrectly\n");
			return (0);
		}
	}
	return (1);
}

int	check_map_elements(t_var *var, int i, int l)
{
	if (var->map_part[i][l] == '0' || var->map_part[i][l] == 'N'
		|| var->map_part[i][l] == 'S' || var->map_part[i][l] == 'W'
		|| var->map_part[i][l] == 'E')
	{
		if (var->map_part[i + 1] == NULL || i == 0
			|| check_map_elem(var->map_part[i - 1],
				var->map_part[i + 1], var->map_part[i], l) == 0)
		{
			printf("ERROR\nThe map is not properly closed\n");
			return (0);
		}
	}
	return (1);
}

int	search_mape_line_elem(t_var *var, int i)
{
	while (var->map[i])
	{
		if (ft_strcmp(var->map[i], var->rgb_format[1]) == 0)
		{
			i++;
			break ;
		}
		i++;
	}
	return (i);
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
