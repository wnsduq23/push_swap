/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 20:27:54 by junykim           #+#    #+#             */
/*   Updated: 2022/05/24 18:25:54 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

# define ERR_PARAM_NUM "error parameter num"

typedef enum e_mode
{
	ATOB,
	BTOA
}t_mode;

typedef struct s_stack
{
	int				elem;
	int				size;// size of stack
	struct s_stack	*next;
	struct s_stack	*prev;

}					t_stack;

// ================================
//				init_free.c
// ================================
t_stack	*init_node(void);
void	init_head_and_tail(t_stack **head, t_stack **tail, int size);

// ================================
//				free.c
// ================================
void	free_list(t_stack *head);
void	free_head_and_tail(t_stack **head, t_stack **tail);

// ================================
//				util_stack.c
// ================================
t_stack	*pop_stack(t_stack *head);
void	swap_stack(t_stack *head);
void	push_stack(t_stack *head_a, t_stack *head_b, t_mode mode);
void	rotate_stack(t_stack *head, t_stack *tail);
void	reverse_rotate_stack(t_stack *head, t_stack *tail);

// ================================
//				push_swap.c
// ================================
void	sort_array(t_stack *head, char **av);

// ================================
//				util.c
// ================================
void	ft_error(char *s);
void	del_node_from_stack(t_stack *node);

#endif
