/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:24:40 by surpetro          #+#    #+#             */
/*   Updated: 2025/02/24 19:24:41 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(char *left_str)
{
	int		i;
	char	*str;

	i = 0;
	if (!left_str)
		return (NULL);
	while (left_str[i] != '\n' && left_str[i])
		i++;
	str = (char *)ft_calloc((i + 2), sizeof(char));
	i = -1;
	while (left_str[++i] != '\n' && left_str[i])
		str[i] = left_str[i];
	if (left_str[i] == '\n')
	{
		str[i] = '\n';
		++i;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_new_left_str(char *left_str)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!left_str)
		return (NULL);
	while (left_str[i] != '\n' && left_str[i])
		++i;
	if (left_str[i] != '\0')
		i++;
	if (left_str[i] == '\0')
	{
		free (left_str);
		return (NULL);
	}
	str = (char *)ft_calloc(sizeof(char), ft_strlen_gnl(left_str) - i + 1);
	while (left_str[i])
		str[j++] = left_str[i++];
	free (left_str);
	return (str);
}

char	*ft_read_to_left(int fd, char *left_str)
{
	char	*buff;
	int		byts;

	if (fd < 0)
		return (NULL);
	byts = 1;
	buff = ft_calloc((BUFFER_SIZE + 1), (sizeof(char)));
	while ((!ft_strchr(left_str, '\n')) && byts != 0)
	{
		byts = read (fd, buff, BUFFER_SIZE);
		if ((byts == -1) || (byts == 0 && !left_str))
		{
			free(buff);
			return (NULL);
		}
		buff[byts] = '\0';
		left_str = ft_strjoin(left_str, buff);
	}
	free (buff);
	return (left_str);
}

char	*get_next_line(int fd)
{
	static char	*left_str;
	char		*line;
	char		*temp;

	temp = left_str;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	temp = ft_read_to_left(fd, temp);
	if (!temp)
		return (0);
	line = ft_get_line(temp);
	temp = ft_new_left_str(temp);
	left_str = temp;
	return (line);
}

// int main()
// {
// 	int fd = open("file.txt",O_RDWR);
// 	printf("%s",get_next_line(fd));
// 	printf("%s",get_next_line(fd));
// 	printf("%s",get_next_line(fd));
// 	printf("%s",get_next_line(fd));
// 	printf("%s",get_next_line(fd));
// 	// printf("%s",get_next_line(fd));
// 	// printf("%s",get_next_line(fd));
// 	// printf("%s",get_next_line(fd));
// 	// printf("%s",get_next_line(fd));
// 	// printf("%s",get_next_line(fd));
// 	// printf("%s",get_next_line(fd));
// 	// printf("%s",get_next_line(fd));
// 	// printf("%s",get_next_line(fd));
// 	// printf("\n%s",get_next_line(fd));
// 	return 0;
// }