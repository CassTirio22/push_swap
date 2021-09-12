/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   top_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 14:31:11 by ctirions          #+#    #+#             */
/*   Updated: 2021/09/12 15:33:25 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	del_top_stack(t_stack **top)
{
	if (*top)
	{
		while ((*top)->previous)
			*top = (*top)->previous;
		if ((*top)->next == NULL)
		{
			free(*top);
			*top = NULL;
		}
		else
		{
			*top = (*top)->next;
			free((*top)->previous);
			(*top)->previous = NULL;
		}
	}
}

void	add_top_stack(t_stack **top, int value)
{
	t_stack	*tmp;

	if (*top)
	{
		tmp = (t_stack *)malloc(sizeof(t_stack));
		if (!tmp)
			ft_error(1);
		tmp->next = *top;
		tmp->previous = NULL;
		(*top)->previous = tmp;
		tmp->value = value;
		*top = (*top)->previous;
	}
	else
	{
		*top = (t_stack *)malloc(sizeof(t_stack));
		if (!*top)
			ft_error(1);
		(*top)->next = NULL;
		(*top)->previous = NULL;
		(*top)->value = value;
	}
}
