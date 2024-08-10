#include "so_long.h"
void put_img_util(t_vars *vars, int y, int x)
{
    mlx_put_image_to_window(vars->mlx, vars->mlx_win,
    vars->game->ground_img, x * 128, y * 128);
    if (vars->game->map_matrix[y][x] == '1')
        mlx_put_image_to_window(vars->mlx, vars->mlx_win,
            vars->game->wall_img, x * 128, y * 128);
    if (vars->game->map_matrix[y][x] == 'C')
        mlx_put_image_to_window(vars->mlx, vars->mlx_win,
            vars->game->collectable_img, x * 128, y * 128);
    if (vars->game->map_matrix[y][x] == 'E')
        mlx_put_image_to_window(vars->mlx, vars->mlx_win,
            vars->game->exit_img, x * 128, y * 128);
}
void put_img(t_vars *vars)
{
    int y;
    int x;

    mlx_clear_window(vars->mlx, vars->mlx_win);
    mlx_put_image_to_window(vars->mlx, vars->mlx_win,
        vars->game->map_x * 128, vars->game->map_y * 128);
    mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->game->player_img, vars->game->map_x * 128, vars->game->map_y * 128);
    //funcion para contar pasos;
    y = -1;
    while (vars->game->map[y++])
    {
        x = -1;
        while (vars->game->map[y][x++])
            put_img_util(vars, y, x);
    }
    
}
int set_image(t_vars *vars)
{
    t_game *game;

    game = vars->game;
    game->player_img= mlx_xpm_file_to_image(vars->mlx, "poner la imagen xpm :)",
			&game->img_width, &game->img_height);
    game->ground_img= mlx_xpm_file_to_image(vars->mlx, "poner la imagen xpm :)",
		&game->img_width, &game->img_height);
    game->wall_img= mlx_xpm_file_to_image(vars->mlx, "poner la imagen xpm :)",
			&game->img_width, &game->img_height);
    game->collectable_img = mlx_xpm_file_to_image(vars->mlx, "poner la imagen xpm :)",
			&game->img_width, &game->img_height);
    game->exit_img= mlx_xpm_file_to_image(vars->mlx, "poner la imagen xpm :)",
			&game->img_width, &game->img_height);
    put_image(vars);
    return(0);
}
