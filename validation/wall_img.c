/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 04:45:35 by kali              #+#    #+#             */
/*   Updated: 2025/01/27 09:04:20 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	format_img(char *line, int i)
{
	int		fd;

	while (line[i])
	{
		if (line[i + 4] == '\0')
			break;
		i++;
	}
	if (ft_strcmp(&line[i], ".xpm") == 0)
	{
		while (i > 0)
		{
			if (line[i - 1] <= 32)
				break;
			i--;
		}
		printf("%s\n", &line[i]);
		fd = open(&line[i], O_RDWR);
		printf("%d\n", fd);
		if (fd > 2)
			return (1);	
	}
	// printf("!!!!!!!!!!\n");
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
			if (format_img(var->map[i], 0) == 1)
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
	return (1);
}
