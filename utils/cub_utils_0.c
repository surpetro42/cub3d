/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils_0.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 15:34:40 by surpetro          #+#    #+#             */
/*   Updated: 2024/12/30 20:20:30 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		++i;
	return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	s_len;
	char			*m;
	unsigned int	j;

	if (!s)
		return (NULL);
	i = -1;
	j = 0;
	s_len = ft_strlen(s);
	if (start >= s_len)
		j = 1;
	else if (s_len < len + start)
		j = s_len - start + 1;
	else
		j = len + 1;
	m = malloc(sizeof(char) * j);
	if (m == NULL)
		return (NULL);
	while (++i < j - 1)
		m[i] = s[start + i];
	m[i] = '\0';
	return (m);
}


static int	count_words(char const *s, char x)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s != x)
		{
			count++;
			while (*s && *s != x)
				s++;
		}
		else
			++s;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	int			res_count;
	char		**str;
	int			i;
	const char	*p_s;

	if (!s)
		return (NULL);
	res_count = count_words(s, c);
	str = (char **)malloc((res_count + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	i = -1;
	while (++i < res_count)
	{
		while (*s == c)
			s++;
		p_s = s;
		while (*s && *s != c)
			s++;
		str[i] = ft_substr(p_s, 0, s - p_s);
		if (!str[i] && ft_split(*str, i))
			return (NULL);
	}
	str[i] = NULL;
	return (str);
}