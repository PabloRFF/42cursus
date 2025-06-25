#ifndef GAME_H
# define GAME_H

# include "../so_long.h"

void    game_init(t_game *game, char *map_path);

#endif

// game/game.c
#include "game.h"

void game_init(t_game *game, char *map_path)
{
    (void)map_path;
    (void)game;
    // Inicializa estructura y llama a funciones de mapa/render
}