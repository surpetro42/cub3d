/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_part.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:27:02 by surpetro          #+#    #+#             */
/*   Updated: 2025/02/24 20:10:43 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	rgb_part(t_var *var, int i, int rgb, int ngc)
{
	ngc = number_given_colors(var);
	if (!(ngc == 2))
	{
		printf("The amount of color data is incorrect.\n");
		return (0);
	}
	var->rgb_format = (char **)malloc(sizeof(char *) * (ngc + 1));
	if (!var->rgb_format)
		return (0);
	while (var->map && var->map[i])
	{
		if (cf(var->map[i], 0, 0) > 0)
		{
			var->rgb_format[rgb] = ft_strdup(var->map[i]);
			rgb++;
		}
		i++;
	}
	var->rgb_format[rgb] = NULL;
	if (!validation_rgb(var, 0, 0, ' '))
		return (0);
	return (1);
}
