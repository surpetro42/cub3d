/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 10:10:37 by kali              #+#    #+#             */
/*   Updated: 2025/01/06 11:04:24 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	format_img(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i + 3] == '\0' || line[i + 3] == '\n')
			break;
		i++;
	}
	if (ft_strcmp(&line[i], "xpm") == 0)
		return (1);
	return (0);
}

int	authenticity(char *line, int i, int wall)
{
	if (line && wall == 0 && (line[i] == 'N' && line[i + 1] == 'O'))
		return (1);			
	else if (line && wall == 1 && (line[i] == 'S' && line[i + 1] == 'O'))
		return (1);
	else if (line && wall == 2 && (line[i] == 'W' && line[i + 1] == 'E'))
		return (1);
	else if (line && wall == 3 && (line[i] == 'E' && line[i + 1] == 'A'))
		return (1);
	else
		return (0);
}

int	wall_img(t_var *var)
{
	int		i;
	int		l;
	int 	wall;

	i = 0;
	wall = 0;
	var->wall_img = (char **)malloc(sizeof(char *) * (4 + 1));
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
		if (var->map[i][l] > 32)
		{
			if (authenticity(var->map[i], l, wall) == 1)
			{
				if (format_img(var->map[i]) == 1)
				{
					var->wall_img[wall] = ft_strdup(var->map[i]);
					wall++;
				}
				else
					break;				
			}
		}
		i++;
	}
	if (wall != 4)
	{
		var->wall_img[wall] = NULL;
		return (0);
	}
	var->wall_img[wall] = NULL;
	return (1);
}

