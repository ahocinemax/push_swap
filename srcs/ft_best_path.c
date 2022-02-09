/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_best_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 23:50:48 by ahocine           #+#    #+#             */
/*   Updated: 2022/01/27 04:48:54 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_stacksize(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

t_list	*ft_bigger_index(t_list *lst)
{
	t_list	*maxi;
	t_list	*curr;

	if (!lst)
		return (NULL);
	maxi = lst;
	curr = lst->next;
	while (curr)
	{
		if (maxi->content < curr->content)
			maxi = curr;
		curr = curr->next;
	}
	return (maxi);
}

t_list	*ft_smaller_index(t_list *lst)
{
	t_list	*mini;
	t_list	*curr;

	if (!lst)
		return (NULL);
	mini = lst;
	curr = lst->next;
	while (curr)
	{
		if (mini->content > curr->content)
			mini = curr;
		curr = curr->next;
	}
	return (mini);
}
