/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:11:36 by ctirions          #+#    #+#             */
/*   Updated: 2021/09/21 15:43:36 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	make_commands(t_data *data)
{
	char	*line;

	line = NULL;
	while (get_next_line(0, &line))
	{
		if (!ft_strncmp(line, "pa", 3))
			push_a(data);
		else if (!ft_strncmp(line, "pb", 3))
			push_b(data);
		else if (!ft_strncmp(line, "rra", 4))
			reverse_rotate(data, 'a');
		else if (!ft_strncmp(line, "rrb", 4))
			reverse_rotate(data, 'b');
		else if (!ft_strncmp(line, "ra", 2))
			rotate(data, 'a');
		else if (!ft_strncmp(line, "rb", 3))
			rotate(data, 'b');
		else if (!ft_strncmp(line, "rr", 3))
			rotate_all(data);
		else if (!ft_strncmp(line, "rrr", 4))
			reverse_rotate_all(data);
		free(line);
		line = NULL;
	}
}

int	main(int argc, char **argv)
{
	t_data data;

	data.a = NULL;
	data.b = NULL;
	if (argc == 1)
		ft_error();
	fill_stack_a(argc, argv, &data);
	duplicate_nbr(data.a, argc);
	make_commands(&data);
	return (0);
}
