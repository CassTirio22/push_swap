/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 12:54:27 by ctirions          #+#    #+#             */
/*   Updated: 2021/09/11 20:16:47 by ctirions         ###   ########.fr       */
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

static void	print_stack(t_stack *stack)
{
	if (!stack)
		return ;
	while (stack->previous)
		stack = stack->previous;
	while (stack->next)
	{
		printf("%d\n", stack->value);
		stack = stack->next;
	}
	printf("%d\n", stack->value);
	printf("-------------\n");
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
	duplicate_nbr(data.a, argc);
	print_stack(data.a);
	push(&data.a, &data.b);
	print_stack(data.b);
	return (0);
}
