/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 11:34:23 by junykim           #+#    #+#             */
/*   Updated: 2022/07/19 16:47:26 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

//최종 상태 : 모래시계 , 
void	_move_to_b(int *stack_a, int *stack_b, const int size)
{
	int	*sorted_stack;
	int	chunk;
	int	idx;

	chunk = size / 3;// 이걸 얼마로 잡아야하는거임 ? 
	sorted_stack = _sort_stack_malloc(stack_a, size);
	idx = 0;
	while (idx < size)
	{
		if (sorted_stack[idx] <= stack_a[idx] && stack_a[idx] <= sorted_stack[idx + chunk])
		{
			stack_b[idx] = stack_a[idx];
			printf("%s\n", "pb");
		}
		else
		{
			stack_b[idx] = stack_a[idx];
			printf("%s\n", "pb");
			_reverse_rotate(stack_b, size);
			printf("%s\n", "rrb");
		}
	}
}

// 
void	_move_to_a(int *stack_a, int *stack_b, const int size)
{
	int	*sorted_stack;

	sorted_stack = _sort_stack_malloc(stack_b, size);	

}
