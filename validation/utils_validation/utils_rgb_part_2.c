/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_rgb_part_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:27:12 by surpetro          #+#    #+#             */
/*   Updated: 2025/03/02 14:22:15 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	checking_rgb_line(char *str, int i)
{
	while (str[i] == '\t' || str[i] == ' ')
		i++;
	if (str[i] == 'C' || str[i] == 'F')
		i++;
	if (str[i] == ' ' || str[i] == '\t')
		return (1);
	return (0);
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
