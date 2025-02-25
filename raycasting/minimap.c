/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:43:50 by surpetro          #+#    #+#             */
/*   Updated: 2025/02/25 12:46:30 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_square(t_var *var, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < TILE_SIZE)
	{
		j = 0;
		while (j < TILE_SIZE)
		{
			my_mlx_pixel_put(&var->img, y + i, x + j, color);
			j++;
		}
		i++;
	}
}

int	draw_minimap(t_var *var)
{
	int	x;
	int	y;

	y = 0;
	while (var->map_part[y])
	{
		x = 0;
		while (var->map_part[y][x])
		{
			if (var->map_part[y][x] == '1')
				draw_square(var, y * TILE_SIZE, x * TILE_SIZE, 0xFFFFFF);
			else if (var->map_part[y][x] == '0')
				draw_square(var, y * TILE_SIZE, x * TILE_SIZE, 0x000000);
			else if (var->map_part[y][x] == 'D')
				draw_square(var, y * TILE_SIZE, x * TILE_SIZE, 0xFF0000);
			else if (var->map_part[y][x] == 'O')
				draw_square(var, y * TILE_SIZE, x * TILE_SIZE, 0x008000);
			x++;
		}
		y++;
	}
	draw_square(var, (int)(var->user.pos_x * TILE_SIZE),
		(int)(var->user.pos_y * TILE_SIZE), 0x0000FF);
	return (0);
}
