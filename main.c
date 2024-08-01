/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliobreg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:59:55 by aliobreg          #+#    #+#             */
/*   Updated: 2024/07/24 17:58:22 by aliobreg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
bool verificity_ber(char *argv)
{
	char	*save;

	save = ft_strrchr(argv, '.');
	if (save)
		return (ft_strncmp(save, "ber") == 0);
	return (0);
}
void check_valid_map(t_game *game)
{
	check_objects(&game);
	check_valid_characters(&game);
	check_rectangle(&game);
	check_walls(&game);
}

int main (int argc, char *argv[])
{
	t_vars	vars;
	t_game	game;

	if (argc != 2 && verificity_ber(argv))
		perror ("Numero de argumentos no valido");
	if (argc == 2 && !(verificity_ber(argv)))
		perror ("Archivo no valido");
	if (argc && verificity_ber(argv))
	{
		vars.game = &game;
		//ft_memset(&game, 0, sizeof(t_vars));
		read_map(&game, argv[1]);
		check_valid_map(&game);
		init_game(&game);
	}

}
/*
int main (void)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	mlx_loop(mlx);
}

*/