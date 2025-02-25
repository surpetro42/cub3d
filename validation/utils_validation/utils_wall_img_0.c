/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_wall_img_0.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:27:15 by surpetro          #+#    #+#             */
/*   Updated: 2025/02/24 20:44:47 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	quality_element(char *line, int i)
{
	if (line && line[i] > 32)
	{
		while (line[i] > 32)
			i++;
		while (line[i] <= 32)
			i++;
		while (line[i] > 32)
			i++;
		if (line[i] == '\0')
			return (1);
	}
	return (0);
}

int	line_validation_error(t_var *var, int i)
{
	if (quality_element(var->map[i], 0) == 0)
	{
		printf("The number of items in the img row is not true\n");
		return (0);
	}
	return (1);
}

void	end_result(char **wall_img)
{
	int	i;

	i = 0;
	while (wall_img && wall_img[i])
	{
		wall_img[i] = ft_strtrim_free(wall_img[i], "WENOSA");
		wall_img[i] = ft_strtrim_free(wall_img[i], " \t");
		i++;
	}
}
