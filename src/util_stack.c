/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:46:19 by junykim           #+#    #+#             */
/*   Updated: 2022/05/24 19:39:31 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//예외처리 하기
void	swap_stack(t_stack *head)
{
	t_stack	*tmp;

	tmp = head->next;
	head->next = head->next->next;
	head->next->prev = head;
	head->next->next = tmp;
	tmp->prev = head->next;
}

t_stack	*pop_stack(t_stack *head)
{
	t_stack	*ret;

	ret = head->next;
	head->size -= 1;
	del_node_from_stack(ret);
	return (ret);
}

void	push_stack(t_stack *head_a, t_stack *head_b, t_mode mode)
{
	t_stack	*top;

	if (mode == ATOB)
	{
		top = pop_stack(head_a);
		top->prev = head_b->next;
		head_b->prev = top;
		top->prev = head_b;
		(top->next)->prev = top;
	}
	else if (mode == BTOA)
	{
		top = pop_stack(head_b);
		top->prev = head_a->next;
		head_a->prev = top;
		top->prev = head_a;
		(top->next)->prev = top;
	}
}

void	rotate_stack(t_stack *head, t_stack *tail)
{
	t_stack	*top;

	top = pop_stack(head);
	tail->prev->next = top;
	top->next = tail;
	top->prev = tail->prev;
	tail->prev = top;
}

void	reverse_rotate_stack(t_stack *head, t_stack *tail)
{
	t_stack	*bottom;

	bottom = tail->prev;
	del_node_from_stack(bottom);
	head->next->prev = bottom;
	bottom->prev = head;
	bottom->next = head->next;
	head->next = bottom;
}
