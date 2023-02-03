/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 10:55:25 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/02/03 16:27:33 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static int	ft_data_is_dup(char **data, char *line)
{
	if (*data == NULL)
		*data = ft_clean_dup(line);
	else
		return (1);
	return (0);
}

static int	ft_parse_data(t_data *data, char *line)
{
	if (!ft_strncmp(line, "NO ", 3))
		return (ft_data_is_dup(&data->wall.north_path, line));
	else if (!ft_strncmp(line, "SO ", 3))
		return (ft_data_is_dup(&data->wall.south_path, line));
	else if (!ft_strncmp(line, "WE ", 3))
		return (ft_data_is_dup(&data->wall.west_path, line));
	else if (!ft_strncmp(line, "EA ", 3))
		return (ft_data_is_dup(&data->wall.east_path, line));
	else if (!ft_strncmp(line, "F ", 2))
		return (ft_data_is_dup(&data->colors.floor_data, line));
	else if (!ft_strncmp(line, "C ", 2))
		return (ft_data_is_dup(&data->colors.ceiling_data, line));
	return (0);
}

static void	ft_parsing_datas(t_data *data, char *line, int fd)
{
	if (ft_parse_data(data, line))
	{
		close (fd);
		ft_free_all(data);
		ft_error_msg("Duplicate data detected.", line, NULL);
	}
	free(line);
}

void	ft_parsing(t_data *data)
{
	int		fd;
	char	*line;

	fd = open(data->map_path, O_RDONLY);
	if (fd == -1)
		ft_error_msg("Unable to open the map file.", NULL, NULL);
	while (1)
	{
		line = simpler_gnl(fd);
		if (!line)
			break ;
		ft_parsing_datas(data, line, fd);
	}
	ft_check_data(data, line, fd);
	close (fd);
	free(line);
}
