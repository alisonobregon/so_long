/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliobreg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 19:39:23 by aliobreg          #+#    #+#             */
/*   Updated: 2024/04/02 21:18:09 by aliobreg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_atoi(const char *str)
{
	int	n;
	int	j;

	n = 1;
	j = 0;
	while (*str)
	{
		while (*str == ' ' || *str == '\t' || *str == '\v'
			|| *str == '\f' || *str == '\n' || *str == '\r')
			str++;
		if (*str == '-')
		{
			str++;
			n = -1;
		}
		else if (*str == '+')
			str++;
		while (*str >= '0' && *str <= '9')
		{
			j = j * 10 + (*str - '0');
			str++;
		}
		return (j * n);
	}
	return (0);
}
