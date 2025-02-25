/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:25:16 by surpetro          #+#    #+#             */
/*   Updated: 2025/02/25 19:46:46 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_call(t_var *var, int flag)
{
	destroy_all_img(var, flag);
	free(var->wall);
	free_var(var);
	exit(1);
}

void	free_double_pointer(char **var)
{
	int	i;

	i = 0;
	while (var && var[i])
	{
		free(var[i]);
		i++;
	}
	free(var);
}

void	free_var(t_var *var)
{
	if (var->line)
		free(var->line);
	if (var->map)
		free_double_pointer(var->map);
	if (var->wall_img)
		free_double_pointer(var->wall_img);
	if (var->rgb_format)
		free_double_pointer(var->rgb_format);
	if (var->map_part)
		free_double_pointer(var->map_part);
}
