/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joalmeid <joalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 00:33:33 by joalmeid          #+#    #+#             */
/*   Updated: 2023/02/27 11:17:16 by joalmeid         ###   ########.fr       */
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
# include <stdio.h>
# include "libft/libft.h"

typedef struct s_content {
	int				index;
	int				data;
}			t_content;

int	is_arg_number(char *str);
int	validate_args(char **argv);
t_list	*ft_node_new_content(t_content content);
void	print_lst(t_list **node);
void	create_stack_a(t_list **node, char **argv);

#endif