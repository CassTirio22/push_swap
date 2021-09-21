/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 13:56:37 by ctirions          #+#    #+#             */
/*   Updated: 2021/09/21 14:36:41 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate(t_data *data, char name)
{
	t_stack	*stack;
	t_stack	*tmp;

	stack = tern_stack(name == 'a', data->a, data->b);
	while (stack->previous)
		stack = stack->previous;
	tmp = stack;
	stack->next->previous = NULL;
	while (stack->next)
		stack = stack->next;
	tmp->previous = stack;
	stack->next = tmp;
	stack->next->next = NULL;
	ft_printf("r%c\n", name);
}

void	rotate_all(t_data *data)
{
	rotate(data, 'a');
	rotate(data, 'b');
}

void	reverse_rotate(t_data *data, char name)
{
	t_stack	*stack;
	t_stack	*tmp;

	stack = tern_stack(name == 'a', data->a, data->b);
	while (stack->next)
		stack = stack->next;
	tmp = stack;
	stack->previous->next = NULL;
	while (stack->previous)
		stack = stack->previous;
	stack->previous = tmp;
	stack->previous->previous = NULL;
	stack->previous->next = stack;
	ft_printf("rr%c\n", name);
}

void	reverse_rotate_all(t_data *data)
{
	reverse_rotate(data, 'a');
	reverse_rotate(data, 'b');
}
