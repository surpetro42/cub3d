/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 04:45:35 by kali              #+#    #+#             */
/*   Updated: 2025/01/29 05:19:27 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	format_img(char *line, int i)
{
	int	fd;

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
		fd = open(&line[i], O_RDWR);
		if (fd > 2)
			return (1);	
	}
	return (0);
}


int	control_sides(char *line, int wall)
{
	if (line[0] == 'N' && line[1] == 'O'
		&& (line[2] == ' ' || line[2] == '\n') && wall == 0)
		return (1);
	else if (line[0] == 'S' && line[1] == 'O'
		&& (line[2] == ' ' || line[2] == '\n') && wall == 1)
		return (1);
	else if (line[0] == 'W' && line[1] == 'E'
		&& (line[2] == ' ' || line[2] == '\n') && wall == 2)
		return (1);
	else if (line[0] == 'E' && line[1] == 'A'
		&& (line[2] == ' ' || line[2] == '\n') && wall == 3)
		return (1);
	else
		return (0);
}

int	line_validation(t_var *var, int wall, int i)
{
	while (var->map && var->map[i] && wall <= 3)
	{
		if (control_sides(var->map[i], wall) == 1)
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

// int	inspect_x(char *line1, char *line2)
// {
// 	printf("line1 == %s\nline2 == %s\n", line1, line2);
// 	if (line1[0] == line2[0] && line1[1] == line2[1])
// 		return (0);
// 	printf("!!!!!!!!!!!!!!!!!!!!\n");
// 	return (1);
// }

// int	inspect(t_var *var, char *line)
// {
// 	int i;

// 	i = 0;
// 	while (var->wall_img[i])
// 	{
// 		if (inspect_x(var->wall_img[i], line) == 0)
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }

// int	recurring_img_line(t_var *var, char **wall_img)
// {
// 	int	i;

// 	i = 0;
// 	while (wall_img[i])
// 	{
// 		if (inspect(var, wall_img[i]) == 0)
// 			return (1);
// 		i++;
// 	}
// 	return (1);
// }

int	wall_img(t_var *var)
{
	int 	wall;

	wall = 0;
	var->wall_img = (char **)malloc(sizeof(char *) * (4 + 1));
	if (!var->wall_img)
		return (0);
	if (line_validation(var, wall, 0) != 4)
		return (0);
	// if (recurring_img_line(var, var->wall_img) == 0)
	// 	return (0);
	return (1);
}
