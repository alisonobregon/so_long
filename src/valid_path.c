/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliobreg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:21:38 by aliobreg          #+#    #+#             */
/*   Updated: 2024/09/17 15:50:29 by aliobreg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	path_checker_exit(t_game *game, int y_axis, int x_axis)
{
	int	flag;

	if (y_axis < 0 || y_axis >= game->map_y || x_axis < 0
		|| x_axis >= game->map_x)
		return (0);
	if (game->map_copy[y_axis][x_axis] == 'E')
		return (1);
	if (game->map_copy[y_axis][x_axis] == 'C')
		game->coins_reachable--;
	game->map_copy[y_axis][x_axis] = 'R';
	flag = 0;
	if (game->map_copy[y_axis][x_axis + 1] != '1'
		&& game->map_copy[y_axis][x_axis + 1] != 'R')
		flag += path_checker_exit(game, y_axis, x_axis + 1);
	if (game->map_copy[y_axis][x_axis - 1] != '1'
		&& game->map_copy[y_axis][x_axis - 1] != 'R')
		flag += path_checker_exit(game, y_axis, x_axis - 1);
	if (game->map_copy[y_axis + 1][x_axis] != '1'
		&& game->map_copy[y_axis + 1][x_axis] != 'R')
		flag += path_checker_exit(game, y_axis + 1, x_axis);
	if (game->map_copy[y_axis - 1][x_axis] != '1'
		&& game->map_copy[y_axis - 1][x_axis] != 'R')
		flag += path_checker_exit(game, y_axis - 1, x_axis);
	return (flag > 0 && game->coins_reachable == 0);
}

void	check_path_recursive(t_game *game)
{
	int	valid;
	int	i;

	i = 0;
	game->coins_reachable = game->coins;
	valid = path_checker_exit(game, game->y_axis, game->x_axis);
	if (game->coins_reachable > 0)
		ft_error("Error\n No avaliable coins\n");
	if (valid == 0)
		ft_error("Error\n No avaliable path\n");
	i = 0;
	while (i < game->map_y)
		free(game->map_copy[i++]);
	free (game->map_copy);
}
