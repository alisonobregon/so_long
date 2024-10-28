/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliobreg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 16:27:10 by aliobreg          #+#    #+#             */
/*   Updated: 2024/04/01 16:29:38 by aliobreg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*cdst;
	char	*csrc;

	if (!dst && !src)
		return (NULL);
	cdst = (char *) dst;
	csrc = (char *) src;
	while (n--)
		*cdst++ = *csrc++;
	return ((char *) dst);
}
