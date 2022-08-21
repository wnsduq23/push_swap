/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:45:16 by junykim           #+#    #+#             */
/*   Updated: 2022/08/21 15:08:15 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_info	*_init_info(void)
{
	t_numbers	*node;
	t_info		*new;

	new = NULL;
	new = (t_info *)malloc(sizeof(t_info));
	node = _init_stack();
	new->array = NULL;
	new->size_a = 0;
	new->top_a = node;
	new->bottom_a = node;
	new->size_b = 0;
	return (new);
}

t_numbers	*_init_stack(void)
{
	t_numbers	*new;

	new = NULL;
	new = (t_numbers *)malloc(sizeof(t_numbers));
	new->prev = NULL;
	new->data = 0;
	new->next = NULL;
	return (new);
}
