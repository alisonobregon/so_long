/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliobreg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:17:59 by aliobreg          #+#    #+#             */
/*   Updated: 2024/04/08 19:56:05 by aliobreg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_int_len(int a)
{
	int	i;

	i = 1;
	while (a / 10)
	{
		i++;
		a /= 10;
	}
	return (i);
}

static char	*ft_zero(char *s, int n)
{
	if (n == 0)
		*s = '0';
	return (s);
}

static char	*overflow(char *save, int n)
{
	if (n == -2147483647 - 1)
		ft_strlcpy(save, "-2147483648", 12);
	return (save);
}

char	*ft_itoa(int n)
{
	char	*save;
	int		len;
	int		n2;

	n2 = n;
	len = ft_int_len(n2);
	if (n2 < 0)
	{
		n2 = -n;
		len++;
	}
	save = (char *)malloc(sizeof(char) * (len + 1));
	if (!save)
		return (NULL);
	*(save + len) = '\0';
	ft_zero(save, n2);
	while (len--)
	{
		*(save + len) = n2 % 10 + '0';
		n2 /= 10;
	}
	if (n < 0)
		*save = '-';
	overflow(save, n);
	return (save);
}
