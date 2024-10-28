/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliobreg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:56:27 by aliobreg          #+#    #+#             */
/*   Updated: 2024/04/03 20:28:08 by aliobreg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		t;
	char	*s3;
	char	*s3_init;

	if (!s1 || !s2)
		return (NULL);
	t = (ft_strlen((char *) s1) + ft_strlen((char *) s2));
	s3 = (char *) malloc(sizeof (char) *(t + 1));
	if (!s3)
		return (NULL);
	s3_init = s3;
	while (*s1)
		*s3++ = *s1++;
	while (*s2)
		*s3++ = *s2++;
	*s3 = '\0';
	return (s3_init);
}
