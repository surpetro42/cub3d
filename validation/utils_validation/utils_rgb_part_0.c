/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_rgb_part_0.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 20:06:34 by surpetro          #+#    #+#             */
/*   Updated: 2025/02/26 20:14:13 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	initialization_number(char **str, t_var *var, char c)
{
	int	i;
	int	buff;
	int	k;

	i = 0;
	k = 0;
	if (c == 'F')
		k = 3;
	while (str[i])
	{
		buff = ft_atoi(str[i]);
		if (!(buff <= 255 && buff >= 0))
		{
			printf("ERROR!\nThe number exceeds.\n");
			return (0);
		}
		assings(var, i + k, buff);
		i++;
	}
	return (1);
}

int	cf_number(char *line, t_var *var, char c)
{
	int		comma;
	int		count;
	char	**str;

	comma = quantity_comma(line);
	count = 0;
	if (comma != 2)
	{
		printf("ERROR!\nThe number of commas is incorrect.\n");
		return (0);
	}
	str = ft_split(line, ',');
	if (!str)
		return (0);
		
	while (str && str[count])
		count++;
	if (count != 3)
	{
		printf("ERROR!\nIncorrect number of numbers is specified.\n");
		return (0);
	}
	if (initialization_number(str, var, c) == 0)
	{
		free_double_pointer(str);
		return (0);
	}
	free_double_pointer(str);
	return (1);
}

int	error_valid_string(t_var *var)
{
	if (valid_string(var->rgb_format) == 0)
	{
		printf("The color format lines are not correct.\n");
		return (0);
	}
	return (1);
}

int	validation_rgb(t_var *var, int i, int l, char c)
{
	if (error_valid_string(var) == 0)
		return (0);
	while (var->rgb_format && var->rgb_format[i])
	{
		l = 0;
		while (var->rgb_format[i][l])
		{
			if (var->rgb_format[i][l] == 'C'
				|| var->rgb_format[i][l] == 'F')
			{
				c = var->rgb_format[i][l];
				l++;
				while (var->rgb_format[i][l] == 32
					&& var->rgb_format[i][l] == 9)
					l++;
				if (cf_number(&var->rgb_format[i][l], var, c) == 0)
					return (0);
			}
			l++;
		}
		i++;
	}
	return (1);
}

int	cf(char *line, int i, int count)
{
	while (line[i])
	{
		if ((line[i] == 'C' || line[i] == 'F') && line[i + 1] <= 32)
			break ;
		i++;
	}
	if (line[i] == 'C' || line[i] == 'F')
		i++;
	while (line[i] && line[i] <= 32)
		i++;
	while (line[i])
	{
		if ((line[i] >= '0' && line[i] <= '9') || line[i] == ',')
			count++;
		else
		{
			count = 0;
			break ;
		}
		i++;
	}
	return (count);
}
