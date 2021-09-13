/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_biggest_smallest.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 18:31:08 by ctirions          #+#    #+#             */
/*   Updated: 2021/09/13 14:59:30 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	find_biggest(t_data *data, char name)
{
	t_stack *stack;

	data->biggest = INT_MIN;
	stack = tern_stack(name == 'a', data->a, data->b);
	stack = go_end(data, name);
	if (stack)
	{
		while (stack->previous)
		{
			if (stack->value > data->biggest)
				data->biggest = stack->value;
			stack = stack->previous;
		}
		if (stack->value > data->biggest)
			data->biggest = stack->value;
	}
}

void	find_smallest(t_data *data, char name)
{
	t_stack	*stack;

	data->smallest = INT_MAX;
	stack = tern_stack(name == 'a', data->a, data->b);
	stack = go_end(data, name);
	if (stack)
	{
		while (stack->previous)
		{
			if (stack->value < data->smallest)
				data->smallest = stack->value;
			stack = stack->previous;
		}
		if (stack->value < data->smallest)
			data->smallest = stack->value;
	}
}
