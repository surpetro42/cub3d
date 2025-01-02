/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization_var.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 13:12:56 by kali              #+#    #+#             */
/*   Updated: 2025/01/02 14:24:33 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	initialization_var(t_var *var)
{
	var->line = NULL;
	var->map = NULL;
	var->wall_img = NULL;
	var->color_format = NULL;
	var->map_part = NULL;
}