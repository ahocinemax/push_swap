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

static void	ft_five(t_list **a, t_list **b, t_stack **stack)
{
	int	val[2];

	while (ft_lstsize(*a) > 3)
	{
		val[MIN] = ft_smaller(*a);
		val[MAX] = ft_bigger(*a);
		if ((*a)->content == val[MIN] || (*a)->content == val[MAX])
			ft_push(b, a, stack, "pb\n");
		else if (((*a)->next->content != val[MIN] && (*a)->next->next->content \
				!= val[MIN]) || ((*a)->next->content != val[MAX] && \
				(*a)->next->next->content != val[MAX]))
			ft_reverse(a, stack, "rra\n");
		else
			ft_rotate(*a, stack, "ra\n");
	}
	ft_three(a, stack);
	while (ft_lstsize(*b))
	{
		ft_push(a, b, stack, "pa\n");
		if ((*a)->content > (*a)->next->content)
			ft_rotate(*a, stack, "ra\n");
	}
}

static void	ft_hundred(t_list **a, t_list **b, t_stack **stack, t_data *data)
{
	ft_move(a, b, stack, data);
	ft_move(b, a, stack, data);
	ft_putstr_fd("\nLISTE A : \n", 1);
	ft_lstprint(*a);
	ft_lstprint_index(*a);
	ft_putstr_fd("\nLISTE B : \n", 1);
	ft_lstprint(*b);
	ft_lstprint_index(*b);
}

static void	ft_fhundred(t_list **a, t_list **b, t_stack **stack, t_data *data)
{
	(void)a;
	(void)b;
	(void)stack;
	(void)data;
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
			ft_swap(*a, stack, "sa\n");
		return ;
	}
	else if (lst_size == 3)
		return (ft_three(a, stack));
	else if (lst_size <= 5)
		return (ft_five(a, b, stack));
	else if (lst_size <= 100)
		return (ft_hundred(a, b, stack, data));
	else
		return (ft_fhundred(a, b, stack, data));
}
