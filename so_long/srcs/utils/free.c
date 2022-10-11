/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:24:46 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/10/11 11:37:31 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	ft_free(char *str, char **arr)
{
	int	i;

	i = 0;
	if (str != NULL)
	{
		free(str);
		str = NULL;
	}
	if (arr != NULL)
	{
		while (arr[i])
		{
			free(arr[i]);
			i++;
		}
		free(arr);
		arr = NULL;
	}
}

void	ft_free_all(t_data *data)
{
	ft_free(data->map_path, data->map);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
}