/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_part.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 06:20:09 by kali              #+#    #+#             */
/*   Updated: 2025/01/09 17:07:46 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	initialization_number(char **str, t_var *var)
{
	int	i;
	int	buff;

	i = 0;
	while (str[i])
	{
		buff = ft_atoi(str[i]);
		if (!(buff <= 255 && buff >= 0))
		{
			printf("The number exceeds.\n");
			return (0);
		}
		assings(var, i, buff);
		i++;
	}
	return (1);
}

int	cf_number(char *line, t_var *var)
{
	int		comma;
	char	**str;

	comma = quantity_comma(line);
	if (comma != 2)
	{
		printf("The number of commas is incorrect.\n");
		return (0);
	}
	str = ft_split(line, ',');
	if (!str)
		return (0);
	if (initialization_number(str, var) == 0)
	{
		free_double_pointer(str);
		return (0);
	}
	free_double_pointer(str);
	return (1);
}

int	validation_collor(t_var *var)
{
	int	i;
	int	l;

	i = 0;
	while (var->color_format && var->color_format[i])
	{
		l = 0;
		while (var->color_format[i][l])
		{
			if (var->color_format[i][l] == 'C'
				|| var->color_format[i][l] == 'F')
			{
				l++;
				while (var->color_format[i][l] == 32
					&& var->color_format[i][l] == 10)
					l++;
				if (cf_number(&var->color_format[i][l], var) == 0)
					return (0);
			}
			l++;
		}
		i++;
	}
	return (1);
}

int	cf(char *line)
{
	int	i;

	i = 0;
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
			return (1);
		i++;
	}
	return (0);
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
	return (count);
}

int	color_part(t_var *var)
{
	int	i;
	int	coll;
	int	ngc;

	i = 0;
	coll = 0;
	ngc = number_given_colors(var);
	if(ngc == 0 || ngc > 2)
	{
		printf("The amount of color data is incorrect.\n");
		return (0);
	}
	var->color_format = (char **)malloc(sizeof(char *) * (ngc + 1));
	if (!var->color_format)
		return (0);
	while (var->map && var->map[i])
	{
		if (cf(var->map[i]) == 1)
		{
			var->color_format[coll] = ft_strdup(var->map[i]);
			coll++;
		}
		i++;
	}
	var->color_format[coll] = NULL;
	if (!validation_collor(var))
		return (0);
	return (1);
}
