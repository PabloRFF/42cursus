#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# include "map/map.h"
# include "game/game.h"
# include "render/render.h"
# include "events/events.h"
# include "utils/utils.h"

typedef struct s_game
{
    void    *mlx;
    void    *win;
    char    **map;
    int     width;
    int     height;
    int     moves;
    int     collectibles;
    int     player_x;
    int     player_y;
}   t_game;

#endif