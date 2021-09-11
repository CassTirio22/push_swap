/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 13:56:37 by ctirions          #+#    #+#             */
/*   Updated: 2021/09/11 14:07:38 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate(t_stack *stack)
{
	t_stack *tmp;

	while (stack->previous)
		stack = stack->previous;
	tmp = stack;
	tmp->next = NULL;
	stack->next->previous = NULL;
	while (stack->next)
		stack = stack->next;
	stack->next = tmp;
}

void	rotate_all(t_data *data)
{
	rotate(data->a);
	rotate(data->b);
}

void	reverse_rotate(t_stack *stack)
{
	t_stack *tmp;

	while (stack->next)
		stack = stack->next;
	tmp = stack;
	tmp->previous = NULL;
	stack->previous->next = NULL;
	while (stack->previous)
		stack = stack->previous;
	stack->previous = tmp;
}

void	reverse_rotate_all(t_data *data)
{
	reverse_rotate(data->a);
	reverse_rotate(data->b);
}