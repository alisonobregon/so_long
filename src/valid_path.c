#include "so_long.h"

int path_checker_exit(char **map_copy, int x_axis, int y_axis)
{
    int flag;

    flag = 0;
    if (map_copy[y_axis][x_axis] == 'E')
        return (1);
    else
        map_copy[y_axis][x_axis] == '1';
    if (map_copy[y_axis][x_axis + 1] != '1')
        flag += path_checker_exit(map_copy[y_axis][x_axis + 1]);
    if (map_copy[y_axis][x_axis - 1] != '1')
        flag += path_checker_exit(map_copy[y_axis][x_axis - 1]);
    if (map_copy[y_axis + 1][x_axis] != '1')
        flag += path_checker_exit(map_copy[y_axis + 1][x_axis]);
    if (map_copy[y_axis - 1][x_axis] != '1')
        flag += path_checker_exit(map_copy[y_axis - 1][x_axis]);
    return (flag);
}
void check_path_recursive(t_game *game)
{
    int valid;
    int i;

    i = 0;
    valid = path_checker_exit(game->map_copy, game->y_axis, game->x_axis);
    if (valid == 0)
        ft_error("Error\n No avaliable path\n");
    while(game->map_copy[i])
        free(game->map_copy[i++]);
    free (game->map_copy);
    

}