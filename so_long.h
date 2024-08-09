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

#define KEY_ESC			53
#define KEY_W			13
#define KEY_A			0
#define KEY_S			1
#define KEY_D			2
#define ARROW_UP		126
#define ARROW_LEFT		123
#define ARROW_DOWN		125
#define ARROW_RIGHT		124
//#define RED_TEXT		53

typedef struct s_vars
{
	void		*mlx;
	void		*mlx_win;
	t_game	*game;
}				t_vars;
typedef struct s_game
{
	char		*player_img;
	char		*wall_img;
	char		*exit_img;
	char		*ground_img;
	char		*collectable_img;
	int			fd;
	int			widht;
	int			height;
	int			player_count;
	int			column_count;
	int			exit_count;
	int			coins;
	int			x_axis;
	int			y_axis;
	int			counter;
	int			step_flag;
	int			steps;
	int			map_y; //p_y
	int			map_x;
	
	char	**map;

}			t_game;

#endif
