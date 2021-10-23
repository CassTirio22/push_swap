/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 14:07:52 by ctirions          #+#    #+#             */
/*   Updated: 2021/10/23 17:34:13 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	add_number(int value, t_stack **stack)
{
	if (!*stack)
	{
		*stack = (t_stack *)malloc(sizeof(t_stack));
		if (!*stack)
			ft_error(1);
		(*stack)->value = value;
		(*stack)->previous = NULL;
		(*stack)->next = NULL;
	}
	else
	{
		(*stack)->next = (t_stack *)malloc(sizeof(t_stack));
		if (!(*stack)->next)
			ft_error(1);
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
			ft_error(1);
		while (argv[i][++j])
		{
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != '+' \
			&& argv[i][j] != '-')
				ft_error(1);
		}
		add_number(ft_atoi(argv[i]), &data->a);
	}
	data->a = go_start(data, 'a');
}
