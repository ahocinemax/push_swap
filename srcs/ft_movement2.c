/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 06:45:30 by ahocine           #+#    #+#             */
/*   Updated: 2022/01/26 06:45:31 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_reverse(t_list **lst, t_stack **stack, char list)
{
	t_list	*last;
	t_list	*tmp;
	t_list	*new;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	tmp = *lst;
	last = ft_lstlast(tmp);
	new = ft_lstnew(last->content);
	ft_lstadd_front(&tmp, new);
	while (tmp->next->next)
		tmp = tmp->next;
	free(tmp->next);
	tmp->next = NULL;
	*lst = new;
	(*lst)->prev = NULL;
	if (list == 'a')
		ft_stack("rra\n", stack);
	else if (list == 'b')
		ft_stack("rrb\n", stack);
	else if (list == 'r')
		ft_stack("rrr\n", stack);
}

void	ft_reverse_rr(t_list **a, t_list **b, t_stack **stack)
{
	ft_reverse(a, stack, ' ');
	ft_reverse(b, stack, 'r');
}

int	ft_nb_lis(t_list *a, t_list *start)
{
	t_list	*tmp;
	int		index;
	int		min;

	index = 1;
	min = a->content;
	tmp = start;
	while (tmp)
	{
		if (min < tmp->content)
		{
			min = tmp->content;
			index++;
		}
		tmp = tmp->next;
	}
	return (index);
}

int	ft_lis(t_list *a)
{
	t_list	*tmp;
	t_list	*start;
	int		*index;
	int		i;
	int		curr_min;
	int		indice;

	index = (int *)ft_calloc(1, sizeof(int) * ft_lstsize(a));
	if (!index)
		return (-1);
	i = 0;
	tmp = a;
	while (tmp->content != ft_smaller(a))
		ft_rotate(tmp, NULL, '\0');
	start = tmp->next;
	while (start)
	{
		index[i++] = ft_nb_lis(tmp, start);
		start = start->next;
	}
	i = 0;
	curr_min = *index;
	indice = 0;
	while (i < ft_lstsize(a))
	{
		if (index[i++] > curr_min)
		{
			curr_min = index[i - 1];
			indice = i - 1;
		}
	}
	return (indice);
}
