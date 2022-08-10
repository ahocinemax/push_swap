/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_five_hundred.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 01:41:55 by ahocine           #+#    #+#             */
/*   Updated: 2022/05/12 01:41:59 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_chunk_left2(t_list *a, int pow)
{
	t_list	*current;
	int		i;

	if ((a->index / 10) * 10 == pow)
		return (1);
	current = a->next;
	i = 0;
	while (i < ft_lstsize(a) - 1)
	{
		if ((current->index / 100) * 100 == pow)
			return (1);
		current = current->next;
		i++;
	}
	return (0);
}

static void	ft_utils2(int i, t_list **a, t_list **b, t_stack **stack)
{
	ft_push(b, a, stack, "pb\n");
	if ((*b)->next && ((*b)->index / 100) * 100 == i)
		ft_rotate(*b, stack, "rb\n");
}

void	ft_five_hundred(t_list **a, t_list **b, t_stack **stack)
{
	int	index_high;
	int	index_low;

	index_high = 200;
	index_low = 100;
	while (*a && ft_lstsize(*a) > 100)
	{
		while (ft_chunk_left2(*a, index_high) || ft_chunk_left2(*a, index_low))
		{
			if (((*a)->index / 100) * 100 == index_high || \
			((*a)->index / 100) * 100 == index_low)
				ft_utils2(index_low, a, b, stack);
			else if (ft_rota(*a, index_high))
				ft_rotate(*a, stack, "ra\n");
			else
				ft_reverse(a, stack, "rra\n");
		}
		if (((*a)->index / 100) * 100 == index_high || \
		((*a)->index / 100) * 100 == index_low)
			ft_utils2(index_low, a, b, stack);
		index_high += 100;
		index_low -= 100;
	}
	int i = 0;
	while (*a && ft_lstsize(*a) > 5 && i >= 0)
	{
		i = ft_smaller_index(*a)->index;
		if ((*a)->index == i)
			ft_push(b, a, stack, "pb\n");
		else if (ft_rev(*a, i))
			ft_reverse(a, stack, "rra\n");
		else
			ft_rotate(*a, stack, "ra\n");
	}
	ft_five(a, b, stack);
	i = (ft_bigger_index(*a)->index / 100) * 100;
	while (((*b)->index / 100) * 100 == i)
		ft_push(a, b, stack, "pa\n");
	printf("\nLIST A\n");
	ft_lstprint_index(*a);
	printf("Nb of elements : %d\n", ft_lstsize(*a));
	printf("\nLIST B\n");
	ft_lstprint_index(*b);
	printf("%d\n", ft_lstsize(*b));
}

void	ft_lstprint_index(t_list *lst)
{
	int	value;

	if (!lst)
		ft_putstr_fd("liste vide", _STD_OUT);
	else
	{
		while (lst)
		{
			value = lst->index;
			ft_putchar_fd('[', _STD_OUT);
			ft_putnbr_fd(value, _STD_OUT);
			ft_putstr_fd("] ", _STD_OUT);
			lst = lst->next;
		}
	}
	ft_putchar_fd('\n', _STD_OUT);
}