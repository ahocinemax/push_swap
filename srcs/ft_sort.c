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

static void	ft_three(t_list **a, t_stack **stack)
{
	char	*pattern;

	pattern = ft_pattern(*a);
	if (pattern[0] == 'a')
	{
		ft_swap(*a, stack, 'a');
		ft_rotate(*a, stack, 'a');
	}
	else if (pattern[0] == 'b')
	{
		if (pattern[1] == 'a')
			ft_swap(*a, stack, 'a');
		else
			ft_reverse(a, stack, 'a');
	}
	else
	{
		if (pattern[1] == 'a')
			ft_rotate(*a, stack, 'a');
		else
		{
			ft_swap(*a, stack, 'a');
			ft_reverse(a, stack, 'a');
		}
	}
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
	if (lst_size < 2)
		return ;
	else if (lst_size == 2)
	{
		if ((*a)->content > (*a)->next->content)
			ft_swap(*a, stack, 'a');
		return ;
	}
	else if (lst_size == 3)
		return (ft_three(a, stack));
	else if (lst_size <= 5)
		return (ft_five(a, b, stack, data));
	else if (lst_size <= 100)
		return (ft_hundred(a, b, stack, data));
	return (ft_fivehundred(a, b, stack, data));
}
