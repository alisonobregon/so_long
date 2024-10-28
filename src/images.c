/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliobreg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 09:34:39 by aliobreg          #+#    #+#             */
/*   Updated: 2024/09/05 18:03:03 by aliobreg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_img_util(t_vars *vars, int y, int x)
{
	if (vars->game->map[y][x] == '0')
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			vars->game->ground_img, x * 64, y * 64);
	if (vars->game->map[y][x] == '1')
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			vars->game->wall_img, x * 64, y * 64);
	if (vars->game->map[y][x] == 'C')
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			vars->game->collectable_img, x * 64, y * 64);
	if (vars->game->map[y][x] == 'E')
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			vars->game->exit_img, x * 64, y * 64);
}

void	put_img(t_vars *vars)
{
	int	y;
	int	x;

	mlx_clear_window(vars->mlx, vars->mlx_win);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win,
		vars->game->current_img, vars->game->x_axis * 64,
		vars->game->y_axis * 64);
	steps_count (vars);
	y = -1;
	while (vars->game->map[++y])
	{
		x = -1;
		while (vars->game->map[y][++x])
			put_img_util(vars, y, x);
	}
}

int	set_image(t_vars *vars)
{
	t_game	*game;

	game = vars->game;
	game->img_height = 64;
	game->img_width = 64;
	game->ground_img = mlx_xpm_file_to_image(vars->mlx, "img/suelo.xpm",
			&game->img_width, &game->img_height);
	game->wall_img = mlx_xpm_file_to_image(vars->mlx, "img/pared.xpm",
			&game->img_width, &game->img_height);
	game->collectable_img = mlx_xpm_file_to_image(vars->mlx,
			"img/Donuts.xpm", &game->img_width,
			&game->img_height);
	game->exit_img = mlx_xpm_file_to_image(vars->mlx, "img/salida.xpm",
			&game->img_width, &game->img_height);
	set_image_character(vars);
	if (!game->ground_img || !game->wall_img || !game->collectable_img
		|| !game->exit_img || !game->player_img_down
		|| !game->player_img_left || !game->player_img_right
		|| !game->player_img_up)
		ft_error("Error\n Images failed");
	return (0);
}

void	set_image_character(t_vars *vars)
{
	vars->game->player_img_down = mlx_xpm_file_to_image(vars->mlx,
			"img/tonyfrente.xpm", &vars->game->img_width,
			&vars->game->img_height);
	vars->game->player_img_up = mlx_xpm_file_to_image(vars->mlx,
			"img/tonyespaldas.xpm", &vars->game->img_width,
			&vars->game->img_height);
	vars->game->player_img_left = mlx_xpm_file_to_image(vars->mlx,
			"img/tonyizquierda.xpm", &vars->game->img_width,
			&vars->game->img_height);
	vars->game->player_img_right = mlx_xpm_file_to_image(vars->mlx,
			"img/tonyderecha.xpm", &vars->game->img_width,
			&vars->game->img_height);
	if (vars->game->fakebool == 1)
	{
		vars->game->current_img = vars->game->player_img_down;
		vars->game->fakebool = 0;
	}
}
