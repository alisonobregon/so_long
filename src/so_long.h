/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliobreg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:07:58 by aliobreg          #+#    #+#             */
/*   Updated: 2024/08/31 17:44:34 by aliobreg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>
# include "../mlx_linux/mlx.h"
# include "../libft/libft.h"

# define  IMG_HEIGHT	64
# define  IMG_WIDTH		64

# define KEY_ESC		65307
# define KEY_W			119
# define KEY_A			97
# define KEY_S			115
# define KEY_D			100
# define ARROW_UP		65362
# define ARROW_LEFT		65361
# define ARROW_DOWN		65364
# define ARROW_RIGHT	65363
# define RED_TEXT		53
# define BUFFER_SIZE	2048

typedef struct s_game
{
	int			step_flag;
	int			steps;
	int			map_y;
	int			map_x;
	int			x_axis;
	int			y_axis;
	int			coins;
	char		*player_img_down;
	char		*player_img_up;
	char		*player_img_left;
	char		*player_img_right;
	char		*current_img;
	char		*wall_img;
	char		*exit_img;
	char		*ground_img;
	char		*collectable_img;
	char		**map;
	int			img_height;
	int			img_width;
	int			fakebool;
	

}			t_game;

typedef struct s_vars
{
	void		*mlx;
	void		*mlx_win;
	t_game		*game;
}				t_vars;

int		verificity_ber(char *argv);
void	check_valid_map(t_game *game);
int		ft_deal_key(int key, t_vars *vars);
void	read_map(t_game *game, char *argv);
void	check_objects(t_game *game);
void	check_valid_characters(t_game *game);
void	check_rectangle(t_game *game);
void	check_walls(t_game *game);
void	init_game(t_vars *vars, t_game *game);
int		ft_close(t_vars *vars);
void	free_map(t_vars *vars);
void	ft_error(char *error);
int		steps_count(t_vars *vars);
void	ft_move_right(t_vars *vars);
void	ft_move_up(t_vars *vars);
void	ft_move_down(t_vars *vars);
void	ft_move_left(t_vars *vars);
int		set_image(t_vars *vars);
void	put_img(t_vars *vars);
void	put_img_util(t_vars *vars, int y, int x);
void	set_image_character(t_vars *vars);
void	all_colectionables(t_vars *vars);

#endif
