/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 13:56:37 by ctirions          #+#    #+#             */
/*   Updated: 2021/10/23 17:32:57 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate(t_data *data, char name)
{
	t_stack	*stack;
	t_stack	*tmp;

	stack = tern_stack(name == 'a', data->a, data->b);
	if (stack_len(data, name) < 2)
		ft_error(2);
	while (stack->previous)
		stack = stack->previous;
	tmp = stack;
	stack->next->previous = NULL;
	while (stack->next)
		stack = stack->next;
	tmp->previous = stack;
	stack->next = tmp;
	stack->next->next = NULL;
}

void	rotate_all(t_data *data)
{
	if (stack_len(data, 'a') < 2 || stack_len(data, 'b') < 2)
		ft_error(2);
	rotate(data, 'a');
	rotate(data, 'b');
}

void	reverse_rotate(t_data *data, char name)
{
	t_stack	*stack;
	t_stack	*tmp;

	stack = tern_stack(name == 'a', data->a, data->b);
	if (stack_len(data, name) < 2)
		ft_error(2);
	while (stack->next)
		stack = stack->next;
	tmp = stack;
	stack->previous->next = NULL;
	while (stack->previous)
		stack = stack->previous;
	stack->previous = tmp;
	stack->previous->previous = NULL;
	stack->previous->next = stack;
}

void	reverse_rotate_all(t_data *data)
{
	if (stack_len(data, 'a') < 2 || stack_len(data, 'b') < 2)
		ft_error(2);
	reverse_rotate(data, 'a');
	reverse_rotate(data, 'b');
}
