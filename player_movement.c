#include "so_long.h"

void    ft_move_right(t_vars *vars)
{
    t_game  *game;

    game = vars->game;
    if (game->map[game->map_y][game->map_x + 1] != '1')
    {
        if (game-> map[game->map_y][game->map_x + 1] == 'C')
            game->coins--;
        if (game-> map[game->map_y][game->map_x + 1] == 'E')
        {
            if (game->coins == 0)
            {
                game->step_flag = 1;
                game->steps++;
                ft_close (vars);
            }
            else
                return;
        }
        game->map[game->map_y][game->map_x] = '0';
        game->map[game->map_y][game->map_x + 1] = 'P';
        game->map_x += 1;
        game->steps++;
        game->step_flag = 1;    
    }
}

void    ft_move_up(t_vars *vars)
{
    t_game  *game;

    game = vars->game;
    if (game->map[game->map_y - 1][game->map_x] != '1')
    {
        if (game-> map[game->map_y - 1][game->map_x
        ] == 'C')
            game->coins--;
        if (game-> map[game->map_y - 1][game->map_x] == 'E')
        {
            if (game->coins == 0)
            {
                game->step_flag = 1;
                game->steps++;
                ft_close (vars);
            }
            else
                return;
        }
        game->map[game->map_y][game->map_x] = '0';
        game->map[game->map_y - 1][game->map_x] = 'P';
        game->map_y -= 1;
        game->steps++;
        game->step_flag = 1;    
    }
}

void    ft_move_up(t_vars *vars)
{
    t_game  *game;

    game = vars->game;
    if (game->map[game->map_y + 1][game->map_x] != '1')
    {
        if (game-> map[game->map_y + 1][game->map_x
        ] == 'C')
            game->coins--;
        if (game-> map[game->map_y + 1][game->map_x] == 'E')
        {
            if (game->coins == 0)
            {
                game->step_flag = 1;
                game->steps++;
                ft_close (vars);
            }
            else
                return;
        }
        game->map[game->map_y][game->map_x] = '0';
        game->map[game->map_y + 1][game->map_x] = 'P';
        game->map_y += 1;
        game->steps++;
        game->step_flag = 1;    
    }
}

void    ft_move_left(t_vars *vars)
{
    t_game  *game;

    game = vars->game;
    if (game->map[game->map_y][game->map_x - 1] != '1')
    {
        if (game-> map[game->map_y][game->map_x - 1] == 'C')
            game->coins--;
        if (game-> map[game->map_y][game->map_x - 1] == 'E')
        {
            if (game->coins == 0)
            {
                game->step_flag = 1;
                game->steps++;
                ft_close (vars);
            }
            else
                return;
        }
        game->map[game->map_y][game->map_x] = '0';
        game->map[game->map_y][game->map_x - 1] = 'P';
        game->map_x -= 1;
        game->steps++;
        game->step_flag = 1;    
    }
}
