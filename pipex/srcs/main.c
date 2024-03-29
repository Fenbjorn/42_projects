/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 14:56:43 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/09/19 15:26:12 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int ac, char **av, char **envp)
{
	t_pipex	data;
	int		exit_code;

	if (ac != 5)
		return (error_msg("Usage: ",
				"./pipex file1 cmd1 cmd2 file2.", "", 1));
	if (!envp || envp[0][0] == '\0')
		ft_error(error_msg("unexpected error.", "", "", 1), &data);
	data = ft_init(ac, av, envp);
	exit_code = ft_pipex(&data);
	return (exit_code);
}
