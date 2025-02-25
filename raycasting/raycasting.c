/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:43:58 by surpetro          #+#    #+#             */
/*   Updated: 2025/02/25 12:48:46 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_floor(t_var *var)
{
	int	i;
	int	j;

	i = -1;
	while (++i < var->map_ht / 2)
	{
		j = -1;
		while (++j < var->map_wd)
			my_mlx_pixel_put(&var->img, j, i, var->c_color);
	}
	while (++i < var->map_ht - 1)
	{
		j = -1;
		while (++j < var->map_wd)
			my_mlx_pixel_put(&var->img, j, i, var->f_color);
	}
}

void	raycasting(t_var *var)
{
	int		w;

	draw_floor(var);
	w = -1;
	while (++w <= var->map_wd)
	{
		ray_pos(var, w);
		step_dir(var);
		var->ray.hit = 0;
		dda_algorithm(var);
		draw_texture(var, w, calc_texture_x(var));
	}
	sprite_anim(var);
	if (var->hide_map == 1)
		draw_minimap(var);
	mlx_put_image_to_window(var->mlx.ptr, var->mlx.win, var->img.img, 0, 0);
}
