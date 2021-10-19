/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 15:12:15 by ctirions          #+#    #+#             */
/*   Updated: 2021/10/20 01:19:30 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_array(int	*array, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = -1;
	while (++i < size - 1)
	{
		j = -1;
		while (++j < size - 1 - i)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
			}
		}
	}
}

void	find_chunks(t_data *data, int div)
{
	int	i;
	int	j;

	i = -1;
	data->a = go_start(data, 'a');
	data->array = (int *)malloc(sizeof(int) * stack_len(data, 'a'));
	if (!data->array)
		ft_error();
	while (++i < stack_len(data, 'a') - 1)
	{
		data->array[i] = data->a->value;
		data->a = data->a->next;
	}
	data->array[i] = data->a->value;
	sort_array(data->array, i + 1);
	j = -1;
	while (++j < div)
		move_chunk(data, data->array[i * j / div],\
		data->array[i * (j + 1) / div], i / div + 1);
	repush_in_order(data, i);
}

void	repush_in_order(t_data *data, int size)
{
	int	i;
	int	j;

	size++;
	while (size--)
	{
		i = find_hold_first(data, data->array[size], data->array[size], 'b');
		j = find_hold_last(data, data->array[size], data->array[size], 'b');
		if (i < j)
			while (i--)
				rotate(data, 'b');
		else
			while (j--)
				reverse_rotate(data, 'b');
		push_a(data);
		data->b = go_start(data, 'b');
	}
}

void	move_chunk(t_data *data, int min, int max, int size)
{
	int	i;
	int	j;
	data->a = go_start(data, 'a');
	while (size-- && data->a)
	{
		i = find_hold_first(data, min, max, 'a');
		j = find_hold_last(data, min, max, 'a');
		if (i < j)
			while (i--)
				rotate(data, 'a');
		else
			while (j--)
				reverse_rotate(data, 'a');
		push_b(data);
	}
}
