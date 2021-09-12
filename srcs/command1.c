/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 13:28:56 by ctirions          #+#    #+#             */
/*   Updated: 2021/09/12 19:25:17 by ctirions         ###   ########.fr       */
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

void	push(t_data *data, char name)
{
	t_stack *old;
	t_stack *new;
	int		tmp;

	old = tern_stack(name == 'a', data->b, data->a);
	new = tern_stack(name == 'a', data->a, data->b);
	if (old)
	{
		while (old->previous)
			old = old->previous;
		tmp = old->value;
		add_top_stack(data, name, tmp);
		del_top_stack(data, ft_ternchar(name == 'a', 'b', 'a'));
	}
}
