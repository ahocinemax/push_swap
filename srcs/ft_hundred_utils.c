/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hundred_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:00:17 by ahocine           #+#    #+#             */
/*   Updated: 2022/02/09 18:00:18 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_rev(t_list *a, int val)
{
	t_list	*current;
	int		i;
	int		j;

	i = 0;
	j = 1;
	if (!a)
		return (-1);
	current = a;
	while (current && current->index != val)
	{
		current = current->next;
		i++;
		if (!current)
			break ;
	}
	current = ft_lstlast(a);
	while (current && current->index != val)
	{
		current = current->prev;
		j++;
		if (!current)
			break ;
	}
	return (i > j);
}

static void	ft_push_b(t_list **a, t_list **b, t_stack **stack)
{
	int	index_to_push;

	index_to_push = 0;
	if (ft_lstsize(*a) > 10)
		ft_push_beta(a, b, stack);
	else if (ft_lstsize(*a) > 5 && ft_lstsize(*a) <= 10)
	{
		while (!ft_is_sort(*a) && ft_lstsize(*a) > 5)
		{
			index_to_push = ft_smaller_index(*a)->index;
			if ((*a)->index == index_to_push)
				ft_push(b, a, stack, "pb\n");
			else if (index_to_push && ft_rev(*a, index_to_push))
				ft_reverse(a, stack, "rra\n");
			else
				ft_rotate(*a, stack, "ra\n");
		}
	}
}

void	ft_hundred(t_list **a, t_list **b, t_stack **stack)
{
	int	i;

	if (!*a)
		return ;
	ft_push_b(a, b, stack);
	if (*a && !ft_is_sort(*a))
	{
		if (ft_lstsize(*a) > 3)
			ft_five(a, b, stack);
		else if (ft_lstsize(*a) == 3)
			ft_three(a, stack);
		else if (ft_lstsize(*a) == 2)
			ft_swap(*a, stack, "sa\n");
	}
	while (*b && ft_lstsize(*b) && i >= 0)
	{
		i = ft_bigger_index(*b)->index;
		if ((*b)->index == i)
			ft_push(a, b, stack, "pa\n");
		else if (ft_rev(*b, i))
			ft_reverse(b, stack, "rrb\n");
		else
			ft_rotate(*b, stack, "rb\n");
	}
}
