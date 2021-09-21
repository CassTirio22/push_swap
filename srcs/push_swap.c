/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 12:54:27 by ctirions          #+#    #+#             */
/*   Updated: 2021/09/21 15:54:43 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static	void	duplicate_nbr(t_stack *stack, int argc)
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
				ft_error();
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

void	ft_error(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_data	data;

	data.a = NULL;
	data.b = NULL;
	if (argc == 1)
		ft_error();
	fill_stack_a(argc, argv, &data);
	duplicate_nbr(data.a, argc);
	if (stack_len(&data, 'a') <= 5)
		solve_max_5(&data);
	else
		find_chunks(&data);
	print_stacks(data);
	return (0);
}
