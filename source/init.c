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

void init_game(t_game game)
{
    game->mlx = mlx_init;
    game->mlx_new_window = mlx_new_window(game->mlx, 1920, 1080, "asd");
    mlx_loop(game->mlx);
}

