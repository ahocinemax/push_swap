/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 06:40:55 by ahocine           #+#    #+#             */
/*   Updated: 2022/01/26 06:40:56 by ahocine          ###   ########.fr       */
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
	new->index = top->index;
	new->keep = top->keep;
	ft_lstadd_front(to, new);
	tmp = *from;
	top->prev = NULL;
	*from = top->next;
	free(tmp);
	if (list == 'a')
		ft_stack("pa\n", stack);
	else
		ft_stack("pb\n", stack);
}

void	ft_swap(t_list *lst, t_stack **stack, char list)
{
	int	tmp;
	int	tmp2;

	tmp = lst->content;
	tmp2 = lst->next->content;
	lst->content = tmp2;
	lst->next->content = tmp;
	tmp = lst->index;
	tmp2 = lst->next->index;
	lst->index = tmp2;
	lst->next->index = tmp;
	tmp = lst->keep;
	tmp2 = lst->next->keep;
	lst->keep = tmp2;
	lst->next->keep = tmp;
	if (list == 'a')
		ft_stack("sa\n", stack);
	else if (list == 'b')
		ft_stack("sb\n", stack);
	else if (list == 's')
		ft_stack("ss\n", stack);
}

void	ft_swap_ss(t_list *a, t_list *b, t_stack **stack)
{
	ft_swap(a, stack, ' ');
	ft_swap(b, stack, 's');
}

void	ft_rotate(t_list *lst, t_stack **stack, char list)
{
	t_list	*tmp;
	int		high;
	int		index;
	int		keep;

	if (!lst || !lst->next)
		return ;
	high = lst->content;
	index = lst->index;
	keep = lst->keep;
	while (lst->next)
	{
		tmp = lst->next;
		lst->content = tmp->content;
		lst->index = tmp->index;
		lst->keep = tmp->keep;
		lst = lst->next;
	}
	lst->content = high;
	lst->index = index;
	lst->keep = keep;
	lst->next = NULL;
	if (list == 'a')
		ft_stack("ra\n", stack);
	else if (list == 'b')
		ft_stack("rb\n", stack);
	else if (list == 'r')
		ft_stack("rr\n", stack);
}

void	ft_rotate_rr(t_list *a, t_list *b, t_stack **stack)
{
	ft_rotate(a, stack, ' ');
	ft_rotate(b, stack, 'r');
}
