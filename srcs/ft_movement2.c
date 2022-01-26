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

void	ft_push(t_list **to_there, t_list **from_there, t_stack **stack, char list)
{
	t_list	*tmp;
	t_list	*top;
	t_list	*new;

	if (!*from_there)
		return ;
	top = *from_there;
	new = ft_lstnew(top->content);
	ft_lstadd_front(to_there, new);
	tmp = *from_there;
	top->prev = NULL;
	*from_there = top->next;
	free(tmp);
	if (list = 'a')
		ft_stack("pa", stack);
	else
		ft_stack("pb", stack);
}

void	ft_reverse(t_list **a, t_stack **stack, char list)
{
	
}
