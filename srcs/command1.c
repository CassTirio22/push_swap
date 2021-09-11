/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 13:28:56 by ctirions          #+#    #+#             */
/*   Updated: 2021/09/11 20:09:18 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_stack **stack)
{
	int	tmp;

	while ((*stack)->previous)
		*stack = (*stack)->previous;
	if ((*stack)->next)
	{
		tmp = (*stack)->value;
		(*stack)->value = (*stack)->next->value;
		(*stack)->next->value = tmp;
	}
}

void	swap_all(t_data *data)
{
	swap(&data->a);
	swap(&data->b);
}

void	push(t_stack **old, t_stack **new)
{
	int	tmp;
	
	if (!*old)
		return ;
	while ((*old)->previous)
		*old = (*old)->previous;
	tmp = (*old)->value;
	*old = (*old)->next;
	free((*old)->previous);
	(*old)->previous = NULL;
	if (*new)
	{
		while ((*new)->previous)
			*new = (*new)->previous;
		(*new)->previous = (t_stack *)malloc(sizeof(t_stack));
		if (!(*new)->previous)
			ft_error(1);
		(*new)->previous->next = *new;
		(*new)->previous->value = tmp;
	}
	else
	{
		*new = (t_stack *)malloc(sizeof(t_stack));
		if (!*new)
			ft_error(1);
		(*new)->value = tmp;
		(*new)->previous = NULL;
		(*new)->next = NULL;
	}
}
