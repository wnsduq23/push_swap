/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 11:36:37 by junykim           #+#    #+#             */
/*   Updated: 2022/07/19 16:42:38 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

void	_make_stack(int *stack, int ac, char **av)
{ 
	int	i;

	i = 0;
	while (i < ac - 1)
	{
		if (!_isdigit(av[i + 1]))// if isn't nbr, error
			_error_msg(ERR_NBR);
		stack[i] = ft_atoi(av[i + 1]);
		i++;
	}
	/** for(int i =0; i < ac - 1 ; i++) */
	/** { */
	/**     printf("%d", stack[i]); */
	/** } */
}

int	*_sort_stack_malloc(int *stack, int size)
{
	int	*sorted_stack;
	int	flag;
	int	i;
	/** int a = size; */

	sorted_stack = malloc(sizeof(int) * size);
	if (!sorted_stack)
		return (NULL);
	sorted_stack = stack;
	while (1)
	{
		flag = 1;
		i = 0;
		while (i < size - 1)
		{
			if (sorted_stack[i] > sorted_stack[i + 1])
			{
				flag = 0;
				ft_swap(&sorted_stack[i], &sorted_stack[i + 1]);
			}
			i++;
		}
		size--;
		if (flag == 1)
			break ;
	}
	/** for(int j = 0; j < a; j++) */
	/** { */
	/**     printf("%d ", sorted_stack[j]); */
	/** } */
	return (sorted_stack);
}
