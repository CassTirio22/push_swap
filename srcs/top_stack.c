/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   top_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 14:31:11 by ctirions          #+#    #+#             */
/*   Updated: 2021/09/12 19:03:09 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	del_top_stack(t_data *data, char name)
{
	t_stack	*stack;

	if (name == 'a')
		stack = data->a;
	else
		stack = data->b;
	if (stack)
	{
		while (stack->previous)
			stack = stack->previous;
		if (stack->next == NULL)
		{
			free(stack);
			stack = NULL;
		}
		else
		{
			stack = stack->next;
			free(stack->previous);
			stack->previous = NULL;
		}
	}
}

void	add_top_stack(t_data *data, char name, int value)
{
	t_stack	*tmp;
	t_stack	*stack;

	if (name == 'a')
		stack = data->a;
	else
		stack = data->b;
	if (stack)
	{
		tmp = (t_stack *)malloc(sizeof(t_stack));
		if (!tmp)
			ft_error(1);
		tmp->next = stack;
		tmp->previous = NULL;
		stack->previous = tmp;
		tmp->value = value;
		stack = stack->previous;
	}
	else
	{
		stack = (t_stack *)malloc(sizeof(t_stack));
		if (!stack)
			ft_error(1);
		stack->next = NULL;
		stack->previous = NULL;
		stack->value = value;
	}
}
