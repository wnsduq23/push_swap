/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 16:41:03 by junykim           #+#    #+#             */
/*   Updated: 2022/07/19 17:13:17 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

void	_reverse_rotate(int *stack, int size)
{
	int	i;
	int	dump;

	i = size - 1;
	dump = stack[0];
	while(0 <= i)
	{
		ft_swap(&stack[i - 1], &stack[i]);
		i--;
	}
	stack[size - 1] = dump;
	for (int i = 0; i < size ; i ++)
		printf("%d ", stack[i]);
	printf("\n");
}

void	_rotate(int *stack, int size)
{
	int	i;
	int	dump;

	dump = stack[size - 1];
	i = 0;
	while (i < size - 1)
	{
		ft_swap(&stack[i], &stack[i + 1]);
		i++;	
	}
	stack[0] = dump; 
	for (int i = 0; i < size ; i ++)
		printf("%d ", stack[i]);
	printf("\n");
}

void	_swap(int *stack_a, int *stack_b)
{
	int	tmp;
	
	tmp = stack_a[0];
	stack_a[0] = stack_b[0];
	stack_b[0] = tmp;
}
