/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:24:30 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/10/20 11:44:34 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static size_t	len_line(t_data *data)
{
	char	*line;
	size_t	len;
	int		fd;

	len = 0;
	fd = open(data->map_path, O_RDONLY);
	line = simpler_gnl(fd);
	if (line == NULL)
		ft_error_msg("No map detected", NULL, NULL);
	len = ft_strlen(line);
	free(line);
	close(fd);
	return (len);
}

static void	ft_check_char_map(t_data *data, char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != 'C' && line[i] != 'P' && line[i] != 'E'
			&& line[i] != '1' && line[i] != '0' && line[i] != '\n')
			ft_error_msg("Invalid character", line, NULL);
		if (line[i] == 'P')
			data->nb_player++;
		if (line[i] == 'C')
			data->nb_item++;
		if (line[i] == 'E')
			data->nb_exit++;
		i++;
	}
}

void	ft_check_map(t_data *data)
{
	int		fd;
	char	*line;
	size_t	len;

	len = len_line(data);
	fd = open(data->map_path, O_RDONLY);
	line = simpler_gnl(fd);
	while (line)
	{
		if (ft_strlen(line) != len)
			ft_error_msg("Wrong map width", line, NULL);
		ft_check_char_map(data, line);
		free(line);
		line = simpler_gnl(fd);
	}
	ft_error_elm(data);
	close(fd);
}

void	ft_check_wall(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->map_width - 1)
	{
		if (data->map[0][i] != '1'
			|| data->map[data->map_height - 1][i] != '1')
			ft_error_msg("Map not closed", NULL, data->map);
		i++;
	}
	i = 0;
	while (i < data->map_height - 2)
	{
		if (data->map[i][0] != '1' || data->map[i][data->map_width - 2] != '1')
			ft_error_msg("Map not closed", NULL, data->map);
		i++;
	}
}

void	ft_check_if_solvable(t_data *data)
{
	if (solve_map(data) == 0)
		ft_error_msg("Impossible to resolve the game",
			NULL, data->map);
}
