/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rotate_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 20:40:29 by junykim           #+#    #+#             */
/*   Updated: 2022/11/06 20:40:54 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//max와min의 위치를 계속찾는 거는 비효율 아닌가 ? 
int	set_a_location(int num, t_info *info)
{
	int	ret;

	if (num < get_stack_min(info->top_a))
		ret = set_location(info, MIN);
	else if (num > get_stack_max(info->top_a))
		ret = set_location(info, MAX);
	else
		ret = set_location_mid(num, info);
	return (ret);
}

void	_rotate_same(t_info *info, int *a, int *b)
{
	while (*a && *b && (*a > 0 && *b > 0))
	{
		rr_b(info);
		*a = *a - 1;
		*b = *b - 1;
	}
	while (*a && *b && (*a < 0 && *b < 0))
	{
		rrr_b(info);
		*a = *a + 1;
		*b = *b + 1;
	}
}

void	_rotate_a(t_info *info, int a)
{
	while (a)
	{
		if (a > 0)
		{
			ra_b(info);
			a--;
		}
		else
		{
			rra_b(info);
			a++;
		}
	}
}

void	_rotate_b(t_info *info, int b)
{
	while (b)
	{
		if (b > 0)
		{
			rb_b(info);
			b--;
		}
		else
		{
			rrb_b(info);
			b++;
		}
	}
}
