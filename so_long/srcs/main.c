/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:53:09 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/06/21 10:27:50 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int main(void)
{
	void 	*mlx;
	void 	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 960, 540, "Hello world");

	mlx_loop(mlx);
	mlx_destroy_window(mlx, mlx_win);
}