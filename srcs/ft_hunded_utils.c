/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hunded_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:00:17 by ahocine           #+#    #+#             */
/*   Updated: 2022/02/09 18:00:18 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_rev(t_list *a, int val)
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
	current = a;
	while (current && current->index != val)
	{
		current = current->prev;
		j++;
		if (!current)
			break ;
	}
	return (i > j);
}

static int	ft_rota(t_list *a, int pow)
{
	t_list	*current;
	int		i;
	int		j;

	i = 0;
	j = 1;
	if (!a)
		return (-1);
	current = a;
	while ((current->index / 10) * 10 != pow)
	{
		i++;
		current = current->next;
		if (!current)
			break ;
	}
	current = a;
	while (current && current->index / 10 != pow)
	{
		j++;
		if (current->prev)
			current = current->prev;
		else
			break ;
	}
	return (i < j);
}

static int	ft_chunk_left(t_list *a, int pow)
{
	t_list	*current;
	int		i;

	if ((a->index / 10) * 10 == pow)
		return (1);
	current = a->next;
	i = 0;
	while (i < ft_lstsize(a) - 1)
	{
		if ((current->index / 10) * 10 == pow)
			return (1);
		current = current->next;
		i++;
	}
	return (0);
}

static void	ft_push_b(t_list **a, t_list **b, t_stack **stack)
{
	int	pow;

	pow = 0;
	if (ft_lstsize(*a) > 10)
	{	while (*a && pow < (ft_bigger_index((*a))->index / 10) * 10)
		{
			while (*a && ft_chunk_left(*a, pow))
			{
				if (((*a)->index / 10) * 10 == pow)
					ft_push(b, a, stack, "pb\n");
				else if (ft_rota(*a, pow))
					ft_rotate(*a, stack, "ra\n");
				else
					ft_reverse(a, stack, "rra\n");
			}
			pow += 10;
		}
	}
	pow = 0;
	if (ft_lstsize(*a) > 5 && ft_lstsize(*a) <= 10)
	{
		while (!ft_is_sort(*a) && ft_lstsize(*a) > 5)
		{
			pow = ft_smaller_index(*a)->index;
			if (pow != - 1 && (*a)->index == pow)
				ft_push(b, a, stack, "pb\n");
			else if (pow && ft_rev(*a, pow))
				ft_reverse(a, stack, "rra\n");
			else
				ft_rotate(*a, stack, "ra\n");
		}
	}
}

void	ft_hundred(t_list **a, t_list **b, t_stack **stack)
{
	int	i;

	ft_push_b(a, b, stack);
	if (ft_lstsize(*a) == 5)
		ft_five(a, b, stack);
	else if (ft_lstsize(*a) > 5)
		ft_hundred(a, b, stack);	
	if (*a && !ft_is_sort(*a))
	{
		if (ft_lstsize(*a) > 3)
			ft_five(a, b, stack);
		else if (ft_lstsize(*a) == 3)
			ft_three(a, stack);
		else if (ft_lstsize(*a) == 2)
			ft_swap(*a, stack, "sa\n");
	}
	i = ft_bigger_index(*b)->index;
	while (i >= 0)
	{
		if ((*b)->index == i)
		{
			ft_push(a, b, stack, "pa\n");
			i--;
		}
		else if (ft_rev(*b, i))
		{
			ft_reverse(b, stack, "rra\n");
		}
		else
		{
			ft_rotate(*b, stack, "ra\n");
		}
	}
}
