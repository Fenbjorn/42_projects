/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 09:24:40 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/09/01 12:21:26 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	len_stack(int ac, char *av)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (ac == 2)
	{
		while (av[i])
		{
			if (('0' <= av[i] && av[i] <= '9')
				&& (av[i + 1] == ' ' || av[i + 1] == '\0'))
				len++;
			i++;
		}
		return (len);
	}
	return (ac - 1);
}

t_stack	*init(int ac, char *av)
{
	t_stack	*lst;

	lst = malloc(sizeof(t_stack));
	lst->len_a = len_stack(ac, av);
	lst->len_b = 0;
	lst->stack_a = ft_calloc(sizeof(int), lst->len_a + 1);
	lst->stack_b = ft_calloc(sizeof(int), lst->len_a + 1);
	lst->tmp_tab = ft_calloc(sizeof(int), lst->len_a);
	lst->index_tab = ft_calloc(sizeof(int), lst->len_a);
	return (lst);
}
