/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_part.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 06:20:09 by kali              #+#    #+#             */
/*   Updated: 2025/01/14 09:17:51 by kali             ###   ########.fr       */
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
	if (valid_string(var->rgb_format) == 0)
	{
		printf("The color format lines are not correct.\n");
		return (0);
	}
	while (var->rgb_format && var->rgb_format[i])
	{
		l = 0;
		while (var->rgb_format[i][l])
		{
			if (var->rgb_format[i][l] == 'C'
				|| var->rgb_format[i][l] == 'F')
			{
				l++;
				while (var->rgb_format[i][l] == 32
					&& var->rgb_format[i][l] == 10)
					l++;
				if (cf_number(&var->rgb_format[i][l], var) == 0)
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

int	rgb_part(t_var *var)
{
	int		i;
	int		rgb;
	int		ngc;
	char	*str;

	i = 0;
	rgb = 0;
	str = NULL;
	ngc = number_given_colors(var);
	if(!(ngc == 2))
	{
		printf("The amount of color data is incorrect.\n");
		return (0);
	}
	var->rgb_format = (char **)malloc(sizeof(char *) * (ngc + 1));
	if (!var->rgb_format)
		return (0);
	while (var->map && var->map[i])
	{
		if (cf(var->map[i]) == 1)
		{
			var->rgb_format[rgb] = ft_strdup(var->map[i]);
			free(str);
			rgb++;
		}
		i++;
	}
	var->rgb_format[rgb] = NULL;
	if (str)
		free(str);
	if (!validation_collor(var))
		return (0);
	return (1);
}
