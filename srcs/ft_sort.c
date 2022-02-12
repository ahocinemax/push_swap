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

static void	ft_a(t_list **a, t_stack **stack)
{
	ft_swap(*a, stack, "sa\n");
	ft_rotate(*a, stack, "ra\n");
}

static void	ft_b(t_list **a, t_stack **stack)
{
	ft_swap(*a, stack, "sa\n");
	ft_reverse(a, stack, "rra\n");
}

void	ft_three(t_list **a, t_stack **stack)
{
	char	*pattern;

	if (ft_is_sort(*a))
		return ;
	pattern = ft_pattern(*a);
	if (pattern[0] == 'a')
		ft_a(a, stack);
	else if (pattern[0] == 'b')
	{
		if (pattern[1] == 'a')
			ft_swap(*a, stack, "sa\n");
		else
			ft_reverse(a, stack, "rra\n");
	}
	else
	{
		if (pattern[1] == 'a')
			ft_rotate(*a, stack, "ra\n");
		else
			ft_b(a, stack);
	}
}

void	ft_five(t_list **a, t_list **b, t_stack **stack)
{
	int	size;

	size = ft_lstsize(*a);
	while (ft_lstsize(*a) > 3)
	{
		if ((*a)->index == ft_smaller_index(*a)->index)
			ft_push(b, a, stack, "pb\n");
		else if (ft_rev(*a, ft_smaller_index(*a)->index))
			ft_reverse(a, stack, "rra\n");
		else
			ft_rotate(*a, stack, "ra\n");
	}
	if (!ft_is_sort(*a) && ft_lstsize(*a) == 3)
		ft_three(a, stack);
	else if (!ft_is_sort(*a) && ft_lstsize(*a) == 2)
		ft_swap(*a, stack, "sa\n");
	while (ft_lstsize(*a) < size)
		ft_push(a, b, stack, "pa\n");
}

void	ft_sort(t_list **a, t_list **b, t_stack **stack)
{
	if (*a && ft_lstsize(*a) < 2)
		return ;
	else if (*a && ft_lstsize(*a) == 2)
	{
		if ((*a)->content > (*a)->next->content)
			ft_swap(*a, stack, "sa\n");
		return ;
	}
	else if (*a && ft_lstsize(*a) == 3)
		return (ft_three(a, stack));
	else if (*a && ft_lstsize(*a) <= 5)
		return (ft_five(a, b, stack));
	else if (*a)
		return (ft_hundred(a, b, stack));
}
