/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 12:54:27 by ctirions          #+#    #+#             */
/*   Updated: 2021/09/11 17:44:27 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	print_stack(t_stack *stack)
{
	while (stack->previous)
		stack = stack->previous;
	while (stack->next)
	{
		printf("%d\n", stack->value);
		stack = stack->next;
	}
	printf("%d\n", stack->value);
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

int main(int argc, char **argv)
{
	t_data	data;

	data.a = NULL;
	data.b = NULL;
	if (argc == 1)
		ft_error(0);
	fill_stack_a(argc, argv, &data);
	print_stack(data.a);
	return (0);
}