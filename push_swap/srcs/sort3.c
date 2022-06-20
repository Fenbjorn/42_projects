/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 08:49:10 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/06/20 13:56:45 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_stack *one_move_swap(t_stack *lst)
{
	t_stack *last;
	t_stack *next_elm;

	last = lstlast(lst);
	next_elm = lst->next;
	if (lst->content > next_elm->content && next_elm->next == NULL)
	{
		lst = swap(lst);
		ft_printf("sa");
	}
	else if (lst->content > next_elm->content && lst->content < last->content)
	{
		lst = swap(lst);
		ft_printf("sa");
	}
	return (lst);
}

t_stack *sort3(t_stack *lst)
{
	lst = one_move_swap(lst);
	return (lst);
}