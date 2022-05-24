/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:43:22 by junykim           #+#    #+#             */
/*   Updated: 2022/05/24 18:25:04 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*init_node(void)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->prev = NULL;
	new->size = 0;
	new->elem = 0;
	return (new);
}

void	init_head_and_tail(t_stack **head, t_stack **tail, int size)
{
	*head = init_node();
	*tail = init_node();
	(*head)->next = *tail;
	(*tail)->prev = *head;
	(*head)->size = size;
}
