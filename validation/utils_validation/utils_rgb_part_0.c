/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_rgb_part_0.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 20:06:34 by surpetro          #+#    #+#             */
/*   Updated: 2025/03/02 14:22:12 by surpetro         ###   ########.fr       */
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

int	validate_commas_and_count(char *line)
{
	int		comma;
	char	**str;
	int		count;

	comma = quantity_comma(line);
	if (comma != 2)
	{
		printf("ERROR!\nThe number of commas is incorrect.\n");
		return (0);
	}
	str = ft_split(line, ',');
	if (!str)
		return (0);
	count = 0;
	while (str[count])
		count++;
	if (count != 3)
	{
		printf("ERROR!\nIncorrect number of numbers is specified.\n");
		free_double_pointer(str);
		return (0);
	}
	free_double_pointer(str);
	return (1);
}

int	cf_number(char *line, t_var *var, char c)
{
	char	**str;

	if (!validate_commas_and_count(line))
		return (0);
	str = ft_split(line, ',');
	if (!str)
		return (0);
	if (initialization_number(str, var, c) == 0)
	{
		free_double_pointer(str);
		return (0);
	}
	free_double_pointer(str);
	return (1);
}

int	validate_rgb_format(char *rgb_line, t_var *var)
{
	int		l;
	char	c;

	l = 0;
	if (checking_rgb_line(rgb_line, 0) == 0)
	{
		printf("ERROR\nThe RGB line has an incorrect C and F format.\n");
		return (0);
	}
	c = rgb_line[l];
	l++;
	while (rgb_line[l] == 32 || rgb_line[l] == 9)
		l++;
	if (cf_number(&rgb_line[l], var, c) == 0)
		return (0);
	return (1);
}

int	validation_rgb(t_var *var, int i)
{
	int	l;

	if (error_valid_string(var) == 0)
		return (0);
	while (var->rgb_format && var->rgb_format[i])
	{
		l = 0;
		while (var->rgb_format[i][l])
		{
			if (var->rgb_format[i][l] == 'C' || var->rgb_format[i][l] == 'F')
			{
				if (!validate_rgb_format(var->rgb_format[i], var))
					return (0);
			}
			l++;
		}
		i++;
	}
	return (1);
}
