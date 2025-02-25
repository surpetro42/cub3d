/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization_var.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:25:26 by surpetro          #+#    #+#             */
/*   Updated: 2025/02/24 19:28:10 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	initialization_var(t_var *var)
{
	var->line = NULL;
	var->map = NULL;
	var->wall_img = NULL;
	var->rgb_format = NULL;
	var->map_part = NULL;
}
