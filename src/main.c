/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliobreg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:59:55 by aliobreg          #+#    #+#             */
/*   Updated: 2024/09/05 17:49:02 by aliobreg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	verificity_ber(char *argv)
{
	size_t	i;

	if (!argv)
		return (0);
	i = ft_strlen(argv);
	if (i < 4)
		return (0);
	if (argv[i - 5] != '/' && argv[i - 4] == '.' && argv[i - 3] == 'b'
		&& argv[i - 2] == 'e' && argv[i - 1] == 'r' )
		return (1);
	return (0);
}

void	check_valid_map(t_game *game)
{
	check_objects(game);
	check_valid_characters(game);
	check_rectangle(game);
	check_walls(game);
	check_path_recursive(game);
}

int	ft_deal_key(int key, t_vars *vars)
{
	if (key == KEY_A || key == ARROW_LEFT)
	{
		vars->game->current_img = vars->game->player_img_left;
		ft_move_left(vars);
	}
	if (key == KEY_W || key == ARROW_UP)
	{
		vars->game->current_img = vars->game->player_img_up;
		ft_move_up(vars);
	}
	if (key == KEY_S || key == ARROW_DOWN)
	{
		vars->game->current_img = vars->game->player_img_down;
		ft_move_down(vars);
	}
	if (key == KEY_D || key == ARROW_RIGHT)
	{
		vars->game->current_img = vars->game->player_img_right;
		ft_move_right(vars);
	}
	if (key == KEY_ESC)
		ft_close(vars);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_vars	vars;
	t_game	game;

	if (argc != 2)
		ft_error("Error\n Not valid arguments\n");
	if (argc == 2 && verificity_ber(argv[1]) == 0)
		ft_error("Error\n Not valid extension\n");
	ft_memset(&game, 0, sizeof(t_game));
	vars.game = &game;
	read_map(&game, argv[1]);
	check_valid_map(&game);
	init_game(&vars, &game);
	game.fakebool = 1;
	set_image(&vars);
	put_img(&vars);
	mlx_key_hook(vars.mlx_win, ft_deal_key, &vars);
	mlx_hook(vars.mlx_win, 17, 0, ft_close, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
