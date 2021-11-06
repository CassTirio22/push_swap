/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 14:43:45 by ctirions          #+#    #+#             */
/*   Updated: 2021/11/06 13:52:01 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void	atoi_error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	neg;
	int	res;
	int	res_2;

	neg = 1;
	i = 0;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			neg *= -1;
	if (i && !str[i])
		atoi_error();
	while (str[i] >= '0' && str[i] <= '9')
	{
		res_2 = res;
		res = res * 10 + str[i++] - '0';
		if (res > INT_MAX || res < res_2)
			atoi_error();
	}
	return ((int)(neg * res));
}
