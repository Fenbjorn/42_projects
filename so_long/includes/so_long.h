/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:56:07 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/10/16 21:24:35 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SOL_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <X11/Xlib.h>
# include <X11/keysym.h>
# include "../libft/libft.h"
# include "../lib/mlx_linux/mlx.h"

typedef struct	s_image
{
	void	*img;
	char	*path;
	int		height;
	int		length;
}	t_image;

typedef struct	s_player
{
	int		x;
	int		y;
	t_image	img;
}	t_player;

typedef struct	s_wall
{
	t_image	img;
}	t_wall;

typedef struct	s_floor
{
	t_image	img;
}	t_floor;

typedef struct	s_item
{
	t_image	img;
}	t_item;

typedef struct	s_exit
{
	t_image	img;
}	t_exit;

typedef struct	s_data
{
	void		*mlx;
	void		*win;
	char		*map_path;
	char		**map;
	int			map_height;
	int			map_length;
	int			nb_item;
	int			nb_exit;
	int			nb_player;
	t_wall		wall;
	t_item		item;
	t_exit		exit;
	t_floor		floor;
	t_player	player;
}	t_data;

int		ft_exit(t_data *data);
int		solve_map(t_data *data);
int		**filling_solving_tab(t_data *data);
void	ft_graphics(t_data *data);
void	ft_error_elm(t_data *data);
void	ft_check_map(t_data *data);
void	ft_check_wall(t_data *data);
void	ft_map_parsing(t_data *data);
void	ft_free(char *str, char **arr);
void	place_img_in_game(t_data *data);
void	ft_search_player_pos(t_data *data);
void	ft_check_if_solvable(t_data *data);
void	ft_init(t_data *data, char *map_name);
void	ft_error_msg(char *str, char *free_str, char **free_arr);

#endif