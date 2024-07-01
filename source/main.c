/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliobreg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:59:55 by aliobreg          #+#    #+#             */
/*   Updated: 2024/06/26 18:35:20 by aliobreg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int main (int argc, char *argv[])
{
	t_complete game;
	if (argc != 2)
		perror ("Numero de argumenntos no valido");
	ft_memset(&game, 0, sizeof(t_complete));
	read_map(&game, argv);
}
