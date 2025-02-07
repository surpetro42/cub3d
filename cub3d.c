/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 15:26:43 by surpetro          #+#    #+#             */
/*   Updated: 2025/02/07 15:00:47 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*gnl(int fd)
{
	char	*str;
	char	*line;

	line = NULL;
	str = NULL;
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
		{
			free(str);
			break ;
		}
		line = ft_strjoin(line, str);
		free(str);
	}
	return (line);
}

void	map_trim(char **map)
{
	int		i;
	char	*buff;

	i = 0;
	buff = NULL;
	while (map && map[i])
	{
		buff = ft_strdup(map[i]);
		free(map[i]);
		map[i] = ft_strtrim(buff, "\t ");
		free(buff);
		i++;
	}
}

void	valid_gnl(int fd)
{
	t_var var;

	initialization_var(&var);
	var.line = NULL;
	var.line = gnl(fd);
	if (!var.line)
		exit(write(2, "ERROR\nThere is nothing in the file\n", 36));
	var.map = ft_split(var.line, '\n');
	map_trim(var.map);
	if (validation(&var) == 0)
	{
		free_var(&var);
		return ;
	}
	int x = 0;
	// while (var.map[x])
	// {
	// 	printf("%d ----- %s\n", x, var.map[x]);
	// 	x++;
	// }
	// while (var.wall_img[x])
	// {
	// 	printf("%s\n",var.wall_img[x]);
	// 	x++;
	// }
	// x = 0;
	// printf("-----------------------\n");
	// while (var.rgb_format[x])
	// {
	// 	printf("%s\n",var.rgb_format[x]);
	// 	x++;
	// }
	x = 0;
	// printf("-----------------------\n");
	while (var.map_part[x])
	{
		printf("%s\n",var.map_part[x]);
		x++;
	}
	free_var(&var);
}

int	main(int argc, char **argv)
{
	int		i;
	int		fd;
	size_t	len;

	i = 0;
	len = ft_strlen(argv[1]);
	if (argc > 1)
	{
		fd = -1;
		if (len > 4 && ft_strcmp(&argv[1][len - 4], ".cub") == 0)
		{
			fd = open(argv[1], O_RDWR);
			if (fd <= 0)
				return (1);
			valid_gnl(fd);
		}
		if (fd < 0)
			return (1);
		i++;
	}
	else
		return (write(2, "Еmpty\n", 8));
	// system("valgrind --leak-check=full ./cub3d");
	return (0);
}
