/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_swap_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 20:34:09 by junykim           #+#    #+#             */
/*   Updated: 2022/11/06 20:34:29 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"

void	sa_b(t_info *info)
{
	int	tmp;

	if (info->size_a < 2)
		return ;
	tmp = info->top_a->data;
	info->top_a->data = info->top_a->next->data;
	info->top_a->next->data = tmp;
}

void	sb_b(t_info *info)
{
	int	tmp;

	if (info->size_b < 2)
		return ;
	tmp = info->top_b->data;
	info->top_b->data = info->top_b->next->data;
	info->top_b->next->data = tmp;
}

void	ss_b(t_info *info)
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
}
