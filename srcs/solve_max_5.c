/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_max_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 18:20:37 by ctirions          #+#    #+#             */
/*   Updated: 2021/09/13 20:45:10 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	solve_2(t_data *data)
{
	data->a = go_start(data, 'a');
	if (data->a->value > data->a->next->value)
		swap(data, 'a');
}

static void	solve_3(t_data *data)
{
	find_biggest(data, 'a');
	data->a = go_start(data, 'a');
	if (data->a->value == data->biggest)
		rotate(data, 'a');
	else if (data->a->next->value == data->biggest)
		reverse_rotate(data, 'a');
	solve_2(data);
}

static void	solve_4(t_data *data)
{
	int 	i;
	int		tmp;

	i = -1;
	find_smallest(data, 'a');
	data->a = go_start(data, 'a');
	while (data->a->next)
	{
		++i;
		if (data->a->value == data->smallest)
			tmp = i;
		data->a = data->a->next;
	}
	if (data->a->value == data->smallest)
		tmp = i + 1;
	data->a = go_start(data, 'a');
	i = -1;
	if (tmp < 2)
		while (tmp--)
			rotate(data, 'a');
	else
		while (++i < 4 - tmp)
			reverse_rotate(data, 'a');
	push_b(data);
	solve_3(data);
	push_a(data);
}

static void	solve_5(t_data *data)
{
	int i;
	int	tmp;

	i = -1;
	find_smallest(data, 'a');
	data->a = go_start(data, 'a');
	while (data->a->next)
	{
		++i;
		if (data->a->value == data->smallest)
			tmp = i;
		data->a = data->a->next;
	}
	if (data->a->value == data->smallest)
		tmp = i + 1;
	data->a = go_start(data, 'a');
	i = -1;
	if (tmp < 3)
	{
		while (tmp--)
			rotate(data, 'a');
	}
	else
		while (++i < 5 - tmp)
			reverse_rotate(data, 'a');
	push_b(data);
	solve_4(data);
	push_a(data);
}

void	solve_max_5(t_data *data)
{
	if (stack_len(data, 'a') == 2)
		solve_2(data);
	else if (stack_len(data, 'a') == 3)
		solve_3(data);
	else if (stack_len(data, 'a') == 4)
		solve_4(data);
	else
		solve_5(data);
}