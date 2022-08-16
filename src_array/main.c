/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 11:25:16 by junykim           #+#    #+#             */
/*   Updated: 2022/07/19 16:30:28 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

//input : 2 1 3 6 5 8 -> array : 2 1 3 6 5 8
// 1 "3 2 7" 되야함 split
//  +1 -2 3 되야함
//  INT_MAX + 1 <- error
int	main(int ac, char **av)
{
	int	*stack_a;	
	int	*stack_b;

	if (ac < 1)
		_error_msg(ERR_PARAM_NUM);
	stack_a = malloc(sizeof(int) * (ac - 1));
	if (!stack_a)
		_error_msg(ERR_ALLOC);
	_make_stack(stack_a, ac, av);
	stack_b = malloc(sizeof(int) * (ac - 1));
	if (!stack_b)
		_error_msg(ERR_ALLOC);
	_move_to_b(stack_a, stack_b, ac - 1);
	_move_to_a(stack_a, stack_b, ac - 1);
	
	free(stack_a);
	return (0);
}
