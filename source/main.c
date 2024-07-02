/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliobreg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:59:55 by aliobreg          #+#    #+#             */
/*   Updated: 2024/07/02 16:32:56 by aliobreg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main (int argc, char *argv[])
{
	t_complete game;
	if (argc != 2 && verificity_ber(argv))
		perror ("Numero de argumentos no valido");
	if (argc == 2 && !(verificity_ber(argv)))
		perror ("Archivo no valido");
	//if (argc && verificity_ber(argv)) algo que entre a la funcion
	
	ft_memset(&game, 0, sizeof(t_complete));
	read_map(&game, argv);
}
