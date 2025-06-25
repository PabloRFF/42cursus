#include "map.h"

int load_map(t_game *game, char *file)
{
    int i;
    int line_length;

    game->height = count_lines(file);
    if (game->height <= 0)
        return (write(2, "Error: Invalid map file\n", 24), 0);
    game->map = malloc(sizeof(char *) * (game->height + 1));
    if (!game->map)
        return (write(2, "Error: Memory allocation failed\n", 33), 0);
    game->width = (int)ft_strlen(game->map[0]);
    i = 0;
    while (i < game->height)
    {
        line_length = ft_strlen(game->map[i]);
        if (game->map[i][line_length - 1] == '\n')
            line_length--;
        if (line_length != game->width)
            return (write(2, "Error: Map is not rectangular\n", 32), free_map(game->map), 0);
    return (1);
}
