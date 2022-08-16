/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 20:27:54 by junykim           #+#    #+#             */
/*   Updated: 2022/07/19 17:11:05 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

# define ERR_PARAM_NUM	"error parameter num"
# define ERR_ALLOC		"Fail Allocation"
# define ERR_NBR		"it isn't nbr"

typedef enum e_bool
{
	FALSE,
	TRUE
}			t_bool;

// ================================
//				init_free.c
// ================================

// ================================
//				sort.c
// ================================
void	_reverse_rotate(int *stack, int size);
void	_rotate(int *stack, int size);
void	_swap(int *stack_a, int *stack_b);

// ================================
//				stack.c
// ================================
void	_make_stack();
int		*_sort_stack_malloc();

// ================================
//				push_swap.c
// ================================
void	_move_to_a(int *stack_a, int *stack_b, int size);
void	_move_to_b(int *stack_a, int *stack_b, int size);


// ================================
//				util.c
// ================================
t_bool	_isdigit(const char *str);
void	_error_msg(char *str);
void	ft_swap(int *a, int *b);

#endif
