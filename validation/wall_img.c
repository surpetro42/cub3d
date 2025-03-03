/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:27:07 by surpetro          #+#    #+#             */
/*   Updated: 2025/03/02 15:08:39 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	format_img(char *line, int i)
{
	int	fd;

	while (line[i])
	{
		if (line[i + 4] == '\0')
			break ;
		i++;
	}
	if (ft_strcmp(&line[i], ".xpm") == 0)
	{
		while (i > 0)
		{
			if (line[i - 1] <= 32)
				break ;
			i--;
		}
		fd = open(&line[i], O_RDWR);
		if (fd > 2)
			return (1);
	}
	return (0);
}

int	control_sides(char *line, int x)
{
	if (line[0] == 'W' && line[1] == 'E'
		&& (line[2] == ' ' || line[2] == '\n') && x == 0)
		return (1);
	else if (line[0] == 'S' && line[1] == 'O'
		&& (line[2] == ' ' || line[2] == '\n') && x == 1)
		return (1);
	else if (line[0] == 'N' && line[1] == 'O'
		&& (line[2] == ' ' || line[2] == '\n') && x == 2)
		return (1);
	else if (line[0] == 'E' && line[1] == 'A'
		&& (line[2] == ' ' || line[2] == '\n') && x == 3)
		return (1);
	else
		return (0);
}

int	line_validation(t_var *var, int wall, int i)
{
	static int	x;

	while (var->map && var->map[i] && wall <= 3)
	{
		if (control_sides(var->map[i], x) == 1)
		{	
			if (line_validation_error(var, i) == 0)
				break ;
			if (format_img(var->map[i], 0) == 1)
			{
				var->wall_img[wall] = ft_strdup(var->map[i]);
				wall++;
				x++;
			}
			else
			{
				printf("ERROR\nThe image format is incorrect.\n");
				break ;
			}
			i = -1;
		}
		i++;
	}
	var->wall_img[wall] = NULL;
	return (wall);
}

int	wall_img(t_var *var)
{
	int	wall;

	wall = 0;
	var->wall_img = (char **)malloc(sizeof(char *) * (4 + 1));
	if (!var->wall_img)
		return (0);
	if (line_validation(var, wall, 0) != 4)
	{
		printf("ERROR\nYou have the wrong format in the image lines.\n");
		return (0);
	}
	end_result(var->wall_img);
	return (1);
}
