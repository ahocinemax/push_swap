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

	if (ft_is_sort(*a))
		return ;
	pattern = ft_pattern(*a);
	if (pattern[0] == 'a')
	{
		ft_rotate(*a, stack, "ra\n");
		ft_swap(*a, stack, "sa\n");
		ft_reverse(a, NULL, stack, "rra\n");
	}
	else if (pattern[0] == 'b')
	{
		if (pattern[1] == 'a')
			ft_swap(*a, stack, "sa\n");
		else
			ft_reverse(a, NULL, stack, "rra\n");
	}
	else
	{
		if (pattern[1] == 'a')
			ft_rotate(*a, stack, "ra\n");
		else
		{
			ft_swap(*a, stack, "sa\n");
			ft_reverse(a, NULL, stack, "rra\n");
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
			ft_reverse(a, b, stack, "rra\n");
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

static int	ft_rev(t_list *a, int val)
{
	t_list	*current;
	int		i;
	int		j;

	i = 0;
	j = 0;
	current = a;
	while (current && current->index != val)
	{
		current = current->next;
		i++;
	}
	current = a;
	while (current && current->index != val)
	{
		current = current->prev;
		j++;
	}
	return (i >= j);
}

static int	ft_rota(t_list *a, int pow)
{
	t_list	*current;
	int		i;
	int		j;

	i = 0;
	j = 0;
	current = a;
	while (current && current->index / 10 != pow)
	{
		current = current->next;
		i++;
	}
	current = a;
	while (current && current->index / 10 != pow)
	{
		current = current->prev;
		j++;
	}
	return (i < j);
}

static int	ft_chunk_left(t_list *a, int pow)
{
	t_list	*current;

	current = a;
	while (current)
	{
		if (current->index / 10 == pow)
			return (1);
		current = current->next;
	}
	return (0);
}

static void	ft_push_b(t_list **a, t_list **b, t_stack **stack, t_data *data)
{
	int	pow = 0;

	if (data->size <= 10)
	{
		while (ft_lstsize(*a) > 5)
		{
			if ((*a)->content == ft_bigger(*a))
				ft_push(b, a, stack, "pb\n");
			else if (ft_rev(*a, ft_bigger(*a)))
				ft_reverse(a, b, stack, "rra\n");
			else
				ft_rotate(*a, stack, "ra\n");
		}
		ft_five(a, b, stack);
		while (ft_lstsize(*b))
		{
			ft_push(a, b, stack, "pa\n");
			if ((*a)->content > (*a)->next->content)
				ft_rotate(*a, stack, "ra\n");
		}
	}
	while (pow != (data->size / 10))
	{
		while (ft_chunk_left(*a, pow))
		{
			if ((*a)->index / 10 == pow)
				ft_push(b, a, stack, "pb\n");
			else if (ft_rota(*a, pow))
				ft_rotate(*a, stack, "ra\n");
			else
				ft_reverse(a, b, stack, "rra\n");
		}
		pow++;
	}
}

static void	ft_hundred(t_list **a, t_list **b, t_stack **stack, t_data *data)
{
	int	i;

	ft_push_b(a, b, stack, data);
	i = (data->size / 10) * 10 - 1;
	while (i >= 0)
	{
		if ((*b)->index == i)
		{
			ft_push(a, b, stack, "pa\n");
			i--;
		}
		else if (ft_rev(*b, i))
			ft_reverse(b, a, stack, "rra\n");
		else
			ft_rotate(*b, stack, "ra\n");
	}
	ft_putstr_fd("\nLISTE A : \n", 1);
	ft_lstprint_index(*a);
	ft_putstr_fd("\nLISTE B : \n", 1);
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
		return (ft_hundred(a, b, stack, data));
	else
		return (ft_fhundred(a, b, stack, data));
}
