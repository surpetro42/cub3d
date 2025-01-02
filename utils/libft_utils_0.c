/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils_0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 13:13:06 by kali              #+#    #+#             */
/*   Updated: 2025/01/02 06:33:50 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

//		libft function
size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s && s[i] != '\0')
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

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	x;
	char	*m;

	i = 0;
	x = ft_strlen(s1);
	m = (char *)malloc(x + 1);
	if (m == NULL)
		return (NULL);
	while (i < x)
	{
		m[i] = s1[i];
		++i;
	}
	if (i == x)
		m[i] = '\0';
	return (m);
}