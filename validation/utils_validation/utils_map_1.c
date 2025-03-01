/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:27:10 by surpetro          #+#    #+#             */
/*   Updated: 2025/03/02 12:51:42 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	checking_all_elements(t_var *var, int i)
{
	int	l;
	int	count;

	l = 0;
	while (var->map && var->map[i])
	{
		l = 0;
		count = 0;
		while (var->map[i][l])
		{
			if (!((var->map[i][l] == '1'
					|| var->map[i][l] == '0' || var->map[i][l] == 'N'
					|| var->map[i][l] == 'S' || var->map[i][l] == 'W'
					|| var->map[i][l] == ' ' || var->map[i][l] == 'E'
					|| var->map[i][l] == 'D' || var->map[i][l] == '\t'
					|| var->map[i][l] == '\n')))
				count++;
			l++;
		}
		if (count > 0)
			return (0);
		i++;
	}
	return (1);
}

int	search_mape_line(t_var *var, int i, int l)
{
	i = search_mape_line_elem(var, i);
	if (checking_all_elements(var, i) == 0)
		return (0);
	while (var->map && var->map[i])
	{
		if (ft_strlen(var->map[i]) != 0)
		{
			l = 0;
			while (var->map[i][l])
			{
				if (var->map[i][l] == '1')
					return (i);
				l++;
			}
			if (l > 0)
				return (0);
		}
		i++;
	}
	return (0);
}

int	search_next_newline(char *line, int i)
{
	if (line[i] == '\n')
		i++;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] == '\n')
		return (0);
	return (1);
}

int	end_line_elem_map(char *line, int i)
{
	while (line && line[i])
		i++;
	if (line[i] == '\0')
		i--;
	while (line && line[i])
	{
		if (line[i] == '1')
			return (i);
		if (!(line[i] == ' ' || line[i] == '\t' || line[i] == '\n'))
			return (0);
		i--;
	}
	return (0);
}

int	valid_newline_map(t_var *var)
{
	int	i;
	int	end;

	i = 0;
	end = end_line_elem_map(var->line, 0);
	while (var->line && var->line[i])
		i++;
	while (var->line[i] != ',' && i >= 0)
		i--;
	while (var->line[i] != '\n')
		i++;
	while (var->line[i] != '1')
		i++;
	while (i <= end && var->line[i])
	{
		if (var->line[i] == '\n')
		{
			if (search_next_newline(&var->line[i], 0) == 0)
				return (0);
		}
		i++;
	}
	return (1);
}
