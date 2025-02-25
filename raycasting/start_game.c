/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:44:00 by surpetro          #+#    #+#             */
/*   Updated: 2025/02/25 12:49:07 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	re_draw(t_var *var)
{
	mlx_destroy_image(var->mlx.ptr, var->img.img);
	create_image(var);
	raycasting(var);
	return (0);
}

void	init_img_var(t_var *var)
{
	var->wall = NULL;
	var->img.img = NULL;
	var->closedoor.img = NULL;
	var->opendoor.img = NULL;
	var->hide_map = 1;
	get_wall__textures(var);
	get_sprite_textures(var);
	get_door(&var->closedoor, var, "./textures/CloseDoor.xpm");
	get_door(&var->opendoor, var, "./textures/OpenDoor.xpm");
	create_image(var);
	var->f_color = create_trgb(0, var->number.f_0,
			var->number.f_1, var->number.f_2);
	var->c_color = create_trgb(0, var->number.c_0,
			var->number.c_1, var->number.c_2);
}

void	game_start(t_var var)
{
	var.map_wd = 1000;
	var.map_ht = 720;
	var.mlx.ptr = mlx_init();
	var.mlx.win = mlx_new_window(var.mlx.ptr, var.map_wd,
			var.map_ht, "CUB3D");
	if (!var.mlx.win)
		free_var(&var);
	init_img_var(&var);
	raycasting(&var);
	mlx_hook(var.mlx.win, 2, 0, &key_press, &var);
	mlx_hook(var.mlx.win, 6, 0, &mouse_move, &var);
	mlx_loop_hook(var.mlx.ptr, &re_draw, &var);
	mlx_hook(var.mlx.win, 17, 0, &press, &var);
	mlx_loop(var.mlx.ptr);
}
