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
	int	val[2];

	while (ft_lstsize(*a) > 3)
	{
		val[MIN] = ft_smaller(*a);
		val[MAX] = ft_bigger(*a);
		if ((*a)->content == val[MIN] || (*a)->content == val[MAX])
			ft_push(b, a, stack, 'b');
		else if (((*a)->next->content != val[MIN] && (*a)->next->next->content \
				!= val[MIN]) || ((*a)->next->content != val[MAX] && \
				(*a)->next->next->content != val[MAX]))
			ft_reverse(a, stack, 'a');
		else
			ft_rotate(*a, stack, 'a');
	}
	ft_three(a, stack);
	while (ft_lstsize(*b))
	{
		ft_push(a, b, stack, 'a');
		if ((*a)->content > (*a)->next->content)
			ft_rotate(*a, stack, 'a');
	}
}

static void	ft_hundred(t_list **a, t_list **b, t_stack **stack)
{
	(void)a;
	(void)b;
	(void)stack;
	int	i;

	i = 0;
	while (i < ft_lstsize(*a) - 1)
	{
		if ((*a)->index != i && (*a)->index != (*a)->next->index - 1)
			ft_push(b, a, stack, 'b');
		else
			ft_rotate(*a, stack, 'a');
		i++;
	}
	ft_putstr_fd("LISTE A : ", 1);
	ft_lstprint(*a);
	ft_putstr_fd("LISTE B : ", 1);
	ft_lstprint(*b);
}

static void	ft_fhundred(t_list **a, t_list **b, t_stack **stack)
{
	(void)a;
	(void)b;
	(void)stack;
}

void	ft_sort(t_list **a, t_list **b, t_stack **stack)
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
		return (ft_hundred(a, b, stack));
	else
		return (ft_fhundred(a, b, stack));
}
