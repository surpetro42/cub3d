/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:44:05 by surpetro          #+#    #+#             */
/*   Updated: 2025/02/25 12:49:56 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_door(t_img *door, t_var *var, char *path)
{
	door->img = mlx_xpm_file_to_image(var->mlx.ptr,
			path, &door->wd, &door->ht);
	if (!door->img)
		free_call(var, 1);
	door->addr = mlx_get_data_addr(door->img,
			&door->bits_per_pixel, &door->line_length,
			&door->endian);
	if (!door->addr)
		free_call(var, 1);
}

void	set_sprite_textures(t_var *var)
{
	var->sprite[0].img = mlx_xpm_file_to_image(var->mlx.ptr,
			"./textures/spriteanim/1.xpm", &var->sprite[0].wd,
			&var->sprite[0].ht);
	var->sprite[1].img = mlx_xpm_file_to_image(var->mlx.ptr,
			"./textures/spriteanim/2.xpm", &var->sprite[1].wd,
			&var->sprite[1].ht);
	var->sprite[2].img = mlx_xpm_file_to_image(var->mlx.ptr,
			"./textures/spriteanim/3.xpm", &var->sprite[2].wd,
			&var->sprite[2].ht);
	var->sprite[3].img = mlx_xpm_file_to_image(var->mlx.ptr,
			"./textures/spriteanim/4.xpm", &var->sprite[3].wd,
			&var->sprite[3].ht);
	var->sprite[4].img = mlx_xpm_file_to_image(var->mlx.ptr,
			"./textures/spriteanim/5.xpm", &var->sprite[4].wd,
			&var->sprite[4].ht);
	var->sprite[5].img = mlx_xpm_file_to_image(var->mlx.ptr,
			"./textures/spriteanim/6.xpm", &var->sprite[5].wd,
			&var->sprite[5].ht);
	var->sprite[6].img = mlx_xpm_file_to_image(var->mlx.ptr,
			"./textures/spriteanim/7.xpm", &var->sprite[6].wd,
			&var->sprite[6].ht);
	var->sprite[7].img = mlx_xpm_file_to_image(var->mlx.ptr,
			"./textures/spriteanim/8.xpm", &var->sprite[7].wd,
			&var->sprite[7].ht);
}

void	get_sprite_textures(t_var *var)
{
	int	i;

	set_sprite_textures(var);
	if (!var->sprite[0].img || !var->sprite[1].img
		|| !var->sprite[2].img || !var->sprite[3].img
		|| !var->sprite[4].img || !var->sprite[5].img
		|| !var->sprite[6].img || !var->sprite[7].img)
		free_call(var, 1);
	i = -1;
	while (++i < 8)
	{
		var->sprite[i].addr = mlx_get_data_addr(var->sprite[i].img,
				&var->sprite[i].bits_per_pixel, &var->sprite[i].line_length,
				&var->sprite[i].endian);
		if (!var->sprite[i].addr)
			free_call(var, 1);
	}
}

void	set_wall_textures(t_var *var)
{
	var->wall = malloc(sizeof(t_img) * 4);
	if (!var->wall)
		free_var(var);
	var->wall[0].img = mlx_xpm_file_to_image(var->mlx.ptr,
			var->wall_img[0], &var->wall[0].wd, &var->wall[0].ht);
	var->wall[1].img = mlx_xpm_file_to_image(var->mlx.ptr,
			var->wall_img[1], &var->wall[1].wd, &var->wall[1].ht);
	var->wall[2].img = mlx_xpm_file_to_image(var->mlx.ptr,
			var->wall_img[2], &var->wall[2].wd, &var->wall[2].ht);
	var->wall[3].img = mlx_xpm_file_to_image(var->mlx.ptr,
			var->wall_img[3], &var->wall[3].wd, &var->wall[3].ht);
}

void	get_wall__textures(t_var *var)
{
	int	i;

	set_wall_textures(var);
	if (!var->wall[0].img || !var->wall[1].img
		|| !var->wall[2].img || !var->wall[3].img
		|| var->wall[0].wd != var->wall[1].wd
		|| var->wall[0].ht != var->wall[1].ht
		|| var->wall[0].wd != var->wall[2].wd
		|| var->wall[0].ht != var->wall[2].ht
		|| var->wall[0].wd != var->wall[3].wd
		|| var->wall[0].ht != var->wall[3].ht)
		free_call(var, 0);
	i = -1;
	while (++i < 4)
	{
		var->wall[i].addr = mlx_get_data_addr(var->wall[i].img,
				&var->wall[i].bits_per_pixel, &var->wall[i].line_length,
				&var->wall[i].endian);
		if (!var->wall[i].addr)
			free_call(var, 0);
	}
}
