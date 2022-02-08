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

void	ft_reverse(t_list **lst, t_list **other, t_stack **stack, char *list)
{
	t_list	*last;
	t_list	*tmp;
	t_list	*new;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	if (other && *other && (*other)->next && !ft_strcmp(list, "rra\n") && \
		(*other)->index > (*other)->index)
	{
		ft_reverse(other, lst, stack, "rrr\n");
		return ;
	}
	tmp = *lst;
	last = ft_lstlast(tmp);
	new = ft_lstnew(last->content);
	new->index = last->index;
	new->keep = last->keep;
	ft_lstadd_front(&tmp, new);
	while (tmp->next->next)
		tmp = tmp->next;
	free(tmp->next);
	tmp->next = NULL;
	*lst = new;
	(*lst)->prev = NULL;
	if (list)
		ft_stack(list, stack);
}

void	ft_reverse_rr(t_list **a, t_list **b, t_stack **stack)
{
	ft_reverse(a, stack, NULL);
	ft_reverse(b, stack, "rrr\n");
}

int	ft_count_suite(t_list *a)
{
	t_list	*current;
	int		nb_elem;
	int		index;
	int		head;

	if (!a)
		return (0);
	head = a->content;
	a->keep = TRUE;
	index = a->index;
	current = a->next;
	nb_elem = 1;
	while (current && current->content != head)
	{
		if (current->index == index + 1)
		{
			current->keep = TRUE;
			nb_elem++;
			index++;
		}
		else
			current->keep = FALSE;
		current = current->next;
	}
	return (nb_elem);
}
