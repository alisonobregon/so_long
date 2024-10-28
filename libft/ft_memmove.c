/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliobreg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 16:30:01 by aliobreg          #+#    #+#             */
/*   Updated: 2024/04/01 16:38:48 by aliobreg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*cdst;
	unsigned const char	*csrc;
	size_t				i;

	cdst = (unsigned char *) dst;
	csrc = (unsigned const char *) src;
	if (!dst && !src)
		return (NULL);
	if (csrc < cdst)
	{
		i = len;
		while (i--)
			cdst[i] = csrc[i];
	}
	else
	{
		while (len--)
			*cdst++ = *csrc++;
	}
	return (dst);
}
