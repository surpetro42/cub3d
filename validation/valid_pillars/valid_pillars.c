/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_pillars.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:15:48 by surpetro          #+#    #+#             */
/*   Updated: 2024/12/30 21:23:12 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	no_so_we_ea(char *line, int i, int y)
{
	if (y == 0 && (line[i] == 'N' && line[i + 1] == 'O'))
		return (1);
	else if (y == 1 && (line[i] == 'S' && line[i + 1] == 'O'))
		return (1);
	else if (y == 2 && (line[i] == 'W' && line[i + 1] == 'E'))
		return (1);
	else if (y == 3 && (line[i] == 'E' && line[i + 1] == 'A'))
		return (1);
	else
		return (0);
}

int	check_side(char *line, int y)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] <= 32)
			i++;
		else if(no_so_we_ea(line, i, y))
			break;
		else
		 	return (0);
	}
	printf("%c\n", line[i]);
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

int	inspect_line_pillar(char **map)
{
	int	i;

	i = 0;
	while(map[i] && i <= 3)
	{
		if(check_side(map[i], i) == 0)
			return 0;
		i++;
	}
	return 1;
}
