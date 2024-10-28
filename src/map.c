/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliobreg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:35:41 by aliobreg          #+#    #+#             */
/*   Updated: 2024/09/05 17:57:19 by aliobreg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(t_game *game, char *argv)
{
	int		fd;
	char	*mapread;
	char	readed;

	fd = open (argv, O_RDONLY);
	if (fd < 0)
	{
		ft_error("Error\n The map couldn't be read\n");
		return ;
	}
	mapread = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!mapread)
		return ;
	readed = read(fd, mapread, BUFFER_SIZE);
	if (readed == -1)
	{
		ft_error("Error\n The map couldn't be read\n");
		free(mapread);
	}
	game->map = ft_split(mapread, '\n');
	game->map_copy = ft_split(mapread, '\n');
	free(mapread);
	close(fd);
}

void	check_objects(t_game *game)
{
	int	p;
	int	e;
	int	x;
	int	y;

	game->coins = 0;
	y = -1;
	p = 0;
	e = 0;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == 'C')
				game->coins++;
			if (game->map[y][x] == 'E')
				e++;
			if (game->map[y][x] == 'P')
				p++;
		}
	}
	if (game->coins < 1 || e != 1 || p != 1)
		ft_error("Error\n Not valid objects\n");
}

void	check_valid_characters(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == 'P')
			{
				game->x_axis = x;
				game->y_axis = y;
			}
			if (game->map[y][x] != 'P' && game->map[y][x] != 'E' &&
				game->map[y][x] != 'C' && game->map[y][x] != '1'
				&& game->map[y][x] != '0')
				ft_error("Error\n Invalid character\n");
		}
	}
}

void	check_rectangle(t_game *game)
{
	int	y;

	y = 0;
	game->map_x = ft_strlen(game->map[y]);
	y = -1;
	while (game->map[++y])
	{
		if (game->map_x != (int)ft_strlen(game->map[y]))
		{
			ft_error("Error\n Not valid map isn't rectangle\n");
			break ;
		}
	}
	game->map_y = y;
	if (game->map_y >= 32 || game->map_x >= 60)
		ft_error("Error\n Not valid map is very long\n");
}

void	check_walls(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (game->map[0][x] != '1'
				|| game->map[game->map_y - 1][x] != '1')
				ft_error ("Error\n Walls invalid\n");
			else if (game->map[y][0] != '1'
				|| game->map[y][game->map_x - 1] != '1')
				ft_error ("Error\n Walls invalid\n");
		}
	}
}
