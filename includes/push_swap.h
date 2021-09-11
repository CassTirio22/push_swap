/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 12:52:37 by ctirions          #+#    #+#             */
/*   Updated: 2021/09/11 14:42:56 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"

typedef struct	s_stack
{
	struct s_stack	*next;
	struct s_stack	*previous;
	int				value;
}				t_stack;

typedef struct s_data
{
	t_stack	*a;
	t_stack	*b;
}				t_data;

/*
**
*/

void	fill_stack_a(int argc, char **argv, t_data *data);

/*
**		COMMANDS
*/

void	swap(t_stack *stack);
void	swap_all(t_data *data);
void	push(t_stack *old_stack, t_stack *new_stack);
void	rotate(t_stack *stack);
void	rotate_all(t_data *data);
void	reverse_rotate(t_stack *stack);
void	reverse_rotate_all(t_data *data);

#endif