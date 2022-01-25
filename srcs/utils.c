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

void	ft_free_all(char **str, t_list **a, t_list **b, t_stack **s)
{
	free(str);
	ft_lstclear(a, NULL);
	ft_lstclear(b, NULL);
	ft_lstclear(s, NULL);
}

int	ft_error(char **strs, t_list **a, t_list **b, t_stack **stack)
{
	print_err("Error\n");
	ft_free_all(a, b, stack, strs);
	return (-1);
}