/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 14:45:21 by ctirions          #+#    #+#             */
/*   Updated: 2021/10/26 14:32:49 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_stack(t_stack *stack)
{
	if (!stack)
		return ;
	while (stack->next)
	{
		stack = stack->next;
		free(stack->previous);
	}
	free(stack);
}

void	free_data(t_data *data)
{
	data->a = go_start(data, 'a');
	data->b = go_start(data, 'b');
	free_stack(data->a);
	free_stack(data->b);
	if (data->array)
		free(data->array);
}

void	duplicate_nbr(t_stack *stack, int argc, t_data *data)
{
	t_stack	*tmp;

	while (stack->previous)
		stack = stack->previous;
	while (--argc)
	{
		tmp = stack;
		while (stack->next)
		{
			if (tmp->value == stack->next->value)
				ft_error(0, data);
			stack = stack->next;
		}
		stack = tmp->next;
	}
}

void	print_stacks(t_data data)
{
	if (data.a)
	{
		while (data.a->previous)
			data.a = data.a->previous;
	}
	if (data.b)
	{
		while (data.b->previous)
			data.b = data.b->previous;
	}
	while (data.a || data.b)
	{
		if (data.a && data.b)
			ft_printf("%10d|%d\n", data.a->value, data.b->value);
		else if (data.a)
			ft_printf("%10d|\n", data.a->value);
		else
			ft_printf("          |%d\n", data.b->value);
		if (data.a)
			data.a = data.a->next;
		if (data.b)
			data.b = data.b->next;
	}
}

void	ft_error(int flag, t_data *data)
{
	if (flag)
		flag++;
	ft_putstr_fd("Error\n", STDERR_FILENO);
	free_data(data);
	exit(1);
}
