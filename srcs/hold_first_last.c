/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hold_first_last.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 14:33:55 by ctirions          #+#    #+#             */
/*   Updated: 2021/09/21 14:35:34 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_hold_first(t_data *data, int min, int max)
{
	int	i;

	i = 0;
	data->a = go_start(data, 'a');
	while (data->a->next)
	{
		if (data->a->value <= max && data->a->value >= min)
		{
			data->hold_first = data->a->value;
			break ;
		}
		i++;
		data->a = data->a->next;
	}
	return (i);
}

int	find_hold_last(t_data *data, int min, int max)
{
	int	i;

	i = 0;
	data->a = go_end(data, 'a');
	while (data->a->previous)
	{
		if (data->a->value <= max && data->a->value >= min)
		{
			data->hold_last = data->a->value;
			break ;
		}
		i++;
		data->a = data->a->previous;
	}
	return (i + 1);
}
