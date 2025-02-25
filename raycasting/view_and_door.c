/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_and_door.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:44:07 by surpetro          #+#    #+#             */
/*   Updated: 2025/02/25 12:50:14 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	press(t_var *var)
{
	free_call(var, 1);
	return (0);
}

void	open_close_door(t_var *var)
{
	int	x;
	int	y;

	x = (int)var->user.pos_x;
	y = (int)var->user.pos_y;
	if (var->user.dir_x < -0.05)
		x = (int)var->user.pos_x - 1;
	else if (var->user.dir_x > 0.05)
		x = (int)var->user.pos_x + 1;
	if (var->user.dir_y < -0.05)
		y = (int)var->user.pos_y - 1;
	else if (var->user.dir_y > 0.05)
		y = (int)var->user.pos_y + 1;
	if (var->map_part[x][y] == 'D')
		var->map_part[x][y] = 'O';
	else if (var->map_part[x][y] == 'O')
		var->map_part[x][y] = 'D';
}

void	get_dir(t_var *var)
{
	if (var->user.dir_x <= 0 && var->user.dir_y >= 0)
	{
		var->user.dir_x = 1 - pow(var->user.dir_x, 2);
		var->user.dir_y = 1 - pow(var->user.dir_y, 2);
	}
	else if (var->user.dir_x >= 0 && var->user.dir_y >= 0)
	{
		var->user.dir_x = 1 - pow(var->user.dir_x, 2);
		var->user.dir_y = -(1 - pow(var->user.dir_y, 2));
	}
	else if (var->user.dir_x >= 0 && var->user.dir_y <= 0)
	{
		var->user.dir_x = -(1 - pow(var->user.dir_x, 2));
		var->user.dir_y = -(1 - pow(var->user.dir_y, 2));
	}
	else
	{
		var->user.dir_x = -(1 - pow(var->user.dir_x, 2));
		var->user.dir_y = 1 - pow(var->user.dir_y, 2);
	}
}

void	rotate_view(t_var *var, double prevdir_x,
	double prevplane_x, double rotate)
{
	var->user.dir_x = var->user.dir_x * cos(rotate)
		- var->user.dir_y * sin(rotate);
	var->user.dir_y = prevdir_x * sin(rotate)
		+ var->user.dir_y * cos(rotate);
	var->user.plane_x = var->user.plane_x * cos(rotate)
		- var->user.plane_y * sin(rotate);
	var->user.plane_y = prevplane_x * sin(rotate)
		+ var->user.plane_y * cos(rotate);
}

void	change_view(t_var *var, int side, double rotate)
{
	double	prevplane_x;
	double	prevdir_x;

	prevdir_x = var->user.dir_x;
	prevplane_x = var->user.plane_x;
	if (side == RARROW)
		rotate_view(var, prevdir_x, prevplane_x, -rotate);
	else
		rotate_view(var, prevdir_x, prevplane_x, rotate);
}
