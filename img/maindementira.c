/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maindementira.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliobreg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 18:22:29 by aliobreg          #+#    #+#             */
/*   Updated: 2024/08/07 18:54:14 by aliobreg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int main (void)
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*relative_path = "p1.xpm";

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img = mlx_xpm_file_lo_image(mlx, relative_path, 32, 32);
	mlx_loop(mlx);

