/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 14:07:52 by ctirions          #+#    #+#             */
/*   Updated: 2021/11/03 14:42:42 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	add_number(int value, t_stack **stack, t_data *data)
{
	if (!*stack)
	{
		*stack = (t_stack *)malloc(sizeof(t_stack));
		if (!*stack)
			ft_error(0, data);
		(*stack)->value = value;
		(*stack)->previous = NULL;
		(*stack)->next = NULL;
	}
	else
	{
		(*stack)->next = (t_stack *)malloc(sizeof(t_stack));
		if (!(*stack)->next)
			ft_error(0, data);
		(*stack)->next->value = value;
		(*stack)->next->previous = *stack;
		(*stack)->next->next = NULL;
		(*stack) = (*stack)->next;
	}
}

void	fill_stack_a(int argc, char **argv, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		j = -1;
		if (!argv[i][0])
			ft_error(0, data);
		while (argv[i][++j])
		{
			if (!ft_isdigit(argv[i][0]) && argv[i][0] != '+' \
			&& argv[i][0] != '-')
				ft_error(0, data);
			if (j && !ft_isdigit(argv[i][j]))
				ft_error(0, data);
		}
		add_number(ft_atoi(argv[i]), &data->a, data);
	}
	data->a = go_start(data, 'a');
}
