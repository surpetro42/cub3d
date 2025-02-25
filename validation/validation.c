/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:27:05 by surpetro          #+#    #+#             */
/*   Updated: 2025/02/24 20:10:36 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	validation(t_var *var)
{
	int	i;

	i = wall_img(var);
	if (i == 0)
		return (0);
	i = rgb_part(var, 0, 0, 0);
	if (i == 0)
		return (0);
	i = map_part(var);
	if (i == 0)
		return (0);
	return (1);
}
