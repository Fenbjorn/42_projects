/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 13:52:40 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/09/12 09:33:14 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

void	ft_error_files(char *file1, char *file2)
{
	int	infile;
	int	outfile;
	
	infile = open(file1, O_RDONLY);
	outfile = open(file2, O_CREAT, O_TRUNC);
	if (outfile == -1)
		perror(file2);
	else if (infile == -1)
		perror(file1);
	close(infile);
	close(outfile);
	exit(0);
}
