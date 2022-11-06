/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 17:24:14 by junykim           #+#    #+#             */
/*   Updated: 2022/08/23 12:39:35 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*_av_to_array(int ac, char **av, int size)
{
	int		ac_idx;
	int		arr_idx;
	int		*array;
	char	**splitted;

	ac_idx = 1;
	arr_idx = 0;
	array = (int *)malloc(sizeof(int) * size);
	if (!array)
		_error_msg(1);
	while (ac_idx < ac)
	{
		splitted = ft_split(av[ac_idx], ' ');
		_str_to_array(splitted, array, &arr_idx);
		_free_str(splitted);
		ac_idx++;
	}
	array[arr_idx] = '\0';
	return (array);
}

void	_arr_to_stack(t_info *info, int *array, int size)
{
	t_numbers	*new;
	int			idx;

	idx = 0;
	while (idx < size)
	{
		new = _init_stack();
		info->size_a += 1;
		info->bottom_a->data = (int)array[idx];
		info->bottom_a->next = new;
		new->prev = info->bottom_a;
		info->bottom_a = new;
		idx++;
	}
	info->bottom_a = info->bottom_a->prev;
	free(new);
}

void	_check_array_sorted(int *array, int size, int idx)
{
	int	j;
	int	checker;
	int	tmp;

	checker = 0;
	while (idx < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				checker++;
			}
			j++;
		}
		if (array[idx] == array[idx + 1])
			_error_msg(1);
		idx++;
	}
	if (checker == 0)
		_error_msg(-1);
}
