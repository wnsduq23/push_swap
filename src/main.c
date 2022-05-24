/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:44:41 by junykim           #+#    #+#             */
/*   Updated: 2022/05/24 17:55:42 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*head_a;
	t_stack	*tail_a;
	t_stack	*head_b;
	t_stack	*tail_b;

	if (ac < 1)
		ft_error(ERR_PARAM_NUM);
	init_head_and_tail(&head_a, &tail_a, ac - 1);
	init_head_and_tail(&head_b, &tail_b, ac - 1);
	sort_array(head_a, av);
	free_head_and_tail(&head_a, &tail_a);
	free_head_and_tail(&head_b, &tail_b);
	return (0);
}
