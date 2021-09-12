/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 19:17:51 by ctirions          #+#    #+#             */
/*   Updated: 2021/09/12 19:51:55 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	stack_len(t_data *data, char name)
{
	t_stack	*stack;
	int		size;

	stack = tern_stack(name == 'a', data->a, data->b);
	while (stack->previous)
		stack = stack->previous;
	size = 0;
	while (stack->next)
	{
		size++;
		stack = stack->next;
	}
	if (size)
		size++;
	return (size);
}

t_stack	*tern_stack(int boolean, t_stack *a, t_stack *b)
{
	if (boolean)
		return (a);
	return (b);
}
