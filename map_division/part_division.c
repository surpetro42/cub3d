/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part_division.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 09:49:36 by kali              #+#    #+#             */
/*   Updated: 2025/01/02 15:08:56 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	wall_img(t_var *var)
{
    int i;
	int l;
	int wall;

	i = 0;
	wall = 0;
	var->wall_img = (char **)malloc((4 + 1) * sizeof(char *));
	if (!var->wall_img)
		return (0);
	while (var->map && var->map[i] && wall <= 3)
	{
		l = 0;
		while (var->map[i][l])
		{
			if (var->map[i][l] > 32)
				break;
			l++;
        }
		if(var->map[i][l] > 32)
		{
			var->wall_img[wall] = ft_strdup(var->map[i]);
			if (!var->wall_img[wall])
				return (0);
			wall++;
		}
		i++;
	}
	var->wall_img[wall] = NULL;
	return (i);
}

int color_part(t_var *var, int i)
{
	int l;
	int str;

	str = 0;
	var->color_format = (char **)malloc((2 + 1) * sizeof(char *));
	if (!var->color_format)
		return (0);
	while (var->map && var->map[i] && str <= 1)
	{
		l = 0;
		while (var->map[i][l])
		{
			if (var->map[i][l] > 32)
				break;
			l++;
        }
		if(var->map[i][l] > 32)
		{
			var->color_format[str] = ft_strdup(var->map[i]);
			if (!var->color_format[str])
				return (0);
			str++;
		}
		i++;
	}
	var->color_format[str] = NULL;
	return (i);
}

int	len_y(char **map, int i)
{
	int count;

	count = 0;
	while (map && map[i])
	{
		count++;
		i++;
	}
	return (count);
}

int	map_part(t_var *var, int i)
{
	int l;
	int len_y_map = 0;

	len_y_map = len_y(var->map, i);
	var->map_part = (char **)malloc((len_y_map + 1) * sizeof(char *));
	if (!var->map_part)
		return (0);
	len_y_map = 0;
	while (var->map && var->map[i])
	{
		l = 0;
		while (var->map[i][l])
		{
			if (var->map[i][l] > 32)
				break;
			l++;
        }
		if(var->map[i][l] > 32)
		{
			var->map_part[len_y_map] = ft_strdup(var->map[i]);
			if (!var->map_part[len_y_map])
				return (0);
			len_y_map++;
		}
		i++;
	}
	var->map_part[len_y_map] = NULL;
	return (i);
}

int	division_map(t_var *var)
{
	int	i;

	i = wall_img(var);
	if (i == 0)
		return (0);
	i = color_part(var, i);
	if (i == 0)
		return (0);
	i = map_part(var, i);
	if (i == 0)
		return (0);
	return (1);
}