/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliobreg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 18:36:49 by aliobreg          #+#    #+#             */
/*   Updated: 2024/04/02 19:16:14 by aliobreg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int		i;
	size_t	y;
	size_t	srcsize;
	size_t	dstsize;

	srcsize = ft_strlen(src);
	dstsize = ft_strlen(dst);
	i = 0;
	y = 0;
	if (dstsize < size)
		y = dstsize + srcsize;
	else
		y = size + srcsize;
	while (src[i] != '\0' && (dstsize + 1) < size)
	{
		dst[dstsize] = src[i];
		i++;
		dstsize++;
	}
	dst[dstsize] = '\0';
	return (y);
}
