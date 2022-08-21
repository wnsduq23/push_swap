/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 17:10:05 by junykim           #+#    #+#             */
/*   Updated: 2022/08/21 16:13:17 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/** type : -1	-> Error */
/** type : 1	-> Success */
/** type : 0	-> Nothing  */
void	_error_msg(int type)
{
	if (type >= 1)
		write(2, "Error\n", 6);
	exit(1);
}

int	ft_isspace(char c)
{
	if ((9 <= c && c <= 13) || c == ' ')
		return (1);
	else
		return (0);
}
