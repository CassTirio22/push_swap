/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 14:07:52 by ctirions          #+#    #+#             */
/*   Updated: 2021/09/11 17:44:47 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	add_number(int value, t_stack **a)
{
	if (!*a)
	{
		*a = (t_stack *)malloc(sizeof(t_stack));
		if (!*a)
			ft_error(1);
		(*a)->value = value;
		(*a)->previous = NULL;
		(*a)->next = NULL;
	}
	else
	{
		(*a)->next = (t_stack *)malloc(sizeof(t_stack));
		if (!(*a)->next)
			ft_error(1);
		(*a)->next->value = value;
		(*a)->next->previous = *a;
		(*a)->next->next = NULL;
		(*a) = (*a)->next;
	}
}

void	fill_stack_a(int argc, char **argv, t_data *data)
{
	int	i;
	int	j;
	int	prev_char;

	i = 0;
	while (++i < argc)
	{
		prev_char = 1;
		j = -1;
		while (argv[i][++j])
		{
			if (!prev_char && !ft_isdigit(argv[i][j]))
				ft_error(2);
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != '+' 
			&& argv[i][j] != '-')
				ft_error(2);
			prev_char = 0;
		}
		add_number(ft_atoi(argv[i]), &data->a);
	}
	return ;
}