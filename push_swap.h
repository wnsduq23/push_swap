/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 20:27:54 by junykim           #+#    #+#             */
/*   Updated: 2022/11/06 20:32:39 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

# define ERR_PARAM_NUM	"error parameter num"
# define ERR_ALLOC		"Fail Allocation"
# define ERR_NBR		"it isn't nbr"

typedef enum e_value
{
	MIN,
	MAX
}			t_value;

// it's doubly linked list for stack a and b
typedef struct s_numbers
{
	struct s_numbers	*next;
	struct s_numbers	*prev;
	int					data;
}						t_numbers;

//it's information about stack
typedef struct s_info
{
	int					*array;
	int					size_a;
	struct s_numbers	*top_a;
	struct s_numbers	*bottom_a;
	int					size_b;
	struct s_numbers	*top_b;
	struct s_numbers	*bottom_b;
}						t_info;
// ================================
//				init.c
// ================================
t_info		*_init_info(void);
t_numbers	*_init_stack(void);

// ================================
//				sort.c
// ================================
void		_reverse_rotate(int *stack, int size);
void		_rotate(int *stack, int size);
void		_swap(int *stack_a, int *stack_b);

// ================================
//			cmd_swap.c
// ================================
void		sa(t_info *info);
void		sb(t_info *info);
void		ss(t_info *info);

// ================================
//			cmd_swap_bonus.c
// ================================
void		sa_b(t_info *info);
void		sb_b(t_info *info);
void		ss_b(t_info *info);

// pb : push num a to b , pa : push num b to a 
// ================================
//			cmd_push.c
// ================================
void		pa(t_info *info);
void		pb(t_info *info);

// ================================
//			cmd_push_bonus.c
// ================================
void		pa_b(t_info *info);
void		pb_b(t_info *info);

// ================================
//			cmd_reverse.c
// ================================
void		ra(t_info *info);
void		rb(t_info *info);
void		rr(t_info *info);

// ================================
//			cmd_r_bonus.c
// ================================
void		ra_b(t_info *info);
void		rb_b(t_info *info);
void		rr_b(t_info *info);

// ================================
//			cmd_rreverse.c
// ================================
void		rra(t_info *info);
void		rrb(t_info *info);
void		rrr(t_info *info);

// ================================
//			cmd_rr_bonus.c
// ================================
void		rra_b(t_info *info);
void		rrb_b(t_info *info);
void		rrr_b(t_info *info);

// ================================
//				array.c
// ================================
int			get_str_size(int ac, char **av);
int			*_av_to_array(int ac, char **av, int size);
void		_arr_to_stack(t_info *info, int *array, int size);
void		_check_array_sorted(int *array, int size, int idx);

// ================================
//				array_util.c
// ================================
int			get_size_split_str(char **splitted);
void		_free_str(char **array);
int			ft_atoll(const char *str);
void		_str_to_array(char **splitted, int *arr, int *arr_idx);

// ================================
//				sort.c
// ================================
void		_sort_bigger(t_info *info);
void		_sort(t_info *info);
void		_sort_three(t_info *info);

//divide three parts is sort roughly
// ================================
//				sort_util.c
// ================================
void		ft_sort_big_last(t_info *info);
void		_compare_top_pivot(t_info *info, int pivot1, int pivot2);
void		_divide_three_parts(t_info *info);
int			ft_get_bigger(int a, int b, int a_loc, int b_loc);
void		get_min_rotate(t_info *info, int *a, int *b);

// ================================
//				sort_rotate.c
// ================================
int			set_a_location(int num, t_info *info);
void		_rotate_same(t_info *info, int *a, int *b);
void		_rotate_a(t_info *info, int a);
void		_rotate_b(t_info *info, int b);

// get_location is find max or min location in stack 
// ================================
//				sort_rotate.c
// ================================
int			get_stack_min(t_numbers *stack);
int			set_location(t_info *info, t_value v);
int			get_stack_max(t_numbers *stack);
int			set_location_mid(int num, t_info *info);

// ================================
//				util.c
// ================================
int			ft_isspace(char c);
void		_error_msg(int type);

#endif
