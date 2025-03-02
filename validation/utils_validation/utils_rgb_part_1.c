/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_rgb_part_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:27:12 by surpetro          #+#    #+#             */
/*   Updated: 2025/03/02 13:22:51 by surpetro         ###   ########.fr       */
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

int	number_given_colors(t_var *var)
{
	int	i;
	int	l;
	int	count;

	i = 0;
	count = 0;
	while (var->map && var->map[i])
	{
		l = 0;
		while (var->map[i][l])
		{
			if ((var->map[i][l] == 'C' || var->map[i][l] == 'F')
					&& var->map[i][l + 1] <= 32)
				count++;
			l++;
		}
		i++;
	}
	return (count);
}

int	valid_string(char **str)
{
	if (!str[0] || !str[1])
		return (0);
	if (ft_strcmp(str[0], str[1]) == 0)
		return (0);
	if (str[0][0] == str[1][0])
		return (0);
	return (1);
}

int	error_valid_string(t_var *var)
{
	if (valid_string(var->rgb_format) == 0)
	{
		printf("ERROR\nThe color format lines are not correct.\n");
		return (0);
	}
	return (1);
}
