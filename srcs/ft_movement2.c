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

void	ft_push(t_list **to, t_list **from, t_stack **stack, char list)
{
	t_list	*tmp;
	t_list	*top;
	t_list	*new;

	if (!*from)
		return ;
	top = *from;
	new = ft_lstnew(top->content);
	ft_lstadd_front(to, new);
	tmp = *from;
	top->prev = NULL;
	*from = top->next;
	free(tmp);
	if (list == 'a')
		ft_stack("pa", stack);
	else
		ft_stack("pb", stack);
}

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
		ft_stack("rra", stack);
	else
		ft_stack("rrb", stack);
}

void	ft_reverse_rr(t_list **a, t_list **b, t_stack **stack)
{
	ft_reverse(a, stack, 'a');
	ft_reverse(b, stack, 'b');
}
