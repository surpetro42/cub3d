/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:43:48 by surpetro          #+#    #+#             */
/*   Updated: 2025/02/25 12:43:49 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	create_image(t_var *var)
{
	var->img.img = mlx_new_image(var->mlx.ptr,
			var->map_wd, var->map_ht);
	if (!var->img.img)
		free_call(var, 1);
	var->img.addr = mlx_get_data_addr(var->img.img,
			&var->img.bits_per_pixel, &var->img.line_length,
			&var->img.endian);
	if (!var->img.addr)
		free_call(var, 1);
	var->img.wd = var->map_wd;
	var->img.ht = var->map_ht;
}
