/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 12:38:17 by kali              #+#    #+#             */
/*   Updated: 2025/01/14 20:32:57 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	search_begin_map(t_var *var)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (var->map && var->map[i] && count < 2)
	{
		if ((ft_strcmp(var->map[i], var->rgb_format[0]) == 0) || 
			(ft_strcmp(var->map[i], var->rgb_format[1]) == 0))
			count++;
		i++;
	}
	if (!(count == 2))
		return (0);
	return (i);
}

void	map(t_var *var, int i)
{
	while (var->map[i])
	{
		// printf("%s\n", var->map[i]);
		i++;
	}
}

int	map_part(t_var *var)
{
	int	res;

	res = search_begin_map(var);
	if (res == 0)
		return (0);
	map(var, res);
	return (1);
}