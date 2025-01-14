/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 10:10:37 by kali              #+#    #+#             */
/*   Updated: 2025/01/14 19:04:32 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	format_img(char *line)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_strtrim(line, "\t ");
	while (str[i])
	{
		if (str[i + 4] == '\0')
			break;
		i++;
	}
	if (ft_strcmp(&str[i], ".xpm") == 0)
	{
		free(str);
		return (1);
	}
	free(str);
	return (0);
}

int	control_sides(char *line)
{
	if (line[0] == 'N' && line[1] == 'O')
		return (1);			
	else if (line[0] == 'S' && line[1] == 'O')
		return (1);
	else if (line[0] == 'W' && line[1] == 'E')
		return (1);
	else if (line[0] == 'E' && line[1] == 'A')
		return (1);
	else
		return (0);
}

int	line_validation(t_var *var, int wall, int i)
{
	char	*str;

	str = NULL;
	while (var->map && var->map[i] && wall <= 3)
	{
		str = ft_strtrim(var->map[i], "\t ");
		if (control_sides(str) == 1)
		{
			if (quality_element(str, 0) == 0)
			{
				printf("The number of items in the img row is not true\n");
				free(str);
				break;
			}
			if (format_img(str) == 1)
			{
				var->wall_img[wall] = ft_strdup(str);
				wall++;
			}
			else
			{
				printf("The image format is incorrect.\n");
				free(str);
				break;
			}
		}
		free(str);
		i++;
	}
	var->wall_img[wall] = NULL;
	return wall;
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
