/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 10:42:18 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/01/17 14:13:19 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <X11/Xlib.h>
# include <X11/keysym.h>

# include "../libs/libft/libft.h"
# include "../libs/mlx_linux/mlx.h"

/*==============================================================*/
/*                             MACROS                           */
/*==============================================================*/
# define WIN_WIDTH 1920
# define WIN_HEIGHT 994
# define FOV 1

/*==============================================================*/
/*                            STRUCTURES                        */
/*==============================================================*/
typedef struct s_image
{
	void		*img;
	int			height;
	int			width;
}	t_image;

typedef struct s_wall_move
{
	double	x;
	double	y;
	double	xtemp;
	double	ytemp;
}	t_wall_move;

typedef struct s_minimap
{
	int	x;
	int	y;
	int	i;
	int	j;
}	t_minimap;

typedef struct s_wall
{
	char		*north_path;
	char		*south_path;
	char		*west_path;
	char		*east_path;
	t_image		north;
	t_image		south;
	t_image		west;
	t_image		east;
	int			*e;
	int			*s;
	int			*n;
	int			*w;
}	t_wall;

typedef struct s_colors
{
	char		*floor_data;
	char		*ceiling_data;
	int			floor;
	int			ceiling;
}	t_colors;

typedef struct s_error
{
	int			dup_north;
	int			dup_south;
	int			dup_west;
	int			dup_east;
	int			dup_floor;
	int			dup_ceiling;
	int			nb_player;
}	t_error;

typedef struct s_texture
{
	int			height;
	double		x;
	double		y;
	double		angle;
}	t_texture;

typedef struct s_add
{
	long int	a_north;
	long int	a_west;
	long int	a_south;
	long int	a_east;
}	t_add;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	char		*map_path;
	char		**map;
	char		**dup_map;
	int			map_height;
	double		x_p;
	double		y_p;
	double		view;
	int			*minimap;
	int			*screen;
	int			*floor_and_celling;
	int			square;
	int			moose;
	int			x_moose;
	t_wall		wall;
	t_image		image[6];
	t_colors	colors;
	t_error		error;
}	t_data;

/*==============================================================*/
/*                            FONCTIONS                         */
/*==============================================================*/

/*------------------------------init.c--------------------------*/
void		ft_init(t_data *data, char *map_name);

/*------------------------------error.c-------------------------*/
void		ft_error_msg(char *str, char *free_str, char **free_arr);

/*------------------------------free.c--------------------------*/
void		ft_free_all(t_data *data);
void		ft_free_array(char **arr);

/*------------------- ---------textures.c-------------------------*/
void		ft_set_texture(t_data *data);

/*-----------------------------utils.c--------------------------*/
void		ft_check_data(t_data *data);
void		ft_check_caracters_utils(t_data *data, char *line);

/*----------------------------parsing.c-------------------------*/
void		ft_parsing(t_data *data);
char		*ft_dup_path(char *str);

/*-------------------------parsing_utils.c----------------------*/
void		ft_parse_data(t_data *data);
void		ft_check_caracters_map(t_data *data);
void		ft_check_texture_data(t_data *data);

/*----------------------------window.c-------------------------*/
void		ft_start_window(t_data *data);

/*----------------------------put_image.c-------------------------*/
void		ft_put_pixel(t_data *data, int *colorized);

/*----------------------------free_window.c-------------------------*/
void		ft_free(t_data *data);

/*----------------------------input.c-------------------------*/
int			ft_mouse_hook(t_data *data);
int			key_hook(int keycode, t_data *data);

/*----------------------------init_player.c-------------------------*/
void		ft_init_player(t_data *data);

/*----------------------------moove.c-------------------------*/
void	ft_move(t_data *data, int i);

/*----------------------------look.c-------------------------*/
void		ft_look_right(t_data *data);
void		ft_look_left(t_data *data);
void		ft_look_right_2(t_data *data);
void		ft_look_left_2(t_data *data);

/*----------------------------math.c-------------------------*/
int			ft_round(double to_round);
double		ft_clock(double angle);
double		ft_radiant(double angle);

/*----------------------------math_2.c-------------------------*/
int		ft_better_round(double to_round);
double	ft_lmove_y(double x);
double	ft_lmove_x(double angle);

/*----------------------------display.c-------------------------*/
void		ft_to_see(t_data *data);

/*----------------------------raycast.c-------------------------*/
void		ft_raycast(t_data *data, double angle);

/*----------------------------start_image.c-------------------------*/
int			*ft_create_image(t_data *data);
int			*ft_create_image_2(t_data *data);
int			*ft_create_minimap(t_data *data);

/*----------------------------wall.c-------------------------*/
double	ft_wall_x(t_wall_move *wall, t_data *data, int i);
double	ft_wall_y(t_wall_move *wall, t_data *data, int i);

/*--------------------------check_map.c------------------------*/
void		ft_check_map(t_data *data);

/*-----------------------check_map_utils.c---------------------*/
int			ft_check_diagonal(t_data *data, int i, int j);
int			ft_if_high_len(t_data *data, int i, int j);

/*----------------------------window.c-------------------------*/
void		ft_start_window(t_data *data);

/*----------------------------minimap.c-------------------------*/
void		ft_minimap(t_data *data);

/*------------------- ---------colors.c-------------------------*/
void		ft_colors(t_data *data);

/*------------------- ---------texture.c-------------------------*/
int			ft_texture(t_data *data, int j, t_texture *t);

/*--------------------------duplicate_map.c----------------------*/
void		ft_texture_map(t_data *data);

/*-----------------------------corner.c--------------------------*/
void		ft_check_corner(t_data *data);

/*------------------------check_spec_wall.c----------------------*/
void		ft_check_spec_wall(t_data *data);

/*------------------------init_add_dir.c----------------------*/
long int	ft_pixel_w(t_texture *t, int j, t_data *data);
long int	ft_pixel_e(t_texture *t, int j, t_data *data);
long int	ft_pixel_s(t_texture *t, int j, t_data *data);
long int	ft_pixel_n(t_texture *t, int j, t_data *data);

/*------------------------dir.c----------------------*/
int			ft_dir(t_texture *t, t_data *data);
int			ft_dir_2(double angle);
int			ft_dir_3(t_texture *t, t_data *data);

/*------------------------special_wall.c----------------------*/
int			ft_special_wall(t_data *data, t_add *add, t_texture *t);

/*------------------------double_wall.c----------------------*/
int			ft_double_wall1(t_data *data, t_add *add, t_texture *t);
int			ft_double_wall2(t_data *data, t_add *add, t_texture *t);

/*------------------------3_wall.c----------------------*/
int			ft_3_wall(t_data *data, t_add *add, t_texture *t);

/*------------------------4_wall.c----------------------*/
int			ft_4_wall(t_data *data, t_add *add, t_texture *t);

#endif
