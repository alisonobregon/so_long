/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliobreg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:57:44 by aliobreg          #+#    #+#             */
/*   Updated: 2024/04/08 20:21:53 by aliobreg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*newchar;

	i = 0;
	newchar = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!newchar)
		return (NULL);
	while (s[i] != '\0')
	{
		newchar[i] = f(i, s[i]);
		i++;
	}
	newchar[i] = '\0';
	return (newchar);
}
