/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliobreg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:35:41 by aliobreg          #+#    #+#             */
/*   Updated: 2024/06/26 18:49:59 by aliobreg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void read_map(t_complete game, char *argv)
{
	game -> fd = open(argv , O_RDONLY);
	if( game -> fd < 0)
		perror("Error reconociendo el archivo");
}


