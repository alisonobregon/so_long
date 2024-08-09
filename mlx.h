/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliobreg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:56:43 by aliobreg          #+#    #+#             */
/*   Updated: 2024/07/03 16:04:56 by aliobreg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_H
# define MLX_H

void		*mlx_init();
void		*mlx_new_window(void *mlx_ptr, int size_x, int size_y, 
		char *title);
int		mlx_clear_window(void *mlx_ptr, void *win_ptr);

int		mlx_destroy_window(void *mlx_ptr, void *win_ptr);
int		mlx_get_color_value(void *mlx_ptr, int color);
int		mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y,
	       	int color);
#endif
