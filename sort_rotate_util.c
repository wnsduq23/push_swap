/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rotate_util.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 12:13:25 by junykim           #+#    #+#             */
/*   Updated: 2022/11/05 20:56:27 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	get_stack_min(t_numbers *stack)
{
	int	ret;

	ret = stack->data;
	while (stack)
	{
		if (ret > stack->data)
			ret = stack->data;
		stack = stack->next;
	}
	return (ret);
}

int	set_location(t_info *info, t_value v)
{
	int			ret;
	int			value;
	int			tmp;
	t_numbers	*stack_a;

	ret = 0;
	stack_a = info->top_a;
	if (v == MIN)
		value = get_stack_min(stack_a);
	else if (v == MAX)
	{
		ret++;
		value = get_stack_max(stack_a);
	}
	while (stack_a)
	{
		tmp = stack_a->data;
		if (tmp == value)
			break ;
		ret++;
		stack_a = stack_a->next;
	}
	if (ret >= (info->size_a + 1) / 2)
		ret = (info->size_a - ret) * -1;
	return (ret);
}

int	get_stack_max(t_numbers *stack)
{
	int	ret;

	ret = stack->data;
	while (stack)
	{
		if (ret < stack->data)
			ret = stack->data;
		stack = stack->next;
	}
	return (ret);
}

int	set_location_mid(int num, t_info *info)
{
	t_numbers	*stack_a;
	int			ret;

	stack_a = info->top_a;
	ret = 1;
	while (stack_a->next)
	{
		if (num > stack_a->data && num < stack_a->next->data)
			break ;
		ret++;
		stack_a = stack_a->next;
	}
	if (ret >= (info->size_a + 1) / 2)
		ret = (info->size_a - ret) * -1;
	return (ret);
}
