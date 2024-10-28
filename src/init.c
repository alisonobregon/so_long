/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliobreg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 17:26:58 by aliobreg          #+#    #+#             */
/*   Updated: 2024/09/05 18:12:14 by aliobreg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_vars *vars, t_game *game)
{
	vars->mlx = mlx_init();
	vars->mlx_win = mlx_new_window(vars->mlx, game->map_x * 64,
			game->map_y * 64, "so_long");
}

int	ft_close(t_vars *vars)
{
	steps_count(vars);
	free_map(vars);
	if (vars->mlx_win)
	{
		mlx_clear_window(vars->mlx, vars->mlx_win);
		mlx_destroy_image(vars->mlx, vars->game->collectable_img);
		mlx_destroy_image(vars->mlx, vars->game->ground_img);
		mlx_destroy_image(vars->mlx, vars->game->wall_img);
		mlx_destroy_image(vars->mlx, vars->game->exit_img);
		mlx_destroy_image(vars->mlx, vars->game->player_img_down);
		mlx_destroy_image(vars->mlx, vars->game->player_img_up);
		mlx_destroy_image(vars->mlx, vars->game->player_img_left);
		mlx_destroy_image(vars->mlx, vars->game->player_img_right);
		mlx_destroy_window(vars->mlx, vars->mlx_win);
	}
	if (vars->mlx)
	{
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}
	exit (0);
	return (0);
}

void	ft_error(char *error)
{
	ft_putstr_fd (error, 1);
	exit (1);
}

int	steps_count(t_vars *vars)
{
	t_game	*game;

	game = vars->game;
	if (game->step_flag == 1)
	{
		ft_putstr_fd ("Steps count:", 1);
		ft_putnbr_fd (game->steps, 1);
		ft_putchar_fd ('\n', 1);
		game->step_flag = 0;
	}
	return (0);
}

void	free_map(t_vars *vars)
{
	int	s;

	s = 0;
	while (s < vars->game->map_y)
		free(vars->game->map[s++]);
	free(vars->game->map);
}
