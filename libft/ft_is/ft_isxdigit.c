/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isxdigit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 12:35:58 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/05/02 12:18:45 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_isxdigit(int c)
{
	return ((c >= 48 && c <= 57) || (c >= 65 && c <= 70)
		|| (c >= 97 && c <= 102));
}
