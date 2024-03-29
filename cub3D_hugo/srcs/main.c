/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:16:40 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/01/04 14:52:40 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 2)
	{
		ft_init(&data, av[1]);
		ft_parsing(&data);
		ft_init_player(&data);
		ft_start_window(&data);
	}
	return (0);
}
