/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:11:36 by ctirions          #+#    #+#             */
/*   Updated: 2021/09/22 18:27:43 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	checker(t_data *data)
{
	t_stack	*stack;
	int		tmp;

	if (data->b)
		return ;
	stack = data->a;
	tmp = stack->value;
	while (stack->next)
	{
		if (tmp > stack->next->value)
			return ;
		stack = stack->next;
		tmp = stack->value;
	}
	ft_printf("OK\n");
	exit(1);
}

static void	make_commands2(t_data *data, char *line)
{
	if (!ft_strncmp(line, "pa", 3))
		push_a(data);
	else if (!ft_strncmp(line, "pb", 3))
		push_b(data);
	else if (!ft_strncmp(line, "sa", 3))
		swap(data, 'a');
	else if (!ft_strncmp(line, "sb", 3))
		swap(data, 'b');
	else if (!ft_strncmp(line, "ss", 3))
		swap_all(data);
	else if (!ft_strncmp(line, "rra", 4))
		reverse_rotate(data, 'a');
	else if (!ft_strncmp(line, "rrb", 4))
		reverse_rotate(data, 'b');
}

static void	make_commands(t_data *data)
{
	char	*line;

	line = NULL;
	while (get_next_line(0, &line))
	{
		make_commands2(data, line);
		if (!ft_strncmp(line, "ra", 2))
			rotate(data, 'a');
		else if (!ft_strncmp(line, "rb", 3))
			rotate(data, 'b');
		else if (!ft_strncmp(line, "rr", 3))
			rotate_all(data);
		else if (!ft_strncmp(line, "rrr", 4))
			reverse_rotate_all(data);
		else if (!ft_strncmp(line, "\0", 1))
			break ;
		data->a = go_start(data, 'a');
		free(line);
		line = NULL;
		checker(data);
	}
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
	make_commands(&data);
	checker(&data);
	ft_printf("KO\n");
	exit(1);
	return (0);
}
