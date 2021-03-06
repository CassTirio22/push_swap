/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 12:52:37 by ctirions          #+#    #+#             */
/*   Updated: 2021/11/03 13:40:49 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"

typedef struct s_stack
{
	struct s_stack	*next;
	struct s_stack	*previous;
	int				value;
}				t_stack;

typedef struct s_data
{
	int		boolean;
	int		hold_first;
	int		hold_last;
	int		quarter;
	int		half;
	int		third_quarter;
	int		smallest;
	int		biggest;
	int		second_biggest;
	int		*array;
	int		check;
	t_stack	*a;
	t_stack	*b;
}				t_data;

/*
**		FIND
*/

void	find_biggest(t_data *data, char name);
void	find_smallest(t_data *data, char name);
void	find_chunks(t_data *data, int div);
int		find_hold_first(t_data *data, int min, int max, char name);
int		find_hold_last(t_data *data, int min, int max, char name);

/*
**		INIT
*/

void	fill_stack_a(int argc, char **argv, t_data *data);
void	duplicate_nbr(t_stack *stack, int argc, t_data *data);
void	sort_array(int	*array, int size);

/*
**		UTILS
*/

t_stack	*go_start(t_data *data, char name);
t_stack	*go_end(t_data *data, char name);
t_stack	*tern_stack(int boolean, t_stack *a, t_stack *b);
t_stack	**tern_stack2(int boolean, t_stack **a, t_stack **b);
void	ft_error(int flag, t_data *data);
void	print_stacks(t_data data);
int		stack_len(t_data *data, char name);
void	free_data(t_data *data);
void	free_stack(t_stack *stack);

/*
**		SOLVER
*/

void	move_chunk(t_data *data, int min, int max, int size);
void	repush_in_order(t_data *data, int size_array);
void	solve_max_5(t_data *data);

/*
**		COMMANDS
*/

void	add_top_stack(t_data *data, char name, int value);
void	del_top_stack(t_data *data, char name);
void	swap(t_data *data, char name);
void	swap_all(t_data *data);
void	push_a(t_data *data);
void	push_b(t_data *data);
void	rotate(t_data *data, char name);
void	rotate_all(t_data *data);
void	reverse_rotate(t_data *data, char name);
void	reverse_rotate_all(t_data *data);

#endif