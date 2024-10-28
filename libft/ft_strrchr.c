/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliobreg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 18:55:40 by aliobreg          #+#    #+#             */
/*   Updated: 2024/04/10 16:23:37 by aliobreg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*i;

	i = NULL;
	while (*s != '\0')
	{
		if (*s == (char) c)
			i = (char *) s;
		s++;
	}
	if ((char) c == '\0')
		return ((char *) s);
	return (i);
}
