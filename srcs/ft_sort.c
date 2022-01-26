/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 00:23:42 by ahocine           #+#    #+#             */
/*   Updated: 2022/01/26 00:23:44 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_tree()
{
	;
}

static void	ft_five()
{
	;
}

static void	ft_hundred()
{
	;
}

static void	ft_fivehundred()
{
	;
}

void	ft_sort(t_list **a, t_list **b, t_stack **stack, t_data *data)
{
	int	lst_size;

	(void)b;
	(void)stack;
	(void)data;
	lst_size = ft_lstsize(*a);
	if (lst_size > 1 && lst_size <= 3)
		return ;
	else if (lst_size > 3 && lst_size <= 5)
		return ;
	else if (lst_size > 5 && lst_size <= 100)
		return ;
	else
		return ;
}
