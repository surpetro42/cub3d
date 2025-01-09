/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_part_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 06:20:09 by kali              #+#    #+#             */
/*   Updated: 2025/01/09 15:51:22 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	quantity_comma(char *line)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line && line[i])
	{
		if (line[i] == ',')
			count++;
		i++;
	}
	return (count);
}

void	assings(t_var *var, int i, int buff)
{
	if (i == 0)
		var->number.c_0 = buff;
	if (i == 1)
		var->number.c_1 = buff;
	if (i == 2)
		var->number.c_2 = buff;
	if (i == 3)
		var->number.f_0 = buff;
	if (i == 4)
		var->number.f_1 = buff;
	if (i == 5)
		var->number.f_2 = buff;
}