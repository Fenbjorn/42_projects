/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 09:25:22 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/09/19 13:57:49 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex_bonus.h"

void	ft_free(char *str, char **strs)
{
	int	i;

	i = 0;
	if (str != NULL)
	{
		free(str);
		str = NULL;
	}
	if (strs != NULL)
	{
		while (strs[i])
		{
			free(strs[i]);
			i++;
		}
		free(strs);
		strs = NULL;
	}
}
