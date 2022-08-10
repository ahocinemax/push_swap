/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fhundred.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 02:42:05 by ahocine           #+#    #+#             */
/*   Updated: 2022/02/11 02:42:07 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_chunk_left(t_list *a, int pow)
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

int	ft_rota(t_list *a, int pow)
{
	t_list	*current;
	int		i;
	int		j;

	i = 0;
	j = 1;
	if (!a)
		return (-1);
	current = a;
	while (current && (current->index / 10) * 10 != pow && i <= ft_lstsize(a))
	{
		i++;
		current = current->next;
	}
	current = ft_lstlast(a);
	while (current && (current->index / 10) * 10 != pow && j <= ft_lstsize(a))
	{
		j++;
		current = current->prev;
	}
	if (i < j)
		return (j - i);
	else
		return (-1);
}

void	ft_utils(int i, t_list **a, t_list **b, t_stack **stack)
{
	ft_push(b, a, stack, "pb\n");
	if ((*b)->next && ((*b)->index / 10) * 10 == i)
		ft_rotate(*b, stack, "rb\n");
}

void	ft_push_beta(t_list **a, t_list **b, t_stack **stack)
{
	int	index_max;
	int	pow;
	int	i;

	index_max = (ft_bigger_index((*a))->index / 10) * 10;
	pow = ((index_max / 2) / 10) * 10;
	i = ((index_max / 2) / 10) * 10 - 10;
	if (ft_lstsize(*a) > 10)
	{
		while (*a && pow < index_max)
		{
			while (*a && (ft_chunk_left(*a, pow) || ft_chunk_left(*a, i)))
			{
				if (((*a)->index / 10) * 10 == pow || \
				((*a)->index / 10) * 10 == i)
					ft_utils(i, a, b, stack);
				else if (ft_rota(*a, pow) || ft_rota(*a, i))
					ft_rotate(*a, stack, "ra\n");
				else
					ft_reverse(a, stack, "rra\n");
			}
			pow += 10;
			i -= 10;
		}
	}
}
