/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joalmeid <joalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 00:33:33 by joalmeid          #+#    #+#             */
/*   Updated: 2023/03/09 12:08:54 by joalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif
# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_push
{
	int	top_or_botton;
	int	qnt;
	int	size;
	int	init;
	int	end;
}			t_push;

int		is_arg_number(char *str);
int		validate_args(char **argv);
t_list	*ft_node_new_data(int data, int index);
void	create_stack_a(t_list **node, char **argv);
int		find_minor_data(t_list **stack);
char	*ft_strjoin_special(char **s1, char *s2);
char	**remove_space_argv(char **argv);
void	free_trimmed_argv(char **trimmed_argv);
void	free_stacks(t_list **stack_a, t_list **stack_b);
void	put_index_node(t_list **node, int index);
void	swap_next_node(t_list **stack);
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
void	push_node(t_list **stack, t_list **head);
void	pa(t_list **stack_a, t_list **head_b);
void	pb(t_list **stack_b, t_list **head_a);
void	rotate_stack(t_list **stack);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rev_rotate_stack(t_list **stack);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);
int		is_sorted(t_list **stack_a);
int		is_inverted(t_list *stack_a);
void	push_swap(t_list **stack_a, t_list **stack_b);
void	uninvert_stack(t_list **stack_a, t_list **stack_b, int stack_size);
void	sort_for_3(t_list **stack_a);
void	sort_for_4(t_list **stack_a, t_list **stack_b);
void	sort_for_5(t_list **stack_a, t_list **stack_b);
int		find_stack_position(int index, t_list *node);
int		find_minor_position(t_list *node);
t_push	set_push_stategy(t_list *stack, int init, int end, int stack_size);
void	push_range_b(t_list **stack_a, t_list **stack_b, t_push set);
void	optmize_push_b(t_list **stack_a, t_list **stack_b, t_push set);
void	optmize_b(t_list **stack_a, t_list **stack_b, t_push set);
void	push_back_a(t_list **stack_a, t_list **stack_b, t_push set);
void	big_sort(t_list **stack_a, t_list **stack_b, int stack_size);
void	print_action(char *act);

#endif