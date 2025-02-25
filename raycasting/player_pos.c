/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:43:55 by surpetro          #+#    #+#             */
/*   Updated: 2025/02/25 12:48:31 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_dir(t_var *var, char c)
{
	var->user.dir_x = 0;
	var->user.dir_y = 0;
	var->user.plane_x = 0;
	var->user.plane_y = 0;
	if (c == 'N')
	{
		var->user.dir_x = -1;
		var->user.plane_y = 0.66;
	}
	else if (c == 'S')
	{
		var->user.dir_x = 1;
		var->user.plane_y = -0.66;
	}
	else if (c == 'E')
	{
		var->user.dir_y = 1;
		var->user.plane_x = 0.66;
	}
	else if (c == 'W')
	{
		var->user.dir_y = -1;
		var->user.plane_x = -0.66;
	}
}

void	got_player_pos(t_var *var)
{
	int		j;
	int		i;
	char	**map;

	map = var->map_part;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'E' || map[i][j] == 'W')
			{
				var->user.pos_y = j + 0.5;
				var->user.pos_x = i + 0.5;
				set_dir(var, map[i][j]);
				var->map_part[i][j] = '0';
				return ;
			}
			j++;
		}
		i++;
	}
}
