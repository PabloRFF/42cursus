#!/bin/bash

# Crear la carpeta principal
mkdir -p so_long

# Cambiar al directorio principal
cd so_long || exit

# Crear archivos en la raíz
touch Makefile README.md main.c so_long.h

# Crear subdirectorios y sus archivos
mkdir -p game map render events utils assets maps

touch game/game.c game/game.h
touch map/map.c map/map.h map/validator.c
touch render/render.c render/images.c render/render.h
touch events/input.c events/exit.c events/events.h
touch utils/utils.c utils/utils.h
touch assets/.keep  # Archivo vacío opcional para mantener el directorio en git
touch maps/ejemplo.ber
