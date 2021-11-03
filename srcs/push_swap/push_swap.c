/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 12:54:27 by ctirions          #+#    #+#             */
/*   Updated: 2021/11/03 13:54:15 by ctirions         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_data	data;

	data.a = NULL;
	data.b = NULL;
	if (argc == 1)
		ft_error(0, &data);
	fill_stack_a(argc, argv, &data);
	duplicate_nbr(data.a, argc, &data);
	checker(&data);
	if (stack_len(&data, 'a') <= 5)
		solve_max_5(&data);
	else if (stack_len(&data, 'a') <= 100)
		find_chunks(&data, 5);
	else if (stack_len(&data, 'a') > 100)
		find_chunks(&data, 10);
	free_data(&data);
	exit(1);
	return (0);
}
