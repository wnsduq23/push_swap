/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:33:03 by junykim           #+#    #+#             */
/*   Updated: 2022/07/18 16:24:48 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_error(char *s)
{
	ft_putstr_fd(s, 1);
	exit(1);
}

void	del_node_from_stack(t_stack *node)
{
	(node)->prev->next = (node)->next;
	if ((node)->next)
		(node)->next->prev = (node)->prev;
}
