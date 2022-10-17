/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_solving.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:15:08 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/10/17 21:27:25 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void check_side(t_maze_solver *maze)
{
	if (maze->solve_mtx[maze->x - 1][maze->y] == 0)
		maze->solve_mtx[maze->x - 1][maze->y] = maze->start + 1;
	if (maze->solve_mtx[maze->x + 1][maze->y] == 0)
		maze->solve_mtx[maze->x + 1][maze->y] = maze->start + 1;
	if (maze->solve_mtx[maze->x][maze->y - 1] == 0)
		maze->solve_mtx[maze->x][maze->y - 1] = maze->start + 1;
	if (maze->solve_mtx[maze->x][maze->y + 1] == 0)
		maze->solve_mtx[maze->x][maze->y + 1] = maze->start + 1;
}

static int check_item(t_maze_solver *maze)
{
	if (maze->solve_mtx[maze->x - 1][maze->y] == -1)
	{
		maze->solve_mtx[maze->x - 1][maze->y] = maze->start + 1;
		maze->count_item++;
	}
	if (maze->solve_mtx[maze->x + 1][maze->y] == -1)
	{
		maze->solve_mtx[maze->x + 1][maze->y] = maze->start + 1;
		maze->count_item++;
	}
	if (maze->solve_mtx[maze->x][maze->y - 1] == -1)
	{
		maze->solve_mtx[maze->x][maze->y - 1] = maze->start + 1;
		maze->count_item++;
	}
	if (maze->solve_mtx[maze->x][maze->y + 1] == -1)
	{
		maze->solve_mtx[maze->x][maze->y + 1] = maze->start + 1;
		maze->count_item++;
	}
	return (maze->count_item);
}

static int check_exit(t_maze_solver *maze, t_data *data)
{
	if (maze->solve_mtx[maze->x - 1][maze->y] == -2
		&& maze->count_item == data->nb_item)
		return (1);
	if (maze->solve_mtx[maze->x + 1][maze->y] == -2
		&& maze->count_item == data->nb_item)
		return (1);
	if (maze->solve_mtx[maze->x][maze->y - 1] == -2
		&& maze->count_item == data->nb_item)
		return (1);
	if (maze->solve_mtx[maze->x][maze->y + 1] == -2
		&& maze->count_item == data->nb_item)
		return (1);
	return (0);
}

static int check_solve(t_maze_solver *maze, t_data *data)
{
	maze->x = 0;
	while (maze->x < data->map_height)
	{
		maze->y = 0;
		while (maze->y < data->map_width)
		{
			if (maze->solve_mtx[maze->x][maze->y] == maze->start)
			{
				check_side(maze);
				maze->count_item = check_item(maze);
				if (check_exit(maze, data) == 1)
					return (1);
			}
			maze->y++;
		}
		maze->x++;
	}
	return (0);
}

int solve_map(t_data *data)
{
	t_maze_solver maze;

	maze.solve_mtx = filling_solving_mtx(data);
	maze.start = 2;
	maze.count_item = 0;
	while (maze.start < (data->map_height * data->map_width))
	{
		if (check_solve(&maze, data) == 1)
		{
			ft_free_mtx(maze.solve_mtx);
			return (1);
		}
		maze.start++;
	}
	for (int X = 0; X < data->map_height; X++)
	{
		for (int Y = 0; Y < data->map_width; Y++)
			ft_printf("%d", maze.solve_mtx[X][Y]);
		ft_printf("\n");
	}
	ft_printf("Nombre d'item dans la map : %d\n", data->nb_item);
	ft_printf("Nombre d'item du compteur : %d\n", maze.count_item);
	ft_free_mtx(maze.solve_mtx);
	return (0);
}