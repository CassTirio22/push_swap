/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hold_first_last.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 14:33:55 by ctirions          #+#    #+#             */
/*   Updated: 2021/10/20 01:08:31 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_hold_first(t_data *data, int min, int max, char name)
{
	int		i;
	t_stack	*stack;

	stack = tern_stack(name == 'a', data->a, data->b);
	i = 0;
	stack = go_start(data, name);
	while (stack->next)
	{
		if (stack->value <= max && stack->value >= min)
		{
			data->hold_first = stack->value;
			break ;
		}
		i++;
		stack = stack->next;
	}
	return (i);
}

int	find_hold_last(t_data *data, int min, int max, char name)
{
	int	i;
	t_stack	*stack;

	stack = tern_stack(name == 'a', data->a, data->b);
	i = 0;
	stack = go_end(data, name);
	while (stack->previous)
	{
		if (stack->value <= max && stack->value >= min)
		{
			data->hold_last = stack->value;
			break ;
		}
		i++;
		stack = stack->previous;
	}
	return (i + 1);
}
