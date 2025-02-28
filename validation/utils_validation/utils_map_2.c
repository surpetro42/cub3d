/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:53:03 by surpetro          #+#    #+#             */
/*   Updated: 2025/02/27 16:31:42 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	check_map_elem_door(char *previous, char *next, char *current, int l)
{
	int	len;

	len = ft_strlen(current);
	if ((l == 0 || l == len) || (((size_t)l >= ft_strlen(previous))
		|| ((size_t)l >= ft_strlen(next))))
		return (0);
	if (current[l] == 'D' && (current[l + 1] == '0' || current[l - 1] == '0'
		|| current[l - 1] == 'D' || current[l + 1] == 'D'))
	{
		if (previous[l] == '1' && next[l] == '1')
			return (1);
	}
	else if(current[l] == 'D' && (previous[l] == '0' || previous[l] == 'D'
		|| next[l] == '0' || next[l] == 'D'))
	{
		if (current[l + 1] == '1' && current[l - 1] == '1')
			return (1);
	}
	return (0);
}
