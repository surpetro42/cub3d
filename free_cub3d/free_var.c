/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 15:26:43 by surpetro          #+#    #+#             */
/*   Updated: 2025/01/02 15:10:52 by kali             ###   ########.fr       */
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
	{
		printf("*******111111111\n");
		free(var->line);
	}
	if (var->map)
	{
		printf("*******222222222\n");
		free_double_pointer(var->map);
	}
	if (var->wall_img)
	{
		printf("*******333333333\n");
		free_double_pointer(var->wall_img);
	}
	if (var->color_format)
	{
		printf("*******444444444\n");
		free_double_pointer(var->color_format);
	}
	if (var->map_part)
	{
		printf("*******555555555\n");
		free_double_pointer(var->map_part);
	}
}