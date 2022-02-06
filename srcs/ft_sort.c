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

static void	ft_lstprint_keep(t_list *lst)
{
	int	value;

	if (!lst)
		;//ft_putstr_fd("liste vide", _STD_OUT);
	else
	{
		while (lst)
		{
			value = lst->keep;
			ft_putchar_fd('[', _STD_OUT);
			ft_putnbr_fd(value, _STD_OUT);
			ft_putstr_fd("] ", _STD_OUT);
			lst = lst->next;
		}
	}
	//ft_putchar_fd('\n', _STD_OUT);
}

static void	ft_hundred(t_list **a, t_list **b, t_stack **stack)
{
	(void)stack;
	(void)b;
	t_list	*current;
	int		best;
	int		i;
	int		actual_count;
	int		max_count;

	while (!ft_is_sort(*a))
	{
		current = *a;
		i = 0;
		max_count = 0;
		while (i < ft_lstsize(*a))
		{
			actual_count = ft_count_suite(current);
			if (actual_count > max_count)
			{
				best = current->index;
				max_count = actual_count;
			}
			else if (actual_count == max_count && 
			(current->index < best))
				best = current->index;
			i++;
			current = current->next;
		}
		int	size = ft_lstsize(*a);
		while ((*a)->index != best)
			ft_rotate(*a, stack, 'a');
		ft_count_suite((*a));
		i = 0;
		while (i < size)
		{
			if ((*a)->keep == TRUE)
				ft_rotate(*a, stack, 'a');
			else
				ft_push(b, a, stack, 'b');
			i++;
		}
		current = *b;
		i = 0;
		max_count = 0;
		best = 0;
		while (i < ft_lstsize(*b))
		{
			actual_count = ft_count_suite(current);
			if (actual_count > max_count)
			{
				best = current->index;
				max_count = actual_count;
			}
			else if (actual_count == max_count && 
			(current->index < best))
				best = current->index;
			i++;
			current = current->next;
		}
		size = ft_lstsize(*b);
		while ((*b)->index != best)
			ft_rotate(*b, stack, 'b');
		ft_count_suite((*b));
		i = 0;
		while (i < size)
		{
			if ((*b)->keep == TRUE)
				ft_rotate(*b, stack, 'b');
			else
				ft_push(a, b, stack, 'a');
			i++;
		}
		ft_lstprint_keep(NULL);
		/*ft_putstr_fd("\nLISTE A : \n", 1);
		ft_lstprint(*a);
		ft_lstprint_index(*a);
		ft_lstprint_keep(*a);
		ft_putstr_fd("\nLISTE B : \n", 1);
		ft_lstprint(*b);
		ft_lstprint_index(*b);
		ft_lstprint_keep((*b));*/
	}
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
