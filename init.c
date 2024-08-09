/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliobreg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 17:26:58 by aliobreg          #+#    #+#             */
/*   Updated: 2024/07/12 17:27:47 by aliobreg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void init_game(t_vars vars, t_game *game)
{
    vars->mlx = mlx_init;
    vars->mlx_win = mlx_new_window(vars->mlx, game->map_x * 128, game->map_y * 128, "so_long");
    //mlx_loop(game->mlx);
}

int	ft_close(t_vars *vars)
{
	//ft_count_steps(vars);
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	exit (0);
	return (0);
}