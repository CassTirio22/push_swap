/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_max_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 18:20:37 by ctirions          #+#    #+#             */
/*   Updated: 2021/09/21 14:52:14 by ctirions         ###   ########.fr       */
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
	find_smallest(data, 'a');
	data->a = go_start(data, 'a');
	if (data->a->value == data->smallest)
		;
	else if (data->a->next->value == data->smallest)
		rotate(data, 'a');
	else if (data->a->next->next->value == data->smallest)
	{
		rotate(data, 'a');
		rotate(data, 'a');
	}
	else
		reverse_rotate(data, 'a');
	push_b(data);
	solve_3(data);
	push_a(data);
}

static void	solve_5(t_data *data)
{
	find_smallest(data, 'a');
	data->a = go_start(data, 'a');
	if (data->a->value == data->smallest)
		;
	else if (data->a->next->value == data->smallest)
		rotate(data, 'a');
	else if (data->a->next->next->value == data->smallest)
	{
		rotate(data, 'a');
		rotate(data, 'a');
	}
	else if (data->a->next->next->next->value == data->smallest)
	{
		reverse_rotate(data, 'a');
		reverse_rotate(data, 'a');
	}
	else
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
