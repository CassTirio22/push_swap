/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 13:28:56 by ctirions          #+#    #+#             */
/*   Updated: 2021/09/13 18:42:10 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_data *data, char name)
{
	t_stack	*stack;
	int		tmp;

	stack = tern_stack(name == 'a', data->a, data->b);
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
	swap(data, 'a');
	swap(data, 'b');
}

void	push_a(t_data *data)
{
	int		tmp;
	
	if (data->b)
	{
		data->b = go_start(data, 'b');
		tmp = data->b->value;
		del_top_stack(data, 'b');
		add_top_stack(data, 'a', tmp);
	}
	
}

void	push_b(t_data *data)
{
	int		tmp;
	
	if (data->a)
	{
		data->a = go_start(data, 'a');
		tmp = data->a->value;
		del_top_stack(data, 'a');
		add_top_stack(data, 'b', tmp);
	}
}
