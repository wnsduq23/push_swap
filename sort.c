/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 19:52:32 by junykim           #+#    #+#             */
/*   Updated: 2022/08/21 16:00:26 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	_sort_three(t_info *info)
{
	int	top;
	int	mid;
	int	bot;

	top = info->top_a->data;
	mid = info->top_a->next->data;
	bot = info->top_a->next->next->data;
	if (top > mid && mid > bot && top > bot)
	{
		sa(info);
		rra(info);
	}
	else if (top > mid && bot > mid && top > bot)
		ra(info);
	else if (mid > top && mid > bot && bot > top)
	{
		sa(info);
		ra(info);
	}
	else if (top > mid && bot > mid && bot > top)
		sa(info);
	else if (mid > top && mid > bot && top > bot)
		rra(info);
}

void	_sort_bigger(t_info *info)
{
	int	a;
	int	b;

	_sort_three_division(info);
	while (info->size_a > 3)
		pb(info);
	if (info->size_a == 2)
	{
		if (info->top_a->data > info->top_a->next->data)
			sa(info);
	}
	if (info->size_a == 3)
		_sort_three(info);
	while (info->size_b)
	{
		a = 0;
		b = 0;
		get_min_rotate(info, &a, &b);
		_rotate_same(info, &a, &b);
		_rotate_a(info, a);
		_rotate_b(info, b);
		pa(info);
	}
	ft_sort_big_last(info);
}

void	_sort(t_info *info)
{
	if (info->size_a == 2)
	{
		if (info->top_a->data > info->top_a->next->data)
			sa(info);
	}
	else if (info->size_a == 3)
		_sort_three(info);
	else
		_sort_bigger(info);
}
