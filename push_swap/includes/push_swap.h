/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 13:21:58 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/07/19 11:26:35 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include <stdlib.h>
#include <unistd.h>
#include "../libft/libft.h"

typedef struct s_stack
{
	int *stack_a;
	int *stack_b;
	int len_a;
	int len_b;
} t_stack;

t_stack *init(int ac);
void error(char *arg);
void is_dup(t_stack *lst);

#endif