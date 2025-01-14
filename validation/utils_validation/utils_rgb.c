/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 07:09:56 by kali              #+#    #+#             */
/*   Updated: 2025/01/14 08:39:34 by kali             ###   ########.fr       */
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
			if ((var->map[i][l] == 'C' || var->map[i][l] == 'F') && var->map[i][l + 1] <= 32)
				count++;
			l++;
		}
		i++;
	}
	printf("%d\n", count);
	return (count);
}

int	valid_string(char **str)
{
	if (ft_strcmp(str[0], str[1]) == 0)
		return (0);
	if ((str[0][0] == str[1][0]))
		return (0);
	return (1);
}
