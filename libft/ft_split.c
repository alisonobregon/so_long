/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliobreg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 21:08:37 by aliobreg          #+#    #+#             */
/*   Updated: 2024/04/10 16:00:58 by aliobreg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*s)
	{
		if (*s != c && j == 0)
		{
			j = 1;
			i++;
		}
		else if (*s == c)
			j = 0;
		s++;
	}
	return (i);
}

static int	ft_count_chars(char const *s, char c)
{
	int	length;

	length = 0;
	while (s[length] != c && s[length] != '\0')
		length++;
	return (length);
}

static char	**ft_free_char(const char **newchar, int j)
{
	if (newchar)
	{
		while (j--)
			free((void *) newchar[j]);
		free(newchar);
	}
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**newchar;
	int		j;

	j = 0;
	newchar = (char **)malloc(sizeof (char *)
			*(ft_count_words(s, c) + 1));
	if (!s || !newchar)
		return (NULL);
	while (*s != '\0')
	{
		if (*s != c)
		{
			newchar[j] = (char *)malloc(sizeof(char)
					*(ft_count_chars(s, c) + 1));
			if (!newchar[j])
				return (ft_free_char((const char **) newchar, j));
			ft_strlcpy(newchar[j], s, ft_count_chars(s, c) + 1);
			s += ft_count_chars(s, c);
			j++;
		}
		else
			s++;
	}
	newchar[j] = 0;
	return (newchar);
}
