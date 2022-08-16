/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 11:58:44 by junykim           #+#    #+#             */
/*   Updated: 2022/07/19 16:42:20 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	_error_msg(char *str)
{
	ft_putstr_fd(str, 1);
	exit(1);
}

t_bool	_isdigit(const char *str)
{
	size_t	i;

	i = 0;
	if (str[i]== '+' || str[i] == '-')
		i++;
	while (i < ft_strlen(str))
	{
		if (!ft_isdigit(str[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}


void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
