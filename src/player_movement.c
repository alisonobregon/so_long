/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliobreg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 20:23:38 by aliobreg          #+#    #+#             */
/*   Updated: 2024/09/05 17:50:15 by aliobreg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_right(t_vars *vars)
{
	t_game	*game;

	game = vars->game;
	if (game->map[game->y_axis][game->x_axis + 1] != '1')
	{
		if (game-> map[game->y_axis][game->x_axis + 1] == 'C')
			game->coins--;
		if (game-> map[game->y_axis][game->x_axis + 1] == 'E')
		{
			if (game->coins == 0)
				all_colectionables(vars);
			else
				return ;
		}
		game->map[game->y_axis][game->x_axis] = '0';
		game->map[game->y_axis][game->x_axis + 1] = 'P';
		game->x_axis += 1;
		game->steps++;
		game->step_flag = 1;
		put_img(vars);
	}
}

void	ft_move_up(t_vars *vars)
{
	t_game	*game;

	game = vars->game;
	if (game->map[game->y_axis - 1][game->x_axis] != '1')
	{
		if (game-> map[game->y_axis - 1][game->x_axis] == 'C')
			game->coins--;
		if (game-> map[game->y_axis - 1][game->x_axis] == 'E')
		{
			if (game->coins == 0)
				all_colectionables(vars);
			else
				return ;
		}
		game->map[game->y_axis][game->x_axis] = '0';
		game->map[game->y_axis - 1][game->x_axis] = 'P';
		game->y_axis -= 1;
		game->steps++;
		game->step_flag = 1;
		put_img(vars);
	}
}

void	ft_move_down(t_vars *vars)
{
	t_game	*game;

	game = vars->game;
	if (game->map[game->y_axis + 1][game->x_axis] != '1')
	{
		if (game-> map[game->y_axis + 1][game->x_axis] == 'C')
			game->coins--;
		if (game-> map[game->y_axis + 1][game->x_axis] == 'E')
		{
			if (game->coins == 0)
				all_colectionables(vars);
			else
				return ;
		}
		game->map[game->y_axis][game->x_axis] = '0';
		game->map[game->y_axis + 1][game->x_axis] = 'P';
		game->y_axis += 1;
		game->steps++;
		game->step_flag = 1;
		put_img(vars);
	}
}

void	ft_move_left(t_vars *vars)
{
	t_game	*game;

	game = vars->game;
	if (game->map[game->y_axis][game->x_axis - 1] != '1')
	{
		if (game-> map[game->y_axis][game->x_axis - 1] == 'C')
			game->coins--;
		if (game-> map[game->y_axis][game->x_axis - 1] == 'E')
		{
			if (game->coins == 0)
				all_colectionables(vars);
			else
				return ;
		}
		game->map[game->y_axis][game->x_axis] = '0';
		game->map[game->y_axis][game->x_axis - 1] = 'P';
		game->x_axis -= 1;
		game->steps++;
		game->step_flag = 1;
		put_img(vars);
	}
}

void	all_colectionables(t_vars *vars)
{
	vars->game->step_flag = 1;
	vars->game->steps++;
	ft_close (vars);
}
