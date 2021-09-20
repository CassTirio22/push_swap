/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 15:12:15 by ctirions          #+#    #+#             */
/*   Updated: 2021/09/18 18:31:03 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	sort_array(int	*array, int size)
{
	int i;
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

void	find_chunks(t_data *data)
{
	int	*array;
	int	i;

	i = -1;
	data->a = go_start(data, 'a');
	array = (int *)malloc(sizeof(int) * stack_len(data, 'a'));
	if (!array)
		ft_error(1);
	while (++i < stack_len(data, 'a') - 1)
	{
		array[i] = data->a->value;
		data->a = data->a->next;
	}
	array[i] = data->a->value;
	sort_array(array, i);
	data->quarter = array[i / 4];
	data->half = array[i / 2];
	data->third_quarter = array[(i / 4) * 3];
	free(array);
}

int	find_hold_first(t_data *data, int min, int max)
{
	int i;

	i = 0;
	data->a = go_start(data, 'a');
	while (data->a->next)
	{
		if (data->a->value <= max && data->a->value >= min)
		{
			data->hold_first = data->a->value;
			break;
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
			break;
		}
		i++;
		data->a = data->a->previous;
	}
	return (i + 1);
}

int	check_stack_b(t_data *data, int val, int stack_len)
{
	int	i;
	int	j;
	
	if (!data->b || !data->b->next)
		return (0);
	find_smallest(data, 'b');
	find_biggest(data, 'b');
	if (data->smallest > val || val > data->biggest)
		return (ft_ternint(val < data->smallest, -1, 0));
	i = 0;
	data->b = go_start(data, 'b');
	while (data->b->next && val < data->b->value)
	{
		data->b = data->b->next;
		i++;
	}
	j = -1;
	if (i < stack_len / 2)
		while (++j < i)
			rotate(data, 'b');
	else
		while (++j < stack_len - i)
			reverse_rotate(data, 'b');
	return (i);
}

void	move_chunk(t_data *data)
{
	int	i;
	int	j;

	i = find_hold_first(data, INT_MIN, data->quarter);
	j = find_hold_last(data, INT_MIN, data->quarter);
	if (i < j)
		while (i--)
			rotate(data, 'a');
	else
		while (j--)
			reverse_rotate(data, 'a');
	i = check_stack_b(data, data->a->value, stack_len(data, 'b'));
	push_b(data);
	j = -1;
	if (i == -1)
		rotate(data, 'b');
	else if (i && i < (stack_len(data, 'b') - 1) / 2)
		while (++j < i)
			reverse_rotate(data, 'b');
	else if (i)
		while (++j < stack_len(data, 'b') - i)
			rotate(data, 'b');
}
