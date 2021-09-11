/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 13:28:56 by ctirions          #+#    #+#             */
/*   Updated: 2021/09/11 13:48:51 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_stack *stack)
{
	int	tmp;

	while (stack->previous)
		stack = stack->previous;
	if (stack->next)
	{
		tmp = stack->value;
		stack->value = stack->next->value;
		stack->next->value = tmp;
	}
}

void	swap_all(t_data *data)
{
	swap(data->a);
	swap(data->b);
}

void	push(t_stack *old_stack, t_stack *new_stack)
{
	if (!old_stack)
		return ;
	while (old_stack->previous)
		old_stack = old_stack->previous;
	while (new_stack->previous)
		new_stack = new_stack->previous;
	old_stack->next->previous = NULL;
	new_stack->previous = old_stack;
}
