/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 14:45:21 by ctirions          #+#    #+#             */
/*   Updated: 2021/10/23 17:37:38 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	duplicate_nbr(t_stack *stack, int argc)
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
				ft_error(1);
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

void	ft_error(int flag)
{
	if (flag == 1)
		ft_putstr_fd("Error\n", STDERR_FILENO);
	else if (flag == 2)
		ft_putstr_fd("KO\n", STDERR_FILENO);
	exit(1);
}
