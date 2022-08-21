/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 14:25:30 by junykim           #+#    #+#             */
/*   Updated: 2022/08/21 14:41:16 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	get_size_split_str(char **splitted)
{
	int	idx;

	idx = 0;
	while (splitted[idx])
		idx++;
	return (idx);
}

void	_free_str(char **array)
{
	int	idx;

	idx = 0;
	while (array[idx])
	{
		free(array[idx]);
		idx++;
	}
	free(array);
}

int	ft_atoll(const char *str)
{
	long long	result;
	int			np;
	int			chker;

	result = 0;
	np = 1;
	chker = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		np = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (ft_isdigit(*str))
	{
		result = result * 10 + (*str - '0');
		str++;
		chker++;
	}
	result = result * np;
	if (*str != '\0' || chker > 10
		|| result > 2147483647 || result < -2147483648)
		_error_msg(1);
	return ((int)result);
}

void	_str_to_array(char **splitted, int *arr, int *arr_idx)
{
	int	tmp_number;
	int	idx;

	idx = 0;
	while (splitted[idx])
	{
		tmp_number = ft_atoll(splitted[idx]);
		arr[*arr_idx] = tmp_number;
		(*arr_idx)++;
		idx++;
	}
}
