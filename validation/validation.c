/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 12:38:17 by kali              #+#    #+#             */
/*   Updated: 2025/01/14 21:49:56 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	validation(t_var *var)
{
	int	i;

	i = wall_img(var);
	if (i == 0)
		return (0);
	i = rgb_part(var);
	if (i == 0)
		return (0);
	// i = map_part(var);
	// if (i == 0)
	// 	return (0);
	return (1);
}
