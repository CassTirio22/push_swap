/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 15:12:15 by ctirions          #+#    #+#             */
/*   Updated: 2021/11/03 13:34:35 by ctirions         ###   ########.fr       */
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
		ft_error(0, data);
	while (++i < stack_len(data, 'a') - 1)
	{
		data->array[i] = data->a->value;
		data->a = data->a->next;
	}
	data->array[i] = data->a->value;
	sort_array(data->array, i + 1);
	j = -1;
	while (++j < div)
		move_chunk(data, data->array[i * j / div], \
		data->array[i * (j + 1) / div], i / div + 1);
	repush_in_order(data, i + 1);
}

static void	repush_in_order2(t_data *data, int *index, int *size, int flag)
{
	data->b = go_start(data, 'b');
	if (data->b->value == data->second_biggest)
	{
		data->boolean = 1;
		push_a(data);
		if (!flag)
			(*index)--;
		(*size)++;
	}
	if (!flag && data->b->value != data->biggest)
		rotate(data, 'b');
	else if (flag && data->b->value != data->biggest)
		reverse_rotate(data, 'b');
	data->b = go_start(data, 'b');
}

void	repush_in_order(t_data *data, int size)
{
	int	i;
	int	j;

	while (size--)
	{
		data->boolean = 0;
		if (size)
			data->second_biggest = data->array[size - 1];
		i = find_hold_first(data, data->array[size], data->array[size], 'b');
		j = find_hold_last(data, data->array[size], data->array[size], 'b');
		data->biggest = data->array[size];
		if (i < j)
			while (i-- > 0)
				repush_in_order2(data, &i, &size, 0);
		else
			while (j--)
				repush_in_order2(data, &j, &size, 1);
		push_a(data);
		if (data->boolean)
			swap(data, 'a');
		if (data->boolean)
			size -= 2;
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
