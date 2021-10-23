/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 13:28:56 by ctirions          #+#    #+#             */
/*   Updated: 2021/10/23 17:32:29 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_data *data, char name)
{
	t_stack	*stack;
	int		tmp;

	stack = tern_stack(name == 'a', data->a, data->b);
	if (stack_len(data, name) < 2)
		ft_error(2);
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
	if (stack_len(data, 'a') < 2 || stack_len(data, 'b') < 2)
	{
		write(1, "KO\n", 3);
		exit(1);
	}
	swap(data, 'a');
	swap(data, 'b');
}

void	push_a(t_data *data)
{
	int	tmp;

	if (!data->b)
		ft_error(2);
	data->b = go_start(data, 'b');
	tmp = data->b->value;
	del_top_stack(data, 'b');
	add_top_stack(data, 'a', tmp);
}

void	push_b(t_data *data)
{
	int	tmp;

	if (!data->a)
		ft_error(2);
	data->a = go_start(data, 'a');
	tmp = data->a->value;
	del_top_stack(data, 'a');
	add_top_stack(data, 'b', tmp);
}
