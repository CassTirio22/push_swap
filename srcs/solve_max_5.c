/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_max_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 18:20:37 by ctirions          #+#    #+#             */
/*   Updated: 2021/09/12 19:53:55 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	solve_2(t_data *data)
{
	while (data->a->previous)
		data->a = data->a->previous;
	if (data->a->value > data->a->next->value)
		swap(data, 'a');
}

static void	solve_3(t_data *data)
{
	data->a = NULL;
}

static void	solve_4(t_data *data)
{
	data->a = NULL;
}

static void	solve_5(t_data *data)
{
	data->a = NULL;
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