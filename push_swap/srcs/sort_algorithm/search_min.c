/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_min.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 10:53:53 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/08/31 13:15:31 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	search_pos_min(t_stack *lst)
{
	int	i;
	int	pos;
	int	tmp;

	i = 0;
	pos = 0;
	tmp = lst->stack_a[i];
	while (i < lst->len_a)
	{
		if (lst->stack_a[i] < tmp)
		{
			tmp = lst->stack_a[i];
			pos = i;
		}
		i++;
	}
	return (pos);
}

void	min_to_first_pos(t_stack *lst)
{
	int	mid;
	int	position;

	mid = lst->len_a / 2;
	position = search_pos_min(lst);
	while (position != 0)
	{
		if (position <= mid)
			rotate_a(lst);
		else
			reverse_rot_a(lst);
		position = search_pos_min(lst);
	}
}
