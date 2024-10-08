/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliobreg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:35:41 by aliobreg          #+#    #+#             */
/*   Updated: 2024/07/02 16:32:14 by aliobreg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



void read_map(t_game game, char *argv)
{
	int		fd;
	char	*mapread;
	char	readed;

	game -> fd = open(argv , O_RDONLY);
	if( game -> fd < 0)
		perror("Error reconociendo el archivo");
	mapread =  (char *)calloc(BUFFER_SIZE + 1, 1);
	if(!mapread)
		return (NULL); //dEVOLVER PERROR
	readed = read(fd, mapread, BUFFER_SIZE);
	if (readed == -1)
		return(perror);
	game -> map = ft_split(mapread, '\n');
	close(game);
}



