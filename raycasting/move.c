/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:43:53 by surpetro          #+#    #+#             */
/*   Updated: 2025/02/25 12:47:19 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	key_press(int key, t_var *var)
{
	if (key == ESC)
		free_call(var, 1);
	else if (key == LARROW)
		change_view(var, LARROW, AROTATE);
	else if (key == RARROW)
		change_view(var, RARROW, AROTATE);
	else if (key == E)
		open_close_door(var);
	else if (key == W)
		move_w(var, WSPEED);
	else if (key == S)
		move_s(var, SSPEED);
	else if (key == A || key == D)
		move_right_left(var, key, ADSPEED);
	else if (key == M)
		var->hide_map *= -1;
	return (0);
}

void	move_s(t_var *var, double move)
{
	if (var->map_part[(int)(var->user.pos_x - var->user.dir_x * move)]
		[(int)(var->user.pos_y)] == '0'
		|| var->map_part[(int)(var->user.pos_x
		- var->user.dir_x * move)][(int)(var->user.pos_y)] == 'O')
		var->user.pos_x -= var->user.dir_x * move;
	if (var->map_part[(int)(var->user.pos_x)][(int)(var->user.pos_y
		- var->user.dir_y * move)] == '0'
		|| var->map_part[(int)(var->user.pos_x)][(int)(var->user.pos_y
		- var->user.dir_y * move)] == 'O')
		var->user.pos_y -= var->user.dir_y * move;
}

void	move_w(t_var *var, double move)
{
	if (var->map_part[(int)(var->user.pos_x + var->user.dir_x * move)]
		[(int)(var->user.pos_y)] == '0'
		|| var->map_part[(int)(var->user.pos_x
		+ var->user.dir_x * move)][(int)(var->user.pos_y)] == 'O')
		var->user.pos_x += var->user.dir_x * move;
	if (var->map_part[(int)(var->user.pos_x)][(int)(var->user.pos_y
		+ var->user.dir_y * move)] == '0'
		|| var->map_part[(int)(var->user.pos_x)][(int)(var->user.pos_y
		+ var->user.dir_y * move)] == 'O')
		var->user.pos_y += var->user.dir_y * move;
}

void	move_right_left(t_var *var, int key, double move)
{
	double	prev_x;
	double	prev_y;

	prev_x = var->user.dir_x;
	prev_y = var->user.dir_y;
	get_dir(var);
	if (key == D)
		move_w(var, move);
	else if (key == A)
		move_s(var, move);
	var->user.dir_x = prev_x;
	var->user.dir_y = prev_y;
}

int	mouse_move(int x, int y, t_var *var)
{
	static int	prevx;

	(void)y;
	if (x < prevx)
		change_view(var, LARROW, MROTATE * abs(x - prevx));
	else if (x > prevx)
		change_view(var, RARROW, MROTATE * abs(x - prevx));
	prevx = x;
	return (0);
}
