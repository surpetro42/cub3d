/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 15:26:43 by surpetro          #+#    #+#             */
/*   Updated: 2025/01/14 07:41:25 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_double_pointer(char **var)
{
    int i;

    i = 0;
    while(var && var[i])
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