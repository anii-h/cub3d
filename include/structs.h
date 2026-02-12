/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anihamba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 22:30:57 by anihamba          #+#    #+#             */
/*   Updated: 2026/02/06 13:06:51 by anihamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_mapnode
{
    char                *line;
    struct s_mapnode    *next;
}               t_mapnode;

typedef struct s_player
{
    double pos_x;
    double pos_y;
    double dir_x;
    double dir_y;
    double cam_plane_x;
    double cam_plane_y;
    double move_speed;
    double rot_speed;
}           t_player;

typedef struct s_texture
{
    void    *img;
    char    *img_data;
    int     width;
    int     height;
    int     bpp;
    int     line_length;
    int     endian;
}               t_texture;

typedef struct s_textures
{
    t_texture   north;
    t_texture   south;
    t_texture   east;
    t_texture   west;
    char        *north_path;
    char        *south_path;
    char        *east_path;
    char        *west_path;
}               t_textures;

typedef struct s_color
{
    int     r;
    int     g;
    int     b;
    int     hex;
}            t_color;

typedef struct s_map
{
    t_mapnode   *tmp_head;
    char        start_dir;
    char        **map;
    int         width;
    int         height;
    int         start_pos_x;
    int         start_pos_y;
}               t_map;


typedef struct s_ray
{
    double  ray_dir_x;
    double  ray_dir_y; // precise dir vector
    double  delta_dist_x;
    double  delta_dist_y; // constant distance to the next x/y side
    double  dist_side_x;
    double  dist_side_y; // length of ray from curr pos to next x or y
    double  wall_dist; // perpendicular distance to wall
    int     pos_x;
    int     pos_y; // curr pos
    int     x_dir;
    int     y_dir; // +1/-1 for direction
    int     hit_wall; //flag: 1 - hit the wall, 2 - didn't
    int     wall; // 0 -none, 1 - NS (x), 2 - EW (y)
}               t_ray;

typedef struct s_img
{
    void    *img;
    char    *img_data;
    int     width;
    int     height;
    int     bpp;
    int     line_length;
    int     endian;
}           t_img;

typedef struct s_mlx
{
    void    *mlx;
    void    *win;
    int     win_width;
    int     win_height;
    t_img   render;
}           t_mlx;


typedef struct s_keys
{
    int w;
    int a;
    int s;
    int d;
    int left;
    int right;
    int esc;
}           t_keys;


/*for now w/o pointers, if afterwards 
    we'll need dynamic allocations and flexibility, we can change*/
typedef struct s_game
{
    t_player    player;
    t_map       map;
    t_textures  textures;
    t_color     floor;
    t_color     ceiling;
    t_mlx       mlx;
    t_keys      keys;
}               t_game;

#endif