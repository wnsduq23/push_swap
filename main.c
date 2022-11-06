/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:16:27 by junykim           #+#    #+#             */
/*   Updated: 2022/11/05 21:35:45 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

// where is array free ?
int	main(int ac, char **av)
{
	int		arr_size;
	int		*num_array;
	t_info	*info;

	if (ac < 2)
		_error_msg(-1);
	arr_size = 0;
	info = _init_info();
	arr_size = get_str_size(ac, av);
	num_array = _av_to_array(ac, av, arr_size);
	_arr_to_stack(info, num_array, arr_size);
	_check_array_sorted(num_array, arr_size, 0);
	info->array = (int *)num_array;
	_sort(info);
	return (0);
}
