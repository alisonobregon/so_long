/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliobreg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 19:28:26 by aliobreg          #+#    #+#             */
/*   Updated: 2024/04/01 19:33:41 by aliobreg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*s1u;
	unsigned char	*s2u;

	i = 0;
	s1u = (unsigned char *) s1;
	s2u = (unsigned char *) s2;
	while (i < n)
	{
		if (s1u[i] != s2u[i])
			return (s1u[i] - s2u[i]);
		i++;
	}
	if (i != n)
		return (s1u[i] - s2u[i]);
	return (0);
}
