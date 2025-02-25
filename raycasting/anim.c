/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:43:42 by surpetro          #+#    #+#             */
/*   Updated: 2025/02/25 12:44:24 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	print_sprite(t_var *var, int i)
{
	int				x;
	int				y;
	int				px;
	int				py;
	unsigned int	color;

	px = 0;
	x = var->img.wd / 2 - var->sprite[i].wd / 2 - 1;
	while (++x < var->img.wd / 2 + var->sprite[i].wd / 2)
	{
		y = var->img.ht - var->sprite[i].ht - 1;
		py = 0;
		while (++y < var->img.ht)
		{
			color = my_mlx_color_taker(&var->sprite[i], px, py);
			if (color == 4278190080)
				color = my_mlx_color_taker(&var->img, x, y);
			my_mlx_pixel_put(&var->img, x, y, color);
			py++;
		}
		px++;
	}
}

void	sprite_anim(t_var *var)
{
	static int	i;
	static int	count;

	if (count % 7 == 0)
	{
		i++;
		if (i == 8)
			i = 0;
	}
	print_sprite(var, i);
	count++;
	if (count >= 1000)
		count = 0;
}
