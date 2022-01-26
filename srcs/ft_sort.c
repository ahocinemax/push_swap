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

static void	ft_five(t_list **a, t_list **b, t_stack **stack)
{
	int	min_val;

	while (ft_lstsize(*a) > 3)
	{
		min_val = ft_smaller(*a);
		if ((*a)->content == min_val)
			ft_push(b, a, stack, 'b');
		else if ((*a)->next->content != min_val && \
			(*a)->next->next->content != min_val)
			ft_reverse(a, stack, 'a');
		else
			ft_rotate(*a, stack, 'a');
	}
	ft_three(a, stack);
	ft_push(a, b, stack, 'a');
	if (ft_lstsize(*b))
		ft_push(a, b, stack, 'a');
}

static void	ft_hundred(t_list **a, t_list **b, t_stack **stack, t_data *data)
{
	int	rot_or_rev;
	int	min_val;
	int	tmp;

	tmp = ft_lstsize(*a);
	while (ft_lstsize(*a) > 3)
	{
		min_val = ft_smaller(*a);
		if ((*a)->content == min_val)
			ft_push(b, a, stack, 'b');
		else if ((*a)->next->content != min_val && \
			(*a)->next->next->content != min_val)
			ft_reverse(a, stack, 'a');
		else
			ft_rotate(*a, stack, 'a');
	}
	ft_three(a, stack);
	ft_push(a, b, stack, 'a');
	while (ft_lstsize(*a) < tmp)
		ft_push(a, b, stack, 'a');
	(void)data;
	return ;
}

static void	ft_fhundred(t_list **a, t_list **b, t_stack **stack, t_data *data)
{
	(void)a;
	(void)b;
	(void)stack;
	(void)data;
	return ;
}

void	ft_sort(t_list **a, t_list **b, t_stack **stack, t_data *data)
{
	int	lst_size;

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
		return (ft_five(a, b, stack));
	else if (lst_size <= 100)
		return (ft_hundred(a, b, stack, data));
	return (ft_fhundred(a, b, stack, data));
}
