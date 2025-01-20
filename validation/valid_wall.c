/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 10:10:37 by kali              #+#    #+#             */
/*   Updated: 2025/01/20 08:00:01 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	format_img(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i + 4] == '\0')
			break;
		i++;
	}
	if (ft_strcmp(&line[i], ".xpm") == 0)
		return (1);
	return (0);
}

int	control_sides(char *line)
{
	if ((line[0] == 'N' && line[1] == 'O'
		&& (line[2] == ' ' || line[2] == '\n')) )
		return (1);
	else if (line[0] == 'S' && line[1] == 'O'
		&& (line[2] == ' ' || line[2] == '\n'))
		return (1);
	else if (line[0] == 'W' && line[1] == 'E'
		&& (line[2] == ' ' || line[2] == '\n'))
		return (1);
	else if (line[0] == 'E' && line[1] == 'A'
		&& (line[2] == ' ' || line[2] == '\n'))
		return (1);
	else
	{
		return (0);
	}
}

int	line_validation(t_var *var, int wall, int i)
{
	while (var->map && var->map[i] && wall <= 3)
	{
		// if (ft_strcmp(var->map[i], "\0") == 0)
			// i++;
		if (control_sides(var->map[i]) == 1)
		{
			if (quality_element(var->map[i], 0) == 0)
			{
				printf("The number of items in the img row is not true\n");
				break;
			}
			if (format_img(var->map[i]) == 1)
			{
				var->wall_img[wall] = ft_strdup(var->map[i]);
				wall++;
			}
			else
			{
				printf("The image format is incorrect.\n");
				break;
			}
		}
		i++;
	}
	var->wall_img[wall] = NULL;
	return (wall);
}

int	wall_img(t_var *var)
{
	int 	wall;

	wall = 0;
	var->wall_img = (char **)malloc(sizeof(char *) * (4 + 1));
	if (!var->wall_img)
		return (0);
	if (line_validation(var, wall, 0) != 4)
		return (0);
	int x = 0;

	while (var->wall_img[x])
	{
		printf("---> %s\n",var->wall_img[x]);
		x++;
	}
	return (1);
}
