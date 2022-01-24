/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 18:05:21 by ahocine           #+#    #+#             */
/*   Updated: 2022/01/18 18:05:23 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_check_double(char **str, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (ft_strcmp(str[i], str[j]) == 0)
				return (1);
		}
	}
	return (0);
}

void	ft_swap(int *tab_to_swap)
{
	int	tmp;

	if (!tab_to_swap[2])
		return ;
	tmp = tab_to_swap[0];
	tab_to_swap[0] = tab_to_swap[1];
	tab_to_swap[1] = tmp;
}

void	ft_push(int *tab_a, int *tab_b)
{
	int	tmp;

	tmp = tab_a[0];
	tab_a[0] = tab_b[0];
	tab_b[0] = tmp;
}
