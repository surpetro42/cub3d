/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:25:20 by surpetro          #+#    #+#             */
/*   Updated: 2025/02/25 19:45:22 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	sprite_destroy(t_var *var)
{
	int	i;

	i = -1;
	while (++i < 8)
	{
		if (var->sprite[i].img != NULL)
			mlx_destroy_image(var->mlx.ptr, var->sprite[i].img);
		var->sprite[i].img = NULL;
	}
}

void	destroy_all_img(t_var *var, int flag)
{
	if (flag)
		sprite_destroy(var);
	if (var->wall[0].img)
		mlx_destroy_image(var->mlx.ptr, var->wall[0].img);
	if (var->wall[1].img)
		mlx_destroy_image(var->mlx.ptr, var->wall[1].img);
	if (var->wall[2].img)
		mlx_destroy_image(var->mlx.ptr, var->wall[2].img);
	if (var->wall[3].img)
		mlx_destroy_image(var->mlx.ptr, var->wall[3].img);
	if (var->img.img)
		mlx_destroy_image(var->mlx.ptr, var->img.img);
	if (var->closedoor.img)
		mlx_destroy_image(var->mlx.ptr, var->closedoor.img);
	if (var->opendoor.img)
		mlx_destroy_image(var->mlx.ptr, var->opendoor.img);
}
