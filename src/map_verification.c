/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verification.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeliz-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 18:17:40 by cfeliz-r          #+#    #+#             */
/*   Updated: 2024/07/17 18:17:43 by cfeliz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Función para duplicar el mapa para la verificación de caminos
char **duplicate_map(t_game_root *root, char *file)
{
    char **map_dup;
    int i;
    int j;
    int k;

    // Reserva de memoria para el mapa duplicado
    map_dup = (char **)malloc(sizeof(char *) * (root->game->map_height + 1));
    if (!map_dup)
        return NULL;
    
    i = 0;
    k = 0;
    // Copia del contenido del archivo `file` al mapa duplicado
    while (i < root->game->map_height)
    {
        map_dup[i] = (char *)malloc(sizeof(char) * (root->game->map_width + 1));
        if (!map_dup[i])
            return NULL;
        j = 0;
        while (j < root->game->map_width)
        {
            map_dup[i][j] = file[k];
            j++;
            k++;
        }
        map_dup[i][j] = '\0';
        k++; // Avanza para saltar el '\n' en `file`
        i++;
    }
    map_dup[i] = NULL;
    return map_dup;
}

// Función recursiva para verificar la validez del camino
int valid_path(t_game_root *root, char **map, int x, int y)
{
    static int e = 0; // Contador de salidas encontradas
    static int c = 0; // Contador de coleccionables encontrados

    // Verificación de los límites del mapa y posiciones inválidas
    if (x < 0 || y < 0 || x >= root->game->map_width || y >= root->game->map_height || map[y][x] == '1' || map[y][x] == 'X')
        return 0;

    // Verificación de la salida
    if (map[y][x] == 'E')
    {
        e++;
        map[y][x] = 'X';
        return 0;
    }

    // Verificación de coleccionables
    if (map[y][x] == 'C')
        c++;

    // Marca la posición actual como visitada
    map[y][x] = 'X';

    // Exploración en todas las direcciones (derecha, izquierda, abajo, arriba)
    valid_path(root, map, x + 1, y);
    valid_path(root, map, x - 1, y);
    valid_path(root, map, x, y + 1);
    valid_path(root, map, x, y - 1);

    // Verificación final para asegurar que se puede llegar a todos los coleccionables y la salida
    if (e == 1 && c == root->game->total_collectibles)
        return 1;

    return 0;
}

// Verificación de caracteres inválidos
int check_invalid_chars(char **map)
{
    int i;
    int j;

    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'C' && map[i][j] != 'E' && map[i][j] != 'P')
                return 0;
            j++;
        }
        i++;
    }
    return 1;
}

// Verificaciones de validez del mapa incluyendo el camino
int map_verifications(t_game_root *root, char *file)
{
    char **map_dup;

    // Duplicado del mapa para las verificaciones
    map_dup = duplicate_map(root, file);
    if (!map_dup)
    {
        root_destroy(root, "Memory allocation failed", 0);
        return 0;
    }

    // Verificación del camino desde la posición inicial del jugador
    if (!valid_path(root, map_dup, root->game->player_position.x, root->game->player_position.y))
    {
        free_elements(map_dup);
        root_destroy(root, "Error: Invalid path!❌", 0);
        return 0;
    }

    // Verificación de caracteres inválidos en el mapa
    if (!check_invalid_chars(map_dup))
    {
        free_elements(map_dup);
        root_destroy(root, "Error: Invalid characters in map!❌", 0);
        return 0;
    }

    free_elements(map_dup);
    return 1;
}
