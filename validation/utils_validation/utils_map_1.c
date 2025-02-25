/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:27:10 by surpetro          #+#    #+#             */
/*   Updated: 2025/02/24 20:39:24 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

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

int	search_mape_line(t_var *var, int i, int l)
{
	i = search_mape_line_elem(var, i);
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
