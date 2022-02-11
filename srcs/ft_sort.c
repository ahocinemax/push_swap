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

void	ft_three(t_list **a, t_stack **stack)
{
	char	*pattern;

	if (ft_is_sort(*a))
		return ;
	pattern = ft_pattern(*a);
	if (pattern[0] == 'a')
	{
		ft_swap(*a, stack, "sa\n");
		ft_rotate(*a, stack, "ra\n");
	}
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
		{
			ft_swap(*a, stack, "sa\n");
			ft_reverse(a, stack, "rra\n");
		}
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

void	ft_sort(t_list **a, t_list **b, t_stack **stack, t_data *data)
{
	if (data->size < 2)
		return ;
	else if (data->size == 2)
	{
		if ((*a)->content > (*a)->next->content)
			ft_swap(*a, stack, "sa\n");
		return ;
	}
	else if (data->size == 3)
		return (ft_three(a, stack));
	else if (data->size <= 5)
		return (ft_five(a, b, stack));
	else if (data->size <= 100)
		return (ft_hundred(a, b, stack));
	else
		return (ft_fhundred(a, b, stack));
}
