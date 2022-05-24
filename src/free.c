/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 18:24:32 by junykim           #+#    #+#             */
/*   Updated: 2022/05/24 18:25:02 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_list(t_stack *head)
{
	t_stack	*dump;

	while (head->next)
	{
		dump = head;
		head = head->next;
		free(dump);
		dump = NULL;
	}
	free(head);
}

void	free_head_and_tail(t_stack **head, t_stack **tail)
{
	free_list(*head);
	free_list(*tail);
	(*head) = NULL;
	(*tail) = NULL;
}
