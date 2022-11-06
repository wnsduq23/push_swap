/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_util_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 20:38:28 by junykim           #+#    #+#             */
/*   Updated: 2022/11/06 20:42:15 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	ft_sort_big_last(t_info *info)
{
	int	min;
	int	min_location;

	min = get_stack_min(info->top_a);
	min_location = set_location(info, MIN);
	while (min_location)
	{
		if (min_location > 0)
		{
			ra_b(info);
			min_location--;
		}
		else
		{
			rra_b(info);
			min_location++;
		}
	}
}

void	_compare_top_pivot(t_info *info, int pivot1, int pivot2)
{
	if (info->top_a->data < pivot1)
	{
		pb_b(info);
		rb_b(info);
	}
	else if (info->top_a->data < pivot2)
		pb_b(info);
	else
		ra_b(info);
}

void	_divide_three_parts(t_info *info)
{
	int	idx;
	int	pivot1;
	int	pivot2;

	idx = info->size_a / 3;
	pivot1 = info->array[idx];
	idx = info->size_a * 2 / 3;
	pivot2 = info->array[idx];
	idx = info->size_a;
	while (idx)
	{
		_compare_top_pivot(info, pivot1, pivot2);
		idx--;
	}
}

int	ft_get_bigger(int a, int b, int a_loc, int b_loc)
{
	if (a < 0)
		a = a * -1;
	if (b < 0)
		b = b * -1;
	if (a_loc < 0)
		a_loc = a_loc * -1;
	if (b_loc < 0)
		b_loc = b_loc * -1;
	if (a + b > a_loc + b_loc)
		return (1);
	else
		return (0);
}

void	get_min_rotate(t_info *info, int *a, int *b)
{
	int			a_location;
	int			b_location;
	int			idx;
	t_numbers	*stack_b;
	int			num;

	idx = 0;
	stack_b = info->top_b;
	while (idx < info->size_b)
	{
		num = stack_b->data;
		a_location = set_a_location(num, info);
		if (idx >= (info->size_b + 1) / 2)
			b_location = (info->size_b - idx) * -1;
		else
			b_location = idx;
		if (idx == 0 || ft_get_bigger(*a, *b, a_location, b_location))
		{
			*a = a_location;
			*b = b_location;
		}
		stack_b = stack_b->next;
		idx++;
	}
}
