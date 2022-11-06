/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 17:10:05 by junykim           #+#    #+#             */
/*   Updated: 2022/11/06 19:40:21 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/** type : -1	-> Error */
/** type : +1	-> Nothing  */
void	_error_msg(int type)
{
	if (type < 1)
		write(2, "Error\n", 6);
	exit(1);
}

int	ft_isspace(char c)
{
	if ((9 <= c && c <= 13) || c == ' ')
		return (1);
	else
		return (0);
}

int	get_str_size(int ac, char **av)
{
	int		index;
	int		size;
	int		checker;
	char	**split_str;

	index = 0;
	size = 0;
	while (index < ac)
	{
		checker = 0;
		while (av[index][checker])
		{
			if (!ft_isspace(av[index][checker]))
				break ;
			checker++;
		}
		if (av[index][checker] == '\0')
			_error_msg(1);
		split_str = ft_split(av[index], ' ');
		size += get_size_split_str(split_str);
		_free_str(split_str);
		index++;
	}
	return (size - 1);
}
