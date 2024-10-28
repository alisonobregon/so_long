/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliobreg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:46:02 by aliobreg          #+#    #+#             */
/*   Updated: 2024/04/03 16:54:02 by aliobreg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	t;
	void	*copychar;

	t = ft_strlen((char *) s1);
	copychar = malloc(t + 1);
	if (copychar != 0)
	{
		ft_memmove(copychar, (char *) s1, t + 1);
		return (copychar);
	}
	return (0);
}
