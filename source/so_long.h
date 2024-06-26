/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliobreg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:07:58 by aliobreg          #+#    #+#             */
/*   Updated: 2024/06/26 18:42:59 by aliobreg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <fcntl.h>

typedef struct game_list
{
	int	fd;
	int	widht;
	int	height;
	int	player_count;
	int	column_count;
	int	exit_count;
	int	colections_count;
	int	x_axis;
	int	y_axis;
	int	counter;
	
	char	**map;

}	t_complete;

#endif
