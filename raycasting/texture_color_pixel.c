/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_color_pixel.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:44:02 by surpetro          #+#    #+#             */
/*   Updated: 2025/02/25 12:49:33 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

unsigned int	my_mlx_color_taker(t_img *data, int j, int i)
{
	char			*dst;

	if (j >= 0 && j < data->wd && i >= 0 && i < data->ht)
	{
		dst = data->addr + (i * data->line_length
				+ j * (data->bits_per_pixel / 8));
		return (*(unsigned int *)dst);
	}
	return (0);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

t_img	*choose_texture(t_var *var)
{
	if (var->ray.hit == 2)
		return (&var->closedoor);
	else if (var->ray.hit == 3)
		return (&var->opendoor);
	else if (var->ray.side == 1 && var->ray.ray_y <= 0)
		return (var->wall);
	else if (var->ray.side == 0 && var->ray.ray_x > 0)
		return (var->wall + 1);
	else if (var->ray.side == 0 && var->ray.ray_x <= 0)
		return (var->wall + 2);
	return (var->wall + 3);
}

void	draw_texture(t_var *var, int x, int tex_x)
{
	t_draw			tex;
	int				y;

	if (var->ray.perp_wall_dist < 0.000001)
		var->ray.perp_wall_dist = 0.000001;
	calc_draw_ends(var, &tex);
	y = tex.draw_start - 1;
	while (++y < tex.draw_end)
	{
		tex.tex_y = (int)tex.tex_pos & (63);
		tex.tex_pos += tex.step;
		my_mlx_pixel_put(&var->img, x, y,
			my_mlx_color_taker(choose_texture(var), tex_x, tex.tex_y));
	}
}
