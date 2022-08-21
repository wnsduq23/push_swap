/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 20:14:08 by junykim           #+#    #+#             */
/*   Updated: 2022/08/21 15:29:47 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"

void	sa(t_info *info)
{
	int	tmp;

	if (info->size_a < 2)
		return ;
	tmp = info->top_a->data;
	info->top_a->data = info->top_a->next->data;
	info->top_a->next->data = tmp;
	write(1, "sa\n", 3);
}

void	sb(t_info *info)
{
	int	tmp;

	if (info->size_b < 2)
		return ;
	tmp = info->top_b->data;
	info->top_b->data = info->top_b->next->data;
	info->top_b->next->data = tmp;
	write(1, "sb\n", 3);
}

void	ss(t_info *info)
{
	int	tmp;

	if (info->size_a < 2)
		return ;
	if (info->size_b < 2)
		return ;
	tmp = info->top_a->data;
	info->top_a->data = info->top_a->next->data;
	info->top_a->next->data = tmp;
	tmp = info->top_b->data;
	info->top_b->data = info->top_b->next->data;
	info->top_b->next->data = tmp;
	write(1, "ss\n", 3);
}
