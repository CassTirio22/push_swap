/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 12:54:27 by ctirions          #+#    #+#             */
/*   Updated: 2021/09/14 16:29:08 by ctirions         ###   ########.fr       */
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
				ft_error(2);
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

void	ft_error(int tag)
{
	if (!tag)
		ft_putstr_fd("Please put some numbers in arguments.\n", STDERR_FILENO);
	else if (tag == 1)
		ft_putstr_fd("Malloc error.\n", STDERR_FILENO);
	else if (tag == 2)
		ft_putstr_fd("Wrong arguments.\n", STDERR_FILENO);
	exit(1);
}

void	make_commands(t_data *data)
{
	char	*line;

	line = NULL;
	while (get_next_line(0, &line))
	{
		if (!ft_strncmp(line, "pa", 3))
			push_a(data);
		else if (!ft_strncmp(line, "pb", 3))
			push_b(data);
		else if (!ft_strncmp(line, "rra", 4))
			reverse_rotate(data, 'a');
		else if (!ft_strncmp(line, "rrb", 4))
			reverse_rotate(data, 'b');
		else if (!ft_strncmp(line, "ra", 2))
			rotate(data, 'a');
		else if (!ft_strncmp(line, "rb", 3))
			rotate(data, 'b');
		else if (!ft_strncmp(line, "rr", 3))
			rotate_all(data);
		else if (!ft_strncmp(line, "rrr", 4))
			reverse_rotate_all(data);
		//ft_printf("\033[H\033[2J");
		print_stacks(*data);
		free(line);
		line = NULL;
	}
}

int main(int argc, char **argv)
{
	t_data	data;

	ft_printf("\033[H\033[2J");
	data.a = NULL;
	data.b = NULL;
	if (argc == 1)
		ft_error(0);
	fill_stack_a(argc, argv, &data);
	duplicate_nbr(data.a, argc);
	find_chunks(&data);
//	solve_max_5(&data);
//	make_commands(&data);
//	print_stacks(data);
	return (0);
}
