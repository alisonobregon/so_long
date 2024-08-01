/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliobreg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:07:58 by aliobreg          #+#    #+#             */
/*   Updated: 2024/07/24 19:41:02 by aliobreg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <fcntl.h>
#include "../minilibx-linux/mlx.h"

typedef struct s_vars
{
	void		*mlx;
	void		*mlx_win;
	//t_complete	*game;
}				t_vars;
typedef struct s_game
{
	int			fd;
	int			widht;
	int			height;
	int			player_count;
	int			column_count;
	int			exit_count;
	int			colections_count;
	int			x_axis;
	int			y_axis;
	int			counter;
	int			map_y;
	int			map_x;
	
	char	**map;

}			t_game;

#endif
