/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:43:45 by surpetro          #+#    #+#             */
/*   Updated: 2025/02/25 12:46:05 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	dda_algorithm(t_var *var)
{
	while (var->ray.hit == 0)
	{
		if (var->ray.sdist_x < var->ray.sdist_y)
		{
			var->ray.sdist_x += var->ray.deltadist_x;
			var->user.map_x += var->user.step_x;
			var->ray.side = 0;
		}
		else
		{
			var->ray.sdist_y += var->ray.deltadist_y;
			var->user.map_y += var->user.step_y;
			var->ray.side = 1;
		}
		if (var->map_part[var->user.map_x][var->user.map_y] == '1')
			var->ray.hit = 1;
		else if (var->map_part[var->user.map_x][var->user.map_y] == 'D')
			var->ray.hit = 2;
		else if (var->map_part[var->user.map_x][var->user.map_y] == 'O')
			var->ray.hit = 3;
	}
	if (var->ray.side == 0)
		var->ray.perp_wall_dist = (var->ray.sdist_x - var->ray.deltadist_x);
	else
		var->ray.perp_wall_dist = (var->ray.sdist_y - var->ray.deltadist_y);
}

void	ray_pos(t_var *var, int w)
{
	var->ray.camera_x = 2.0 * w / (double)var->map_wd - 1.0;
	var->ray.ray_x = var->user.dir_x
		+ var->user.plane_x * var->ray.camera_x;
	var->ray.ray_y = var->user.dir_y
		+ var->user.plane_y * var->ray.camera_x;
	var->user.map_x = (int)var->user.pos_x;
	var->user.map_y = (int)var->user.pos_y;
	if (var->ray.ray_x == 0)
		var->ray.deltadist_x = 1e30;
	else
		var->ray.deltadist_x = fabs(1 / var->ray.ray_x);
	if (var->ray.ray_y == 0)
		var->ray.deltadist_y = 1e30;
	else
		var->ray.deltadist_y = fabs(1 / var->ray.ray_y);
}

void	calc_draw_ends(t_var *var, t_draw *tex)
{
	tex->line_height = (int)(var->map_ht / var->ray.perp_wall_dist);
	tex->draw_start = -tex->line_height / 2 + var->map_ht / 2;
	if (tex->draw_start < 0)
		tex->draw_start = 0;
	tex->draw_end = tex->line_height / 2 + var->map_ht / 2;
	if (tex->draw_end >= var->map_ht)
		tex->draw_end = var->map_ht - 1;
	tex->step = 1.0 * 64 / tex->line_height;
	tex->tex_pos = (tex->draw_start - var->map_ht / 2 + tex->line_height / 2)
		* tex->step;
}

int	calc_texture_x(t_var *var)
{
	int		tex_x;
	double	wall_x;

	wall_x = var->user.pos_x + var->ray.perp_wall_dist * var->ray.ray_x;
	if (var->ray.side == 0)
		wall_x = var->user.pos_y + var->ray.perp_wall_dist * var->ray.ray_y;
	wall_x -= floor((wall_x));
	tex_x = (int)(wall_x * (double)(64));
	if ((var->ray.side == 0 && var->ray.ray_x > 0)
		|| (var->ray.side == 1 && var->ray.ray_y < 0))
		tex_x = 64 - tex_x - 1;
	return (tex_x);
}

void	step_dir(t_var *var)
{
	if (var->ray.ray_x < 0)
	{
		var->user.step_x = -1;
		var->ray.sdist_x = (var->user.pos_x - var->user.map_x)
			* var->ray.deltadist_x;
	}
	else
	{
		var->user.step_x = 1;
		var->ray.sdist_x = (var->user.map_x + 1.0 - var->user.pos_x)
			* var->ray.deltadist_x;
	}
	if (var->ray.ray_y < 0)
	{
		var->user.step_y = -1;
		var->ray.sdist_y = (var->user.pos_y - var->user.map_y)
			* var->ray.deltadist_y;
	}
	else
	{
		var->user.step_y = 1;
		var->ray.sdist_y = (var->user.map_y + 1.0 - var->user.pos_y)
			* var->ray.deltadist_y;
	}
}
