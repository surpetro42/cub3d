/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:27:05 by surpetro          #+#    #+#             */
/*   Updated: 2025/02/27 16:53:27 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	valid_map(t_var *var, int i, int l)
{
	while (var->map && var->map[i])
	{
		if (i == 6)
		{
			l = 0;
			while (var->map[i][l])
			{
				if (!(var->map[i][l] == '1' || var->map[i][l] == ' ' || var->map[i][l] == '\t'))
				{
					printf("ERROR\nExtra line in the map\n");
					return (0);
				}
				l++;
			}
		}
		i++;
	}
	return (1);
}

int	validation(t_var *var)
{
	int	i;

	i = wall_img(var);
	if (valid_map(var, 0, 0) == 0)
		return (0);
	if (i == 0)
		return (0);
	i = rgb_part(var, 0, 0, 0);
	if (i == 0)
		return (0);
	i = map_part(var);
	if (i == 0)
		return (0);
	return (1);
}
