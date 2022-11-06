/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 20:50:45 by junykim           #+#    #+#             */
/*   Updated: 2022/11/06 20:51:50 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_info *info)
{
	while (info->top_a->next)
	{
		if (info->top_a->data > info->top_a->next->data)
			return (0);
		info->top_a = info->top_a->next;
	}
	return (1);
}

void	_execute_cmds(t_info *info, char *cmd)
{
	if (!ft_strncmp(cmd, "sa\n", 4))
		sa_b(info);
	else if (!ft_strncmp(cmd, "sb\n", 4))
		sb_b(info);
	else if (!ft_strncmp(cmd, "ss\n", 4))
		ss_b(info);
	else if (!ft_strncmp(cmd, "pa\n", 4))
		pa_b(info);
	else if (!ft_strncmp(cmd, "pb\n", 4))
		pb_b(info);
	else if (!ft_strncmp(cmd, "ra\n", 4))
		ra_b(info);
	else if (!ft_strncmp(cmd, "rb\n", 4))
		rb_b(info);
	else if (!ft_strncmp(cmd, "rr\n", 4))
		rr_b(info);
	else if (!ft_strncmp(cmd, "rra\n", 5))
		rra_b(info);
	else if (!ft_strncmp(cmd, "rrb\n", 5))
		rrb_b(info);
	else if (!ft_strncmp(cmd, "rrr\n", 5))
		rrr_b(info);
	else
		_error_msg(-1);
}

void	do_checker(t_info *info)
{
	char	*cmd;

	while (1)
	{
		cmd = get_next_line(STDIN_FILENO);
		if (!cmd)
			break ;
		_execute_cmds(info, cmd);
		free(cmd);
		cmd = NULL;
	}
	if (is_sorted(info) == 1)
		write(1, "OK\n", 3);
	else if (is_sorted(info) == 0)
		write(1, "KO\n", 3);
}

int	main(int ac, char **av)
{
	t_info		*info;
	int			arr_size;
	int			*num_array;

	if (ac < 2)
		_error_msg(-1);
	info = _init_info();
	arr_size = get_str_size(ac, av);
	num_array = _av_to_array(ac, av, arr_size);
	_arr_to_stack(info, num_array, arr_size);
	info->array = (int *)num_array;
	do_checker(info);
	return (0);
}
