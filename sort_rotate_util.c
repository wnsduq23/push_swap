/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rotate_util.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 12:13:25 by junykim           #+#    #+#             */
/*   Updated: 2022/08/21 12:15:22 by junykim          ###   ########.fr       */
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
		{
			ret = stack->data;
		}
		stack = stack->next;
	}
	return (ret);
}

int	set_a_location_min(t_info *info)
{
	int			ret;
	int			index;
	int			tmp;
	t_numbers	*stack_a;

	ret = 0;
	tmp = 0;
	stack_a = info->top_a;
	index = get_stack_min(stack_a);
	while (stack_a)
	{
		tmp = stack_a->data;
		if (tmp == index)
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
		{
			ret = stack->data;
		}
		stack = stack->next;
	}
	return (ret);
}

int	set_a_location_max(t_info *info)
{
	int			ret;
	int			index;
	int			tmp;
	t_numbers	*stack_a;

	ret = 0;
	tmp = 0;
	stack_a = info->top_a;
	index = get_stack_max(stack_a);
	while (stack_a)
	{
		tmp = stack_a->data;
		if (tmp == index)
			break ;
		ret++;
		stack_a = stack_a->next;
	}
	ret++;
	if (ret >= (info->size_a + 1) / 2)
		ret = (info->size_a - ret) * -1;
	return (ret);
}

int	set_a_location_mid(int num, t_info *info)
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
